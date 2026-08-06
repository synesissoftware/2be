# 2be - TODO <!-- omit in toc -->


## Packaging / CI

* [ ] **TinyCC CI with tests**: the **`linux-tcc`** cell currently builds and installs with **`BUILD_TESTING=OFF`** (equivalent to **`prepare_cmake.sh -T`**) and skips unit tests, because **STLSoft** and **xTests** are not yet TinyCC-compatible. Once they are, install those deps under TinyCC (or a suitable hybrid), configure with **`BUILD_TESTING=ON`**, and set **`run-tests: true`** for **`linux-tcc`**;


<!-- ########################### end of file ########################### -->
