#ifndef STRING_H
#define STRING_H

#include "../../boolean.h"
#include "../WordMachine/wordmachine.h"


#define STRCAP 351
#define MARK_STRING '\0'

typedef struct string
{
    char buffer[STRCAP];
    int maxLength;
} String;



void createEmptyString(String *s, int maxLength);
/*
    I.S. s sembarang
    F.S. s terbentuk dengan mark di elemen pertama.
*/

void readString(String *s, int maxLength);
/**
 * I.S. s sembarang
 * F.S. s terbentuk sebagai hasil input dari stdin.
*/

boolean isStringEqual(String s1, String s2);
/**
 * 
*/

int stringLength(String s);
/**
 * 
*/

boolean isStringFull (String s);
/**
 * 
*/

void addChar(String *s, char c);
/**
 * 

*/

void addWord(String *s, Word w);
/**
 * 
*/

boolean compareString(String s, char* cptr);
/**
 * 
*/

void displayString(String s);
/**
 * 
*/


#endif