<<<<<<< HEAD
#include <stdio.h>
#include "../wordmachine.h"
#include "../boolean.h"

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
        case 2:
    }

=======
#include <stdio.h>
#include "../wordmachine.h"
#include "../boolean.h"

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
                if (currentChar != MARK){
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
                if (currentChar != MARK){
                    printf(" ");
                }
                ADVWORD();
            }
            printf("\n");
            break;

    }

>>>>>>> develop
}