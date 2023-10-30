#include <stdio.h>
#include "../wordmachine.h"
#include "../../boolean.h"

int main(){
    int i=0, temp;
    int test;
    printf("Masukkan no: ");
    scanf("%d", &test);
    scanf("%u", &temp);
    STARTWORD();
    switch (test){
        case 1:
            /* print ulang kata yang dimasukkan tanpa spasi*/
            while(!EndWord){
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", currentWord.TabWord[i]);
                }
                if (currentChar_WordMachine != MARK_WordMachine){
                    printf(" ");
                }
                ADVWORD();
            }
            printf("\n");
            break;
        case 2:
            /* caesar cipher digeser sebanyak jumlah kata*/
            while(!EndWord){
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", ((currentWord.TabWord[i] - 'A' + currentWord.Length) % ('z' - 'A' + 1)) + 'A');
                }
                if (currentChar_WordMachine != MARK_WordMachine){
                    printf(" ");
                }
                ADVWORD();
            }
            printf("\n");
            break;

    }

}