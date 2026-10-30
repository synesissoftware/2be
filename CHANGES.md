# 2be - Changes <!-- omit in toc -->


## 0.1.5 - 31st October 2026

* testing:
  * `File:` labels under **test** name the project-relative path;


## 0.1.4 - 27th October 2026

* Defined `HAS_xTests` and `HAS_XTESTS` when **xTests** is detected;
* **test.scratch.versions** prints **STLSoft** under `HAS_STLSoft`;


## 0.1.3 - 14th October 2026

* Synced tip **cmake-helpers** runners (**run_all_examples** / **scratch** / **unit**);
* Migrated `TWOB_VER_ALPHABETA` to `TWOB_VER_RELSTATUS` (prior name retained as documentation-skip alias);
* Phase **4c** polish: `PROGRAM_NAME` **test.scratch.versions**;
* CI hygiene: **install-sis-deps**, execute-bit restore after artifact download, Windows **.cmd** dogfood, canonical push branches;


## 0.1.2 - 9th October 2026

* Applied **misc-dev-scripts** **0.6.0** editor/Git/`.sis` drop-in templates on **boilerplate**;
* Restored historical **.gitignore** patterns as a sorted union with **misc-dev-scripts** gold section layout;


## 0.1.1 - 7th August 2026

* **MSVC** compatibility: map POSIX `strncasecmp()` to `_strnicmp()` in **`src/truthy.c`** (and include **`<strings.h>`** on non-MSVC platforms);
* Modular GitHub Actions CI (**`ci.yml`** / **`ci-cell.yml`**) covering Linux (**Clang**/**GCC**/**TinyCC**), macOS (**Clang**), and Windows (**cl** / **MinGW**), with dependency install, unit tests, and install-verify; **TinyCC** is library build/install only (**`-T`** / no unit tests) until **STLSoft** / **xTests** support it (see **TODO.md**);
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
