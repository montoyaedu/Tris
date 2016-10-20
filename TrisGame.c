#include "TrisImpl.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int getRow(int pos) {
    if (pos >= 1 && pos <= 3) {
        return 0;
    } else if (pos >= 4 && pos <= 6) {
        return 1;
    } else if (pos >= 7 && pos <= 9) {
        return 2;
    }
    return -1;
}

int getColumn(int pos) {
    if (pos == 1 || pos == 4 || pos == 7) {
        return 0;
    } else if (pos == 2 || pos == 5 || pos == 8) {
        return 1;
    } else if (pos == 3 || pos == 6 || pos == 9) {
        return 2;
    }
    return -1;
}

void render(tris_t* t) {
    for (int i = 0; i < 9; i++) {
        if (i%3 == 0) {
            fprintf(stderr, "\n");
        }
        if (t->grid[i] == None) {
            fprintf(stderr, "%d", i + 1);
        } else if (t->grid[i] == Cross) {
            fprintf(stderr, "X");
        } else if (t->grid[i] == Nought) {
            fprintf(stderr, "O");
        }
    }
    fprintf(stderr, "\n");
    if (t->winner == None) {
        fprintf(stderr, "There is no winner");
    } else if (t->winner == Cross) {
        fprintf(stderr, "Winner is Cross X");
    } else if (t->winner == Nought) {
        fprintf(stderr, "Winner is Nought O");
    }
    fprintf(stderr, "\n");
    if (t->winner == None) {
        if (t->next == None) {
            fprintf(stderr, "It's None's turn");
        } else if (t->next == Cross) {
            fprintf(stderr, "It's Cross' turn");
        } else if (t->next == Nought) {
            fprintf(stderr, "It's Nought' turn");
        }
    }
    fprintf(stderr, "\n");
}

int main() {
    tris_t* t = (tris_t*) calloc(1, sizeof(tris_t));
    new_game(t);
    char pressed;
    do {
        system("clear");
        fprintf(stderr, "TRIS\n");
        fprintf(stderr, "====\n");
        render(t);
        fprintf(stderr, "press n <ENTER> restart a new game...\n");
        fprintf(stderr, "press q <ENTER> to exit ...\n");
        fprintf(stderr, "press [1-9] <ENTER> to play\n");
        pressed = getchar();
        if (pressed == 'n') {
            free(t);
            t = (tris_t*) calloc(1, sizeof(tris_t));
            new_game(t);
        } else if (pressed != 'q') {
            char pressed_c[2] = {0, 0};
            sprintf(pressed_c, "%c", pressed);
            int pos = atoi(pressed_c);
            if (pos >= 1 && pos <= 9) {
                int row = getRow(pos);
                int column = getColumn(pos);
                int rc = add(t, t->next, row, column);
                if (rc != 0) {
                }
            }
        }
    } while(pressed != 'q');
    return 0;
}
