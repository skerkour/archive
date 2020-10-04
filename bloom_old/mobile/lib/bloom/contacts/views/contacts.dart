import 'package:bloom/bloom/contacts/blocs/contacts.dart';
import 'package:bloom/bloom/contacts/views/contact.dart';
import 'package:bloom/bloom/contacts/widgets/drawer.dart';
import 'package:bloom/bloom/contacts/models/db/contact.dart';
import 'package:flutter/material.dart';

class ContactsView extends StatefulWidget {
  @override
  _ContactsState createState() => _ContactsState();
}

class _ContactsState extends State<ContactsView> {
  ContactsBloc _bloc;

  @override
  void initState() {
    _bloc = ContactsBloc();
    super.initState();
  }

  @override
  void dispose() {
    _bloc.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    _bloc.getContacts();
    return Scaffold(
      endDrawer: const ContactsDrawer(),
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: const Text('Contacts'),
      ),
      body: StreamBuilder<List<Contact>>(
          stream: _bloc.contactsStream,
          builder:
              (BuildContext context, AsyncSnapshot<List<Contact>> snapshot) {
            if (snapshot.hasData) {
              return _buildBody(snapshot.data);
            } else {
              return const Center(child: CircularProgressIndicator());
            }
          }),
      floatingActionButton: FloatingActionButton(
        onPressed: () => _newContactTapped(context),
        child: Icon(Icons.add),
        backgroundColor: Colors.red,
      ),
    );
  }

  SafeArea _buildBody(List<Contact> contacts) {
    return SafeArea(
      child: ListView.builder(
        itemCount: contacts.length ?? 0,
        itemBuilder: (BuildContext context, int index) {
          final Contact contact = contacts.elementAt(index);
          return ListTile(
            onTap: () {
              Navigator.push<dynamic>(
                context,
                MaterialPageRoute<dynamic>(
                  builder: (BuildContext context) =>
                      ContactView(contact: contact),
                ),
              );
            },
            // leading: (contact.avatar != null && contact.avatar.isNotEmpty)
            //     ? CircleAvatar(backgroundImage: MemoryImage(contact.avatar))
            leading: CircleAvatar(
                child: Text((contact.name[0] ?? '').toUpperCase())),
            title: Text(contact.name),
          );
        },
      ),
    );
  }

  Future<void> _newContactTapped(BuildContext ctx) async {
    print('new contact tapped');
  }
}
