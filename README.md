# to-be <!-- omit in toc -->

![Language](https://img.shields.io/badge/C-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/2be.svg)](https://github.com/synesissoftware/2be/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/2be)](https://github.com/synesissoftware/2be/commits/master)
[![C/C++ CI](https://github.com/synesissoftware/2be/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/synesissoftware/2be/actions/workflows/c-cpp.yml)

Simple C library determining whether strings indicate truey or falsy values.


## Introduction

**to-be** is a library providing facilities for determine whether the truthyness of strings. It implemented in several languages: **2be** is the **C** implementation.


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Terminology](#terminology)
- [Installation](#installation)
- [Components](#components)
  - [Constants](#constants)
  - [Enumerations](#enumerations)
  - [Features](#features)
  - [Functions](#functions)
  - [Macros](#macros)
  - [Structures](#structures)
  - [(Simple) Types](#simple-types)
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

For example, consider the following **C** program:

```C
#include <2be/2be.h>

int main()
{
  char const* s1 = "no";
  char const* s2 = "True";
  char const* s3 = "orange";

  // "no" is validly truthy, and is falsey
  twob_string_is_falsey((s1) // !0
  twob_string_is_truey(s1)   // 0
  twob_string_is_truthy(s1)  // !0

  // "True" is validly truthy, and is truey
  twob_string_is_falsey((s2) // 0
  twob_string_is_truey(s2)   // !0
  twob_string_is_truthy(s2)  // !0

  // "orange" is not validly truthy, and is neither falsey nor truey
  twob_string_is_falsey((s3) // 0
  twob_string_is_truey(s3)   // 0
  twob_string_is_truthy(s3)  // 0

  return 0;
}
```

## Installation

**CMake** configuration files are provided, along with some helper scripts.

The following steps are suggested for a minimal build/installation:

1. Perform the CMake configuration
    ```bash
    export SIS_CMAKE_BUILD_DIR=/tmp/sis/2be
    ./prepare_cmake.sh -E -T
    ```
2. Build the library
    ```bash
    ./build_cmake.sh
    ```
3. Install
    ```bash
    sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release | grep -i -v up-to-date
    ```


## Components

### Constants

No public constants are defined at this time.


### Enumerations

No public enumerations are defined at this time.


### Features

No public crate-specific features are defined at this time.


### Functions

The following public functions are defined in the current version:

```C
/** Obtains the Diagnosticism version (at time of compilation)
 *
 * @note Can be called without having initialised the API.
 */
twob_uint32_t
twob_api_version(void);

/** Initialises the API.
 */
int
twob_api_init(
    twob_uint32_t   init_flags
,   void*           init_param
);
/** Uninitialises the API.
 */
void
twob_api_uninit(void);

/** Indicates that the given string, when trimmed, is classified as "truthy"
 * and is deemed as "falsey".
 */
int
twob_string_is_falsey(
    char const* s
);
/** Indicates that the given string, when trimmed, is classified as "truthy"
 * and is deemed as "truey".
 */
int
twob_string_is_truey(
    char const* s
);
/** Indicates that the given string, when trimmed, is classified as "truthy"
 * (and is deemed as either "falsey" or "truey").
 */
int
twob_string_is_truthy(
    char const* s
);
```


### Macros

No public macros are defined at this time.


### Structures

No public structures are defined at this time.


### (Simple) Types

The following public types are defined in the current version:

```C
typedef uint32_t twob_uint32_t;
```


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
* [**to_be.Ruby**](https://github.com/synesissoftware/to_be.Ruby);
* [**to-be.Rust**](https://github.com/synesissoftware/to-be.Rust);


### License

**to-be.Go** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

