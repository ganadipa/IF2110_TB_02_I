
#ifndef PHOTO_H
#define PHOTO_H

#include "../boolean.h"
#include "../ADT/String/string.h"
#include "../ADT/Matriks/charMatriks.h"

typedef struct photo {
    CharMatrix symbols;
    CharMatrix color;
} Photo;


#define SYMMATRIX(u) (u).symbols
#define COLORMATRIX(u) (u).color

void initializePhoto(Photo *p);
/**
 * 
*/

void readPhoto(Photo *p); 
/**
 * 
*/
void readPhotoFile(Photo *p, String photoString);
void displayPhoto(Photo p);
/**
 * 
*/

#endif