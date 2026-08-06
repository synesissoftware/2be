# 2be - CHANGES <!-- omit in toc -->


## 0.1.1 - 6th August 2026

* **MSVC** compatibility: map POSIX `strncasecmp()` to `_strnicmp()` in **`src/truthy.c`** (and include **`<strings.h>`** on non-MSVC platforms);
* Modular GitHub Actions CI (**`ci.yml`** / **`ci-cell.yml`**) covering Linux (**Clang**/**GCC**), macOS (**Clang**), and Windows (**cl** / **MinGW**), with dependency install, unit tests, and install-verify;
* Helper-script canonicalisation: **`.sis/project_name.txt`**; coloured **`run_all_*.sh`** runners; **`-v`** / **`--verbose`**; **`--unit-only`** / **`--component-only`**; stricter **`--no-make`** guarding; **`run_all_unit_tests.cmd`** parity;
* Corrected stale file headers in **`include/2be/2be.h`** and **`src/truthy.c`**;


## 0.1.0 - 7th September 2025

* Canonicalising with other SIS projects (CMake configuration, helper scripts, **`.sis/script_info_lines.txt`**);
* **`.gitattributes`**; CMake polishing; **LICENSE** added;
* **`run_all_unit_tests.cmd`** added;


## 0.0.4 - 1st September 2025

* **`.gitattributes`**;
* badges;
* links;
* documentation;


## 0.0.3 - 17th August 2025

* release;


## 0.0.3-alpha1 - 17th August 2025

* GitHub actions fixes;


## 0.0.2 - 17th August 2025

* simplifying dependencies;
* project boilerplate;


## 0.0.1 - 11th August 2025

* initial version;



<!-- ########################### end of file ########################### -->
