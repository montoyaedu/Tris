Tris
====

Status
======

[coverage status](https://montoyaedu.github.io/Tris/coverage.html)

A tris (italian for tic tac toe) implementation using ansi c and TDD

Requisites
==========

* gcc
* GNU make
* gcov
* gcovr

Usage
=====

`````C++
#include "TrisImpl.h"
#include <stdlib.h>
#include <assert.h>

int main() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    /**
      This game is won by X at 7th move
      XOX
      OXO
      X
     */
    assert(0 == add(t, Cross, 0, 0));
    assert(t->winner == None);
    assert(0 == add(t, Nought, 0, 1));
    assert(t->winner == None);
    assert(0 == add(t, Cross, 0, 2));
    assert(t->winner == None);
    assert(0 == add(t, Nought, 1, 0));
    assert(t->winner == None);
    assert(0 == add(t, Cross, 1, 1));
    assert(t->winner == None);
    assert(0 == add(t, Nought, 1, 2));
    assert(t->winner == None);
    assert(0 == add(t, Cross, 2, 0));
    assert(t->winner == Cross);
    return 0;
}
`````

Compile
=======

`````
make all
`````

Clean
=====

`````
make clean
`````

Execute Tests
=============

`````
make test
`````

View Coverage Results
=====================

`````
open gcovr-report-html/coverage.html
`````

TODO
====

Publish results to SonarQube.

Current Coverage Summary
========================

`````
------------------------------------------------------------------------------
                           GCC Code Coverage Report
Directory: .
------------------------------------------------------------------------------
File                                       Lines    Exec  Cover   Missing
------------------------------------------------------------------------------
TrisImpl.c                                    51      47    92%   19,65,68,94
TrisTest.c                                   125     121    96%   50-53
------------------------------------------------------------------------------
TOTAL                                        176     168    95%
------------------------------------------------------------------------------
`````
