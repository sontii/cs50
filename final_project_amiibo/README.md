# CS50 The Amiibo's
#### Video Demo:  https://youtu.be/Mo4HUia1FsY
## Description:

Amiibo finder is web application with python and flask framework.
The users data stored in local sql project.db file.

In this page you can look up for amiibos, search trough cards, and figures,
and if you like it you can set your favorite, and thats saved to the local database.

Written in the CS50 ide 

Data provider for API: https://amiiboapi.com/  Copyright © 2021 ; Coded by [Nevin Vu](https://www.n3evin.com/)
The API is  RESTful API for Amiibo. 
used values from response:

- Series

- Game series

- Character name

- Name

- Type (card or figure)

- image (to show image of the amiibo in a page)

  

In the helpers.py defined two lookups. The first one (lookup symbol) for if we know 
the name of amiibo. The second one (autocomp) lookup for all amiibo to use
auto complete in the find page drop down menu.

The project.db contains two tables. 

- users
  for store username and password

- favorites 

  to store favorite amiibo name

The find page GET method show the dropdown menu and the submit button.
POST method will show the selected amiibo in find page, with a "set favorite"button.

The favorite page GET method will show the favorite amiibo, except if no favorite
in database. Then you get a message: "You don't have favorite Amiibo!"
POST method will set a new favorite amiibo in the database. If already have a favorite amiibo
then the method will update the databese to the new one.

The flash message show changes in database.





------

### How to use:

In the landing page you need to complete the registration.
If your registration complete you can login and enters to the
main page.

in the top left the "C$50 The Amiibo's" link will get you to the main page

in the "find" link get the the finder. there is a drop down menu you can
search amiibo. The find button show details of the selected amiibo.

If you want you can set favorite amiibo.

"Favorite Amiibo" will show your favorite amiibo, except you don't set it up
you will get message: you don't have it yet.

"Log out" link will log out the system .

------

#### **Requirements:**

------

- Flask
- Python 3
- HTML5
- RESTFUL API [AmiiboAPI](https://amiiboapi.com/).
- Bootstrap
- sqlite3
- werkzeug
- CS50 IDE

------

##### Launch

------

To run enter to the command line:

```
$ export FLASK_APP=application.py
$ flask run
```

------

###### Files and folders

------

- /static
- /tempates
- helpes.py
- project.py
- project.db
- reqirement.txt