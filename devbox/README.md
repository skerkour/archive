# devbox

Collection of pretty CLI tools for developers and devops.

<!--

# To Do

setup alias section in installation
uninstall

* rg
* fd
* ds
* calc

* https://gitlab.com/bloom42/flint
* https://gitlab.com/bloom42/misspell
* hexdump
* http
* image burner (dd)
* Ip subnet calculator
* Govm
* Nvm
* rustvm
* http
* static server
* broken urls
* hashsum
* tls grad (comme sslab)
* website performance
* dedup
 -->

<!--

apps:
TODO:
setup alias section in installation

uninstall

install --binary --directory --force

todo
Podcast
books
mail
dl
http
mastodon
Calc
Password manager
File manager?
Revolut
Calendar
Notes
Edit(or)
Arcade
Voice recorder
Contacts
Radio
phone
Clock
convert (file converted)
mux: https://github.com/aaronjanse/3mux
dictionnary
airshare
htop like
 -->

1. [Installation](#installation)
2. [Tools](#tools)
    * [gowatch](#gowatch)
3. [Community](#community)
4. [Contributing](#contributing)
5. [Licensing](#licensing)
6. [Security](#security)


## Installation

```sh
$ go get -u github.com/bloom42/devbox
$ devbox install # install the symlinks
```


## Tools

### gowatch

`gowatch` is a utility that will monitor for any changes in your source and automatically rebuild your project.

```sh
$ gowatch -build="go build" -command="./myprogram"
```

## Community

Please use [issues](https://github.com/bloom42/devbox/issues) if you have some suggestions or want to report bugs.

You can follow us on [Twitter @42bloom](https://twitter.com/@42bloom) or on [Mastdon @42bloom@mastodon.social](https://mastodon.social/@42bloom) to never miss an update.

You can also subscribe to the newsletter to never miss an update: https://fatalentropy.com/

## Contributing

Thank you for your interest in contributing! Please refer to
https://gitlab.com/bloom42/wiki/-/wikis/organization/contributing for guidance.

**TL;DR:** Please open an issue to discuss before making a Merge Request (for things other than typos).


## Licensing

See `LICENSE.txt` and https://bloom.sh/licensing


## Security

You can read the details of our security architecture here: https://gitlab.com/bloom42/bloom/-/wikis/security.

If you found a security issue affecting this project, please do not open a public issue and refer to our
[dedicated security page](https://bloom.sh/security) instead. Thank you!
