#include <stdio.h>
#include "../wordmachine.h"
#include "../../../boolean.h"

int main(){
    int i=0, temp;
    int test;
    printf("Masukkan no: ");
    scanf("%d", &test);
    switch (test){
        case 1:
            /* print ulang kata yang dimasukkan tanpa spasi*/
            scanf("%u", &temp);
            STARTWORD();
            while(!EndWord){
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", currentWord.TabWord[i]);
                }
                if (currentChar_WordMachine != MARK_WordMachine){
                    printf(" ");
                }
                ADVWORD();
            }
            break;
        case 2:
            /* caesar cipher digeser sebanyak jumlah kata*/
            scanf("%u", &temp);
            STARTWORD();
            while(!EndWord){
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", ((currentWord.TabWord[i] - 'A' + currentWord.Length) % ('z' - 'A' + 1)) + 'A');
                }
                if (currentChar_WordMachine != MARK_WordMachine){
                    printf(" ");
                }
                ADVWORD();
            }
            break;
        case 3: 
            printf("%d", test);
            break;

    }

}