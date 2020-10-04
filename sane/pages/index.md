# SANE

The Simple And NEeded configuration format

By <a href="https://kerkour.fr" target="_blank" rel="noopener noreferrer">Sylvain Kerkour</a>

## Goals

* SANE aims to be a simple open configuration format that's easy to read due to obvious and consistent semantics.
* SANE is designed to map unambiguously to a map (a.k.a hash table, a.k.a dictionary).
* SANE should be easy to parse into data structures in a wide variety of languages.
* SANE is designed to be **human to machine** not machine to machine (YAML, JSON...)
* SANE, as a modern format, is designed to support tooling like auto formatting / linting.


## Specs

* [v1.0.0](versions/v1.0.0)



## Issues and discussions

<a href="https://gitlab.com/bloom42/sane/issues" target="_blank" rel="noopener">On GitLab</a>


## Why

Prior to SANE, the software we built at [Bloom](https://bloom.sh) used a variety of
configuration languages from full programming languages such as JavaScript to complete data structure
languages such as TOML or JSON. The problem is that each of these languages have serious flaws which are
not acceptable to build software for the future.

Because of this, we decided to create our own configuration format designed to be written and read
by humans.

That being said you will easily notice that SANE found great inspiration from languages like TOML,
HCL, JSON.

Here are some of the killer features:

* Safe
* Comments are parsed as any other values and can be written by programs
* Less is more
* Human and parser friendly
* Pure data (no templating)
* Easy to use, even without syntax coloration
* Sane


## Example

```sane
# This is a SANE document

title = "SANE Example"

creator = {
  name = "Sylvain Kerkour",
  website = "https://kerkour.fr",
}

database = {
  server = "192.168.1.1",
  ports = [ 8001, 8001, 8002 ],
  connection_max = 5000,
  enabled = true,
}

servers = {
  # Indentation (only spaces) is allowed but not required
  alpha = {
    ip = "10.0.0.1",
    dc = "eqdc10",
  },

  beta = {
    ip = "10.0.0.2",
    dc = "eqdc10",
  },
}

empty_map = {}

hosts = [
  "alpha",
  "omega",
]
```

## SANE for

* Simple And NEeded
* Sane And NEat
* Safe And NicE
* Simple And NEw
* Simple And NoblE
* Sane's Appreciated by Nearly Everyone
