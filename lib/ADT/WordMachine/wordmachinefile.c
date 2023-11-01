#include <stdio.h>
#include "wordmachinefile.h"

boolean EndWordFile;
String currentWordFile;

void IgnoreNewLinesFile()
{
    
    while (currentCharFile == '\n'){
        ADVCHARFILE();
        // printf("%c", currentCharFile);
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ '\n'*/

void IgnoreNullFile(){
    while (currentCharFile == '\0'){
        ADVCHARFILE();
    }
}

void IgnoreBlanksFile(){
    while (currentCharFile == BLANK){
        ADVCHARFILE();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORDFILE(){
    OPENFILE();
    IgnoreBlanksFile();
    IgnoreNullFile();
    printf("1");
    if(currentCharFile == MARK_LAST_FILE){
        printf("2");
        EndWordFile = true;
        printf("3");
    } else{
        printf("4");
        EndWordFile = false;
        printf("5");
        CopyWordFILE();
        printf("6");
        IgnoreNewLinesFile();
        printf("7");

    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDFILE(){
    if (currentCharFile == MARK_LAST_FILE){
        EndWordFile = true;
    } else{
        CopyWordFILE();
        IgnoreNewLinesFile();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWordFILE(){
    int i = 0;
    while (currentCharFile != MARK_LAST_FILE && currentCharFile != '\n'){
        currentWordFile.buffer[i] = currentCharFile;
        currentWordFile.maxLength = i + 1;
        i++;
        ADVCHARFILE();
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

