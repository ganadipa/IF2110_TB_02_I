
#include "./string.h"
#include <stdio.h>

void createEmptyString(String *s, int maxLength)
/*
    I.S. s sembarang, 0 <= maxLength <= 350
    F.S. s terbentuk dengan mark di elemen pertama.
*/
{
    (*s).buffer[0] = '\0';
    s->maxLength = maxLength;
}

int stringLength(String s) 

{
    boolean found = false;
    int i = 0;
    while (i < s.maxLength && !found) {
        if (s.buffer[i] == '\0') found = true;
        else{
            i++;
        }

    }

    return i;
}

boolean isStringFull (String s) {
    return s.maxLength == stringLength(s);
}

void addChar(String *s, char c)
/**
 * 
*/
{
    int len = stringLength(*s);
    int maxlen = s->maxLength;
    if (len < maxlen) {
        s->buffer[len] = c;
        s->buffer[len+1] = '\0';
    }

}

void addWord(String *s, Word w)
{
    int length = w.Length;
    int i = 0;
    for (i = 0; i<length; i++){
        addChar(s, w.TabWord[i]);
    }
}

void readString(String *s, int maxLength)
/**
 * I.S. s sembarang, pita terbuka
 * F.S. s terbentuk sebagai hasil input dari stdin, currentChar bernilai '\n'.
*/
{
    createEmptyString(s, maxLength);

    if (currentChar_WordMachine == '\0' || currentChar_WordMachine == '\n')
    {
        IgnoreNewLinesAndNull();
    } else {
        ADV();
    }

    while (currentChar_WordMachine != MARK_WordMachine) {
        addChar(s, currentChar_WordMachine);
        ADV();
    }

    ADV();
    // now current char is '\n'
}

boolean isStringEqual(String s1, String s2)

{
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);
    if (len1 != len2) return false;
    int i = 0;
    boolean check = true;
    while (i < len1 && check) {
        if (s1.buffer[i] != s2.buffer[i]) check = false;
        i++;
    }

    return check;
}

boolean compareString(String s, char* cptr)
{
    int i = 0;
    boolean finish = false;
    boolean check = true;
    while (!finish) {
        if (*cptr != s.buffer[i]) {
            finish = true;
            check = false;
        }
        else {
            cptr++;
            i++;
        }

        if (*cptr == '\0' && s.buffer[i] == '\0') finish = true;

    }

    return check;
}

void displayString(String s) {
    int len = stringLength(s);

    for (int i = 0; i < len; i++) {
        printf("%c", s.buffer[i]);
    }
}