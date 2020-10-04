# SANE vs ...


## SANE vs TOML

TOML is the primary inspiration for SANE, but there are some differences:

* SANE is easy to understand for anyone.
* Lists MUST be deeply homogenous.
* Maps (Tables) and Lists (Arrays) are cleaner, syntax is not mixed.
* Types are obvious (in TOML, are the types of `[[my_conf]]` and `[my_other_conf]` really obvious ?).
* Duplicated keys are not allowed: SANE is typo safe unlike TOML.
* SANE supports tooling like auto formatting (think gofmt) for better consistency and thus readability.
* SANE does not support DateTime contrary to TOML.
* SANE use only spaces as whitespaces character (VS spaces + tabs for TOML) which save from a lot of headache.
* SANE does not have a complex DateTime type.

## SANE vs JSON

* Comments are allowed
* No `null`
* Less ambiguous
* Duplicate keys are NOT allowed
* Unified format (in comparison of JSON derivatives like JSON5, HOCON...)


## SANE vs YAML

* Cleaner
* Safer
* Better
* Not indentation based (so tooling, like a linter, can be used to improve user experience)
