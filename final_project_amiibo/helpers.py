import os
import requests
import urllib.parse
import json

from flask import redirect, render_template, request, session
from functools import wraps


def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/1.1.x/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


def lookup(symbol):
    """Look up quote for symbol."""

    # Contact API
    try:
        api_key = os.environ.get("API_KEY")
        url = f"https://www.amiiboapi.com/api/amiibo/?character={symbol}"
        response = requests.get(url)
        response.raise_for_status()
        quote = response.json()
        # get nested dictionary value
        for i in quote['amiibo']:
            series = i['amiiboSeries']
            character = i['character']
            gseries = i['gameSeries']
            image = i['image']
            name = i['name']
            atype = i['type']
    except requests.RequestException:
        return None

    # Parse response
    try:
        quote = response.json()
        return {
            "series": series,
            "character": character,
            "gseries": gseries,
            "image": image,
            "name": name,
            "atype": atype
        }
    except (KeyError, TypeError, ValueError):
        return None


# function for autocomplete search amiibo
def autocomp():
    """Look all amiibo for autocomplete."""

    # Contact API
    try:
        url = "https://www.amiiboapi.com/api/character"
        response = requests.get(url)
        response.raise_for_status()
        auto = response.json()

        results = []

        # get nested dictionary value
        for i in auto['amiibo']:
            results.append(i['name'])
        results.sort()
        return results

    except requests.RequestException:
        return None