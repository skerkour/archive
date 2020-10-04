import 'models/note.dart';

class NotesGuiListNotes {
  NotesGuiListNotes();

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{
      'type': 'notes.gui.list_notes',
      'data': <String, dynamic>{},
    };
    return data;
  }
}

class NotesGetArchive {
  NotesGetArchive();

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{
      'type': 'notes.gui.get_archive',
      'data': <String, dynamic>{},
    };
    return data;
  }
}

class NotesGuiNotes {
  NotesGuiNotes({this.notes});

  final List<Note> notes;

  static NotesGuiNotes fromJson(Map<String, dynamic> json) {
    final List<dynamic> list = json['data']['notes'];
    final List<Note> notes = list.map((dynamic i) => Note.fromJson(i)).toList();
    return NotesGuiNotes(notes: notes);
  }
}

class NotesGuiCreateNote {
  NotesGuiCreateNote(this.title, this.body, this.color);

  final String title;
  final String body;
  final int color;

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{
      'type': 'notes.gui.create_note',
      'data': <String, dynamic>{
        'title': title,
        'body': body,
        'color': color,
      },
    };
    return data;
  }
}

class NotesGuiNote {
  NotesGuiNote({this.note});

  final Note note;

  static NotesGuiNote fromJson(Map<String, dynamic> json) {
    final Note note = Note.fromJson(json['data']['note']);
    return NotesGuiNote(note: note);
  }
}

class NotesGuiUpdateNote {
  NotesGuiUpdateNote(this.note);

  final Note note;

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{
      'type': 'notes.gui.update_note',
      'data': <String, dynamic>{
        'note': note.toJson(),
      },
    };
    return data;
  }
}

class NotesGuiDeleteNote {
  NotesGuiDeleteNote(this.id);

  final String id;

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = <String, dynamic>{
      'type': 'notes.gui.delete_note',
      'data': <String, dynamic>{
        'id': id,
      },
    };
    return data;
  }
}
