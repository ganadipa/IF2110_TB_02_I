#include "../lib/ADT/WordMachine/charmachinefile.h"
#include "../lib/ADT/WordMachine/wordmachinefile.h"
#include <stdio.h>
void load(){
   STARTWORDFILE();
   while (!EndWordFile){
        for (int i = 0 ; i < currentWordFile.maxLength; i++){
            printf("%c", currentWordFile.buffer[i]);
        }
        printf("\n");
        ADVWORDFILE();
   }

}