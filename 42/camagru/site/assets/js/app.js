var app = {

// GetElemtById
  GEBI: function(id) {
    return document.getElementById(id);
  },

  
// HTTP
  http: function(method, url, cb) {
    var xhttp;
    if (window.XMLHttpRequest) {
      xhttp = new XMLHttpRequest();
    } else {
      xhttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4) {
        cb(this)
      }
    }

    xhttp.open(method, url, true);
    return xhttp;
  },


// GET  
  get: function(url, cb) {
    var req = app.http("GET", url, cb);
    req.send();
  },

// POST
  post: function(url, payload, cb) {
    var req = app.http("POST", url, cb);
    req.send(payload);
  },

// POST JSON
  post_JSON: function(url, payload, cb) {
    var req = app.http("POST", url, cb);
    req.setRequestHeader('Content-Type', 'application/json');
    req.send(JSON.stringify(payload));
  },



// LOGIN
  login: function() {
    var email_input = app.GEBI('login_email');
    var email = email_input.value;
    var password_input = app.GEBI('login_password');
    var password = password_input.value;

    var creds = {
      email: email,
      password: password
    };

    app.post_JSON("/api/auth/password", creds, function(res) {
      res.data = JSON.parse(res.response);
      if (res.status > 226) {
        app.alert_box_error(res.data.informations);
      } else {
        var token = res.data.token;
        var id = res.data.id;
        var username = res.data.username;
        app.set_cookie('id', id);
        app.set_cookie('token', token);
        app.set_cookie('username', username);
        app.redirect('/home');
      }

    });
  },


// LOGOUT
  logout: function() {
        app.unset_cookie('id');
        app.unset_cookie('token');
        app.unset_cookie('username');
        app.redirect('/login');
  },


// REGISTER
  register: function() {
    var email_input = app.GEBI('register_email');
    var email = email_input.value;
    var username_input = app.GEBI('register_username');
    var username = username_input.value;
    var password_input = app.GEBI('register_password');
    var password = password_input.value;

    var user = {
      email: email,
      username: username,
      password: password
    };
    app.post_JSON("/api/users", user, function(res) {
      res.data = JSON.parse(res.response);
      if (res.status > 226) {
        app.alert_box_error(res.data.informations);
      }
      
    });
  },


// REDIRECT  
  redirect: function(url) {
    window.location = url;
  },

// ALERT BOX ERROR
  alert_box_error: function(msg) {
    app.GEBI("alert_box_content").innerHTML = msg;
    app.GEBI("alert_box").className = "alert-box-error";
  },
// ALERT BOX HIDE
  alert_box_hide: function() {
    app.GEBI("alert_box").className = "hidden";
  },


// GET COOKIE
  get_cookie: function(cname) {
    var name = cname + '=';
    var ca = document.cookie.split(';');
    for(var i = 0; i <ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length,c.length);
        }
    }
    return "";
  },


// SET COOKIE
  set_cookie: function(cname, cvalue, exdays) {
    if (exdays == undefined) {
      exdays = 42;
    }
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = 'expires='+ d.toUTCString();
    document.cookie = cname + '=' + cvalue + ';' + expires + ';path=/';
  },


// UNSET COOKIE
  unset_cookie: function(cname) {
    var exdays = -42;
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = 'expires='+ d.toUTCString();
    document.cookie = cname + '=' + ' ;' + expires + ';path=/';
  },

};
