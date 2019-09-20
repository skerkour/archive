var g_id = 0;

function strIsEmpty(str) {
	return (str.length === 0 || !str.trim());
}

function addNotee() {
	var str = prompt("Please enter some content");
	if (!strIsEmpty(str)) {
		addNote(str, g_id, 1);
		g_id++;
	}
}

function addNote(str, id, post) {
	$("<div />", {
		id: 'note_'+id,
		onClick: 'removeNote('+id+');'
	}).insertAfter("#newBtn").text(str);
	if (post)
		$.post("insert.php", {id: id, str: str});
}

function removeNote(n) {
	if (confirm('Voulez-vous vraiment supprimer cette note ?')) {
		$('#note_'+n).remove();
		$.get("delete.php?id="+n);
	}
}

window.onload = function () {
	$.getJSON("select.php", function(result){
		$.each(result, function(i, field){
			if (field) {
				addNote(field, i, 0);
				g_id = parseInt(i) + 1;
			}
		});
	});
}
