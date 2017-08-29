# ziar
[![Build Status](https://travis-ci.org/lovasko/ziar.svg?branch=master)](https://travis-ci.org/lovasko/ziar)

## Introduction
ziar is a path tracer written in C99, intended to run on all POSIX-compliant
operating systems.

## Features
The processing engine supports the following list of features:

### Cameras
* perspective

### Geometry objects
* infinite plane
* sphere
* triangle

### Rendering procedures
* simple cosine debug mode

## Build & run
The project can be built using the standard POSIX-compliant `make`:
```
$ make
$ ./bin/run
```

## License
This project is licensed under the terms of the 2-clause BSD
license.  For more information please consult the [LICENSE](LICENSE)
file. In case you need a different license, feel free to contact the
author.

## Author
Daniel Lovasko <daniel.lovasko@gmail.com>
