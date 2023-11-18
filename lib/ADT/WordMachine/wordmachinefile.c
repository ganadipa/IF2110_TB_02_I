#include <stdio.h>
#include "wordmachinefile.h"

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
void IgnoreOnes(){
    while(currentCharFile == '\x01' && retvalfile != -1){
        ADVCHARFILE();
    }
}
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
    // EndFile = (currentCharFile == '\0');
    if (!EndFile){
        IgnoreBlanksFile();
        IgnoreNullFile();
        if(currentCharFile == MARK_LAST_FILE){
            EndFile = true;
        } else{
            EndFile = false;
            CopyWordFILE();
            // IgnoreNewLinesFile();
            ADVCHARFILE();
            ADVCHARFILE();
        }
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDFILE(){
    IgnoreOnes();
    CopyWordFILE();
    ADVCHARFILE();
    ADVCHARFILE();
}
void ADVWORDFILE2(){
    IgnoreOnes();
    CopyWordFILE2();
    ADVCHARFILE();
    if(currentCharFile == '\n'){
        ADVCHARFILE();
    }
}
void ADVFILEPHOTO(){
    CopyFILEPhoto();
    ADVCHARFILE();
    ADVCHARFILE();
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWordFILE(){
     if (currentCharFile == '\n' || currentCharFile == '\r'){
        currentWordFile.buffer[0] = '\n';
        currentWordFile.maxLength = 1;
    } else{
        int i = 0;
        while (currentCharFile != MARK_LAST_FILE && retvalfile != -1 && currentCharFile != '\r'){
            currentWordFile.buffer[i] = currentCharFile;
            currentWordFile.maxLength = i + 1;
            i++;
            ADVCHARFILE();
        }
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordFILE2(){
    int i = 0;
    while (currentCharFile != BLANK && currentCharFile != MARK_LAST_FILE && currentCharFile != '\r'){
        currentWordFile.buffer[i] = currentCharFile;
        currentWordFile.maxLength = i + 1;
        i++;
        ADVCHARFILE();
    }
    // printf("%c ", currentWordFile.buffer[0]);
}
void CopyFILEPhoto(){
    int i = 0;
    while (currentCharFile != MARK_LAST_FILE && currentCharFile != '\n' && currentCharFile != '\r'){
        currentWordFile.buffer[i] = currentCharFile;
        currentWordFile.maxLength = i + 1;
        i++;
        ADVCHARFILE();
    }
    currentWordFile.buffer[i] = '\n';
    currentWordFile.maxLength += 1;
    // printf("%c", currentWordFile.buffer[10]);
}

void TulisFile(FILE* filename, String kata){
    int i;
    int len = kata.maxLength;
    for(i=0;i<len;i++){
        fprintf(filename, kata.buffer[i]);
    }
    fprintf(filename, "\n");
}