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

boolean isStringInsensitivelyEqual(String s1, String s2);

boolean isAlphabet(char c);

boolean isAlphabetLowerCase(char c);

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

String concatString(String *sOut, String s1, String s2);
/**
 * 
*/


boolean compareString(String s, char* cptr);
/**
 * 
*/

boolean compareStringInsensitively(String s, char* cptr);
/**
 * 
*/

void displayString(String s);
/**
 * 
*/

boolean isAllNumber(String s);

String getWordAt(String s, int i) ;
/**
 * Mulanya, string s terdefinisi, i < n di mana n adalah jumlah kata dalam string s.
 * Mendapatkan string yang berisi kata ke-i (0-indexed).
*/

int countWord(String s);


#endif