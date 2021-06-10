import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

from datetime import datetime

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    trade = db.execute("SELECT symbol, name, SUM(shares) FROM trade WHERE users_id=:id GROUP BY symbol", id=session["user_id"])
    result = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
    cash = result[0]['cash']

    # total count
    gtotal = cash

    for symbol in trade:
        price = lookup(symbol['symbol'])['price']
        total = symbol['SUM(shares)'] * price
        symbol.update({'price': price, 'total': total})
        gtotal += total

    return render_template("portfolio.html", trade=trade, cash=cash, gtotal=gtotal)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("Must provide symbol")

        if not request.form.get("shares"):
            return apology("Must provide quantity")

        if not request.form.get("shares").isdigit():
            return apology("Must provide valid quantity")

        if int(request.form.get("shares")) <= 0:
            return apology("Must provide valid quantity")

        # Lookup symbol in IEX
        stock = lookup(request.form.get("symbol"))

        # wrong symbol
        if stock == None:
            return apology("Wrong symbol!")

        user_id = session["user_id"]
        ssymbol = stock['symbol']
        sname = stock['name']
        sprice = stock['price']
        share = int(request.form.get("shares"))
        cost = share * sprice
        result = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        cash = result[0]['cash']
        newcash = cash - cost
        if cost > cash:
            return apology("You don't have enough money for transaction!")

        # buy
        timestamp = date = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        db.execute("INSERT INTO trade (users_id, symbol, name, shares, price, timestp, total ) VALUES(?, ?, ?, ?, ?, ?, ?)",
                   user_id, ssymbol, sname, share, sprice, timestamp, cost)

        # update cash
        db.execute("UPDATE users SET cash=cash-:cost WHERE id=:id", cost=cost, id=session["user_id"])

        # Redirect user to quote show page
        flash("Bought!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    trade = db.execute("SELECT symbol, shares, price, timestp FROM trade WHERE users_id=:id", id=session["user_id"])

    return render_template("history.html", trade=trade)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("Must provide symbol")

        # Lookup symbol in IEX
        stock = lookup(request.form.get("symbol"))

        # wrong symbol
        if stock == None:
            return apology("Wrong symbol!")

        # Redirect user to quote show page
        flash("Quote")
        return render_template("quote2.html", stock=stock)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password and confirmation was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists
        if len(rows) == 1:
            return apology("Username already taken", 400)

        if request.form.get("password") != request.form.get("confirmation"):
            return apology("Passwords not match", 400)

        # register user to db
        flash("Registered!")
        pwd = generate_password_hash(request.form.get("password"), method='pbkdf2:sha256', salt_length=8)
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)",  request.form.get("username"), pwd)

        # Redirect user to home page
        flash("Registered!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("Must provide symbol")

        if not request.form.get("shares"):
            return apology("Must provide quantity")

        if not request.form.get("shares").isdigit():
            return apology("Must provide valid quantity")

        if int(request.form.get("shares")) <= 0:
            return apology("Must provide valid quantity")

        # Lookup symbol in IEX
        stock = lookup(request.form.get("symbol"))

        # wrong symbol
        if stock == None:
            return apology("Wrong symbol!")

        trade = db.execute("SELECT symbol, name, SUM(shares) FROM trade WHERE users_id=:id AND symbol=:symbol GROUP BY symbol",
                           id=session["user_id"], symbol=request.form.get("symbol"))

        if stock['symbol'] not in trade[0]['symbol']:
            return apology("You dont own that stock!")

        if int(request.form.get("shares")) > trade[0]['SUM(shares)']:
            return apology("You dont own that amount of stock!")

        #user_id = session["user_id"]
        symbol = request.form.get("symbol")
        #sname = stock['name']
        #sprice = stock['price']
        share2 = int(request.form.get("shares"))
        share = int(request.form.get("shares")) * - 1
        cost = share * stock['price']
        cost2 = share2 * stock['price']
        result = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        cash = result[0]['cash']
        newcash = cash + cost

        # sell
        timestamp = date = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        db.execute("""INSERT INTO trade (users_id, symbol, name, shares, price, timestp, total)
                    VALUES(:user_id, :symbol, :name, :shares, :price, :timestp, :total) """,
                   user_id=session["user_id"], symbol=symbol, name=stock['name'],
                   shares=share, price=stock['price'], timestp=timestamp, total=cost)

        # update cash
        db.execute("UPDATE users SET cash=cash+:cost2 WHERE id=:id", cost2=cost2, id=session["user_id"])

        # Redirect user to quote show page
        flash("Sold!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        # show just owned stocks
        trade = db.execute("SELECT symbol, name, SUM(shares) FROM trade WHERE users_id=:id GROUP BY symbol HAVING SUM(shares) > 0",
                           id=session["user_id"])
        return render_template("sell.html", trade=trade)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
