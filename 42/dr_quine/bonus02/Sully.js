var i = 5;
(function main() {
	const path = require('path');
	const fs = require('fs');
	const exec = require('child_process').exec;

	const file = path.basename(__filename);

	if (file.indexOf('_') > -1) {
		i -= 1;
	}
	if (i >= 0) {
		const name = `Sully_${i}.js`;
		fs.writeFile(name, `var i = ${i};\n(${main.toString()})();\n`, () => {});
		exec(`node ./${name}`);
	}
})();
