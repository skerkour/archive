var fs = require('fs');var QUINE = function () {fs.writeFile("./Grace_kid.js", "var fs = require('fs');var QUINE = " + QUINE.toString() + ";var MAIN = " + MAIN.toString() + ";MAIN();\n", (err) => {});};var MAIN = function () {QUINE();
/*
	lol1
*/
};MAIN();
