1. [Specification](spec)
2. [Architecture](architecture.md)
3. [Development](development.md)
4. [Build](build.md)
5. [Self hosting](self_hosting.md)
6. [Security](security)


1. [Design](design.md)

--------


Bloom's mission is to empower people.

In order to empower people, we need to find better ways to connect them,
allow them to fulfill their need, to communicate, to discover things,
to work together...
All of this, by ganranteeing security of users and their data.

Bloom's users needs to be able to replace all of their app with only Bloom.

For example, an user who bought a new android device, just have to download Bloom, without creating
account on his device, to fulfill all his tasks.


When launching,


One of Bloom's main innovation are "groups". Also called "Teams", "Workspace", "Organizations" is other
apps and services, groups are a way to allow people to work, play, discuss, exchange idea together.

Each group have access to the same apps that a signle user have, but with real time collaboration.
Groups administrators are able to deactivate apps, to restrict usage by users.

If billing is reuquired to use an app in a group, and billing is not yet activated:
* if user is a group administrator, it indicate how to enable billing
* otherwise, it explain to contact a group administrator to enable billing

Groups can be nested to reflect an organization organigram


The other principal innovation, is the `discover` tab:
it allows to perform worldwide search

* News
* Web
* Videos
* Images

# API

API should be transport agnostic and based on messages (or events).

we register handlers like

```rust
server.handle("com.event.type", handler);
```

-------------

* [Billing](billing)
* [Bitflow](bitflow)
* [Calendar](calendar)
* [Contacts](contacts)
* [Drive](drive)
* [MyAccount](myaccount)
* [Notes](notes)
* [Phaser](phaser)
* [Platform](platform)

