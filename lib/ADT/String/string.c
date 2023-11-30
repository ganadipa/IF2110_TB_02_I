
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


void toTitleCase(String *s){
    if (97 <= s->buffer[0] && s->buffer[0] <= 122){
        s->buffer[0] -= 32;
    }

    int length = stringLength(*s);
    int i;
    for (i = 1; i< length; i++){
        if (65 <= s->buffer[i] && s->buffer[i] <= 90){
            s->buffer[i] += 32;
        }
    }
}

int stringToInt(String s){
    int i;
    int j = 1;
    int k = 0;
    int length = stringLength(s);

    boolean isneg = false;
    if (s.buffer[0] == '-') isneg = true;


    for (i = length-1; i >= (0 + isneg); i--){
        if (s.buffer[i] - '0' < 0 || s.buffer[i]- '0' > 9) break;

        k += (s.buffer[i] - '0') * j;
        j *= 10;
    }
    return isneg? -k:k;
}

String intToString(int i, int numlength)
{
    String s;
    createEmptyString(&s, 350);

    int j = i;
    int length = 0;
    while (i > 0)
    {
        length++;
        i/= 10;
    }

    if (numlength < length) {
        return s;
    }

    int padZero = numlength - length;
    while(padZero--) {
        addChar(&s, '0');
    }

    int k = 0;
    for (k =0; k < length; k++) {
        int l = 1;
        int div = 1;
        for (l = 0; l < length -1-k; l++)
        {
            div *= 10;
        }


        int mod = div*10;
        int n = (j % mod)/div;
         

        addChar(&s, n + '0');
    }

    return s;

    
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


void addString(String *s, String s2){
    int length = stringLength(s2);
    int i = 0; 
    for(i = 0; i < length; i++){
        addChar(s, s2.buffer[i]);
    }
}
void replaceString(String *s, int idx, int idx2, String s2){
    int i = idx;
    int j = 0;
    for(i= idx; i < idx2; i++){
        s->buffer[i] = s2.buffer[j];
        j++;
    }
}
char *addChartoChar(char *destination, const char *source){
    if (destination == NULL){
        return NULL;
    }
    int i = 0;
    while (source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
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
    if (currentChar_WordMachine != '\n') {
        printf("\nSetiap input harus memiliki mark berupa ';'. dan Anda baru saja melanggarnya.\n");
    }
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

boolean isStringInsensitivelyEqual(String s1, String s2)

{
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);
    if (len1 != len2) return false;



    int i = 0;
    boolean check = true;
    while (i < len1 && check) {
        int num1 = s1.buffer[i] - 'A';
        int num2 = s2.buffer[i] - 'A';


        if (isAlphabet(s1.buffer[i])) {
            if (isAlphabetLowerCase(s1.buffer[i])) {
                if (num2 != num1 && num2 != num1-32) check = false;
            } else {
                if (num2 != num1 && num2 != num1+32) check = false;
            }
        } else {
            if (s1.buffer[i] != s2.buffer[i]) check = false;
        }
        
        i++;
    }

    return check;
}

boolean isAlphabet(char c) 

{
    int num = (int) c;
    return (65 <= num && num <= 90) || (97 <= num && num <= 122);
}

boolean isAlphabetLowerCase(char c) 

{
    int i = c - 'a';
    return i >= 0 && i <= 25;
}

boolean compareString(String s, char* cptr)
{
    int i = 0;
    boolean finish = false;
    boolean check = true;
    if (*cptr == '\0' && s.buffer[i] == '\0') finish = true;

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

boolean compareStringInsensitively(String s, char* cptr)
{
    int i = 0;
    boolean finish = false;
    boolean check = true;
    if (*cptr == '\0' && s.buffer[i] == '\0') return true;

    while (!finish && check) {
        int num1 = *cptr - 'A';
        int num2 = s.buffer[i] - 'A';


        if (isAlphabet(s.buffer[i])) {
            if (isAlphabetLowerCase(s.buffer[i])) {
                if (num1 != num2 && num1 != num2 - 32) check = false;
            } else {
                if (num1 != num2 && num1 != num2 + 32) check = false;
            }
        } else {
            if (num1 != num2) check = false;
        }

        if (check) {
            cptr++;
            i++;
        } else {
            finish = true;
        }

        if (*cptr == '\0' && s.buffer[i] == '\0') finish = true;

    }

    return check;
}

void displayString(String s) {
    int len = stringLength(s);
    int i;
    for (i = 0; i < len; i++) {
        printf("%c", s.buffer[i]);
    }
}

boolean isAllNumber(String s) {
    int len = stringLength(s);
    boolean check = true;

    int i = 0;
    while (i < len && check) {
        int num = s.buffer[i] - '0';
        if (num > 10 || num < 0) check = false;
        i++;
    }

    return check;
}

String getWordAt(String s, int i) 
/**
 * Mulanya, string s terdefinisi, i < n di mana n adalah jumlah kata dalam string s.
 * Mendapatkan string yang berisi kata ke-i (0-indexed).
*/

{
    String oneWord;
    createEmptyString(&oneWord, 350);

    int k = 0, ptr = 0;;
    while (k < i) {
        if (s.buffer[ptr] != ' ') {
            ptr++;
            }
        else 
         {
            k++;
            while (s.buffer[ptr] == ' ') {
                ptr++;
            }
         }
    }

    while (s.buffer[ptr] != ' ' && s.buffer[ptr] != '\0') {
        addChar(&oneWord, s.buffer[ptr]);
        ptr++;
    }

    return oneWord;
}

int countWord(String s)

/**
 * 
*/

{
    int k= 0, ptr = 0;
    if (s.buffer[0] == '\0') return 0;

    while (s.buffer[ptr] != '\0') {
        if (s.buffer[ptr] != ' ') {
            ptr++;
        }
        else 
         {
            k++;
            while (s.buffer[ptr] == ' ') {
                ptr++;
            }
         }
    }

    return k+1;

}

boolean isAllSpace(String s){
    int length = stringLength(s);
    int i;
    for (i = 0; i < length; i++) {
        if (s.buffer[i] != ' ')
            return false;
    }

    return true;
}

void SplitIntoTwo(String s, String* s1, String* s2) {
    createEmptyString(s1, 350);
    createEmptyString(s2, 350);
    *s1 = getWordAt(s, 0);
    int k = 0, ptr = 0, i = stringLength(s);
    while (k < i) {
        if (s.buffer[ptr] == ' ') {
            ptr++;
            break;
        }
        k++;
        ptr++;
    }

    while (k < i) {
        addChar(s2, s.buffer[ptr]);
        ptr++;
        k++;
    }
}
void removeLastWord(String* s){
    int i;
    int length = stringLength(*s);
    for (i = length-1; i >= 0; i--){
        if (s->buffer[i] == ' ' ) {
            s->buffer[i] = '\0';
            break;
        }
    }
}

String getLastWord(String s) {
    String result;
    int cnt = countWord(s);
    result = getWordAt(s, cnt-1);
    return result;
}