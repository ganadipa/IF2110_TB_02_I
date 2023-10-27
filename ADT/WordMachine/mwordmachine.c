#include <stdio.h>
#include "wordmachine.c"
#include "boolean.h"

int main(){
    Word word;
    int i=0;
    int test;
    printf("Masukkan no: ");
    scanf("%d", &test);
    switch (test){
        case 1:
            /* print ulang kata yang dimasukkan tanpa spasi*/
            STARTWORD();
            while(!EndWord){
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", currentWord.TabWord[i]);
                }
                ADVWORD();
            }
            break;
        case 2:
            printf("n");
            break;
    }

}