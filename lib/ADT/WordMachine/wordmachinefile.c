#include <stdio.h>
#include "wordmachinefile.h"

boolean EndFile;
String currentWordFile;

void IgnoreNewLinesFile()
{   /* kalo file udh abis IgnoreNewLinesFile bakal selesai*/
    /* jadinya bakal masuk ke EndFile = true */
    while (currentCharFile == '\n' && retvalfile!=-1){ 
        ADVCHARFILE();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ '\n'*/

void IgnoreNullFile(){
    while (currentCharFile == '\0' && retvalfile != -1){
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

void STARTWORDFILE(String filename){
    OPENFILE(filename);
    if (!EndFile){
        IgnoreBlanksFile();
        IgnoreNullFile();
        if(currentCharFile == MARK_LAST_FILE){
            EndFile = true;
        } else{
            EndFile = false;
            CopyWordFILE();
            IgnoreNewLinesFile();

        }
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDFILE(){
    if (currentCharFile == MARK_LAST_FILE){
        EndFile = true;
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

