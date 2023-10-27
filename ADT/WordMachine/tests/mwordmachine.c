#include <stdio.h>
#include "../wordmachine.c"
#include "../boolean.h"

int main(){
    Word word;
    int i=0, N;
    int test;
    printf("Masukkan no: ");
    scanf("%d", &test);
    scanf("%c");
    STARTWORD();
    switch (test){
        case 1:
            /* print ulang kata yang dimasukkan tanpa spasi*/
            while(!EndWord){
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", currentWord.TabWord[i]);
                }
                ADVWORD();
            }
            break;
        case 2:
            /* caesar cipher digeser sebanyak jumalah kata*/
            while(!EndWord){
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", ((currentWord.TabWord[i] - 'A' + currentWord.Length) % ('z' - 'A' + 1)) + 'A');
                }
                if (currentChar != MARK){
                    printf(" ");
                } else{
                    printf("");
                }
                ADVWORD();
            }
            break;

    }

}