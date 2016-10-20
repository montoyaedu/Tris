Tris
====

A tris (italian for tic tac toe) implementation using ansi c and TDD

Usage
=====

`````
#include "Tris.h"
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
