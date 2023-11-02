#include "../lib/ADT/WordMachine/charmachinefile.c"
#include "../lib/ADT/WordMachine/wordmachinefile.c"
#include "../lib/ADT/WordMachine/wordmachine.c"
#include "../lib/ADT/WordMachine/charmachine.c"
#include "../lib/ADT/String/string.c"
#include <stdio.h>
int main(){
    String s;
    readString(&s, 351);
    STARTWORDFILE(s);
    while (!EndFile){
            
            for (int i = 0 ; i < currentWordFile.maxLength; i++){
                printf("%c", currentWordFile.buffer[i]);
            }
            printf("\n");
            ADVWORDFILE();
    }

}