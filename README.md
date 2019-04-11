# lib3mf
[![Build Status](https://travis-ci.org/3MFConsortium/lib3mf.svg?branch=master)](https://travis-ci.org/3MFConsortium/lib3mf)
[![Documentation Status](https://readthedocs.org/projects/lib3mf/badge/?version=latest)](https://readthedocs.org/projects/lib3mf)
![Supported platforms](https://img.shields.io/static/v1.svg?label=platform&message=windows%20%7C%20macos%20%7C%20linux&color=lightgrey)
[![Simplified BSD License](https://img.shields.io/static/v1.svg?label=license&message=BSD&color=green)](LICENSE)

lib3mf is a C++ implementation of the 3D Manufacturing Format file standard.

It provides 3MF reading and writing capabilities, as well as conversion and validation tools for input and output data. lib3mf runs on Windows, Linux and MacOS and offers a clean and easy-to-use API in [various programming languages]() to speed up the development and keep integration costs at a minimum.

As 3MF shall become an universal 3D Printing standard, its quick adoption is very important. 
This library shall lower all barriers of adoption to any possible user, let it be software 
providers, hardware providers, service providers or middleware tools.

The specification can be downloaded at
[http://3mf.io/specification/](http://3mf.io/specification/).


## Documentation
lib3mf's documentation is available on https://lib3mf.readthedocs.io.

## Obtaining lib3mf
Simply download the precompiled binary SDK https://github.com/3MFConsortium/lib3mf/releases.

### Dependencies:
On Unix-systems you have to install [uuid](https://linux.die.net/man/3/uuid)
  * Linux (Ubuntu/Debian): `sudo apt-get install uuid-dev`
  * MAC: `brew install ossp-uuid`

## Using lib3mf
Allthough the different language bindings are kept as similar as possible,
the usage of lib3mf still depends your programming language.

You are best-off starting with one of the examples distributed in the [SDK](https://github.com/3MFConsortium/lib3mf/releases) or with this [minimal example in C++](https://link-to-C++-minimal).

## Contributing
lib3mf is an open source project and supported by the [3MF Consortium](https://3mf.io/).

Contributions are welcome and we are always looking for people that improve the implementation of the specification and extensions of 3MF. Have a look at the [contributor's guide](CONTRIBUTING.md) for details.
This page also contains a section about building lib3mf from source or obtaining nightly snapshot builds.
