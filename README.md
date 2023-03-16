# CycloneDDS examples for Zephyr RTOS

## Purpose
This repository contains some proof-of-concept applications that show how to build and use [CycloneDDS](https://github.com/eclipse-cyclonedds/cyclonedds) on [Zephyr RTOS](https://www.zephyrproject.org)

## Usage:
This repository can be cloned and used like any generic Zephyr application. CycloneDDS is included as a git submodule.
The `CMakeLists.txt` is currently setup to build CycloneDDS examples and ddsperf but can be easily modified or extended for other application code.

For example, to build Roundtrip Ping for the `s32z270dc2_rtu0_r52` target:
```
$ west build -b s32z270dc2_rtu0_r52 . -- -DBUILD_ROUNDTRIP_PING=1
```
To build for qemu_x86, with ethernet support:
```
$ west build -b x86_64 . -- -DOVERLAY_CONFIG=overlay-e1000.conf -DBUILD_ROUNDTRIP_PING=1
```
Command-line parameters for the example can be modified in `src/rountrip_main.c`

The `copy_examples.sh` script can be used (manually) to update the code from CycloneDDS examples and run idlc to generate types.

The CycloneDDS configuration in `config.xml` is automatically converted to a char array and available as env. var to support the default behaviour of retrieving config from CYCLONEDDS_URI.
Alternatively, [dds_create_domain_with_rawconfig](https://cyclonedds.io/docs/cyclonedds/latest/api/domain.html?#c.dds_create_domain_with_rawconfig) can be used without XML configuration data.
