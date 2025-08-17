# to-be <!-- omit in toc -->

[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)

Simple C library determining whether strings indicate truey or falsy values.


## Introduction

**to-be** is a library providing facilities for determine whether the truthyness of strings. It implemented in several languages: **2be** is the **C** implementation.


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Terminology](#terminology)
- [Installation](#installation)
- [Components](#components)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
    - [Development/Testing Dependencies](#developmenttesting-dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Terminology

The term "*truthy*" is an unhelpfully overloaded term in the programming world, insofar as it is used to refer to the notion of "truthyness" - whether something can be _deemed to be_ interpretable as truth - and also the true side of that interpretation. In this library, the former interpretation is used, leaving us with the following terms:

* "*truthy*" - whether something can be can be _deemed to be_ interpretable as having truth;
* "*falsey*" - whether an object can be _deemed to be_ interpretable as being false;
* "*truey*" - whether an object can be _deemed to be_ interpretable as being true;

For example, consider the following **Go** program:

```C
#include <2be/2be.h>

char const* s1 = "no";
char const* s2 = "True";
char const* s3 = "orange";

// "no" is validly truthy, and is falsey
twob_string_is_falsey((s1) // true
twob_string_is_truey(s1)   // false
twob_string_is_truthy(s1)  // true

// "True" is validly truthy, and is truey
twob_string_is_falsey((s2) // false
twob_string_is_truey(s2)   // true
twob_string_is_truthy(s2)  // true

// "orange" is not validly truthy, and is neither falsey nor truey
twob_string_is_falsey((s3) // false
twob_string_is_truey(s3)   // false
twob_string_is_truthy(s3)  // false
```

## Installation

T.B.C.


## Components

T.B.C.


## Examples

Examples are provided in the ```examples``` directory, along with a markdown description for each. A detailed list TOC of them is provided in [EXAMPLES.md](./EXAMPLES.md).


## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/2be "GitHub Page")

### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/2be.


### Dependencies

No dependencies


#### Development/Testing Dependencies

* [**STLSoft-1.11**](https://github.com/synesissoftware/STLSoft-1.11/);
* [**xTests**](https://github.com/synesissoftware/xTests/);


### Related projects

* [**py2be**](https://github.com/synesissoftware/py2be) (**Python**);
* [**to-be.Go**](https://github.com/synesissoftware/to-be) (**to-be.Go**);
* [**to-be.Ruby**](https://github.com/synesissoftware/to-be.Ruby);
* [**to-be.Rust**](https://github.com/synesissoftware/to-be.Rust);


### License

**to-be.Go** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

