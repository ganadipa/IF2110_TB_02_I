#include <stdio.h>
#include "Photo.h"
#include "../ADT/PColor/pcolor.h"

void initializePhoto(Photo *p)
/**
 * 
*/
{
    createMatrix_CharMatriks(5, 5, &SYMMATRIX(*p));
    createMatrix_CharMatriks(5, 5, &COLORMATRIX(*p));

    int i = 0;
    int j = 0;
    for (i = 0; i < 5; i++) {
        for (j =0; j < 5; j++) {
            ELMT_CharMatriks(SYMMATRIX(*p), i, j) = '*';
            ELMT_CharMatriks(COLORMATRIX(*p), i, j) = 'R';
        }
    }
}

void readPhoto(Photo *p) {
    char color;
    char symbol;
    int i = 0;
    int j = 0;
    for (i = 0; i< 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%c %c", &color, &symbol);
            ELMT_CharMatriks(SYMMATRIX(*p), i, j) = symbol;
            ELMT_CharMatriks(COLORMATRIX(*p), i, j) = color;
        }
    }
}

void displayPhoto(Photo p) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (ELMT_CharMatriks(COLORMATRIX(p), i, j) == 'R') {
                print_red(ELMT_CharMatriks(SYMMATRIX(p), i, j));
            } else if (ELMT_CharMatriks(COLORMATRIX(p), i, j) == 'G') {
                print_green(ELMT_CharMatriks(SYMMATRIX(p), i, j));
            } else {
                print_blue(ELMT_CharMatriks(SYMMATRIX(p), i, j));
            }
        }
        printf("\n");
    }
}