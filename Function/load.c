#include "../lib/ADT/WordMachine/charmachinefile.h"
#include "../lib/ADT/WordMachine/wordmachinefile.h"
#include <stdio.h>
int main(){
   STARTWORDFILE();
   printf("/");
   while (!EndWordFile){
    printf("/");
        for (int i = 0 ; i < currentWordFile.maxLength; i++){
            printf("%c", currentWordFile.buffer[i]);
        }
        printf(" ");
        ADVWORDFILE();
   }

}