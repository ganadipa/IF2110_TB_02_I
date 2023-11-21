#include <stdio.h>
#include "../wordmachinefile.h"

int main(){
    int i=0, temp;
    int test;
    printf("Masukkan no: ");
    scanf("%d", &test);
    switch (test){
        case 1:
        String filename = {"kicauan.config", 200};
        STARTWORDFILE(filename);
            displayString(currentWordFile);
        if (retvalfile != -1){
            printf("1");
            int jumlahkicau = stringToInt(currentWordFile);
            printf("%c",currentCharFile);
            printf("%d\n", jumlahkicau);
            for(i=0;i<jumlahkicau;i++){
                Kicauan kicau;
                ADVWORDFILE();
                int IdKicau = stringToInt(currentWordFile);
                printf("%d\n", IdKicau);
                ADVWORDFILE();
                String text = currentWordFile;
                displayString(text);
                printf("\n");
                ADVWORDFILE();
                int like = stringToInt(currentWordFile);
                printf("%d\n", like);
                ADVWORDFILE();
                displayString(currentWordFile);
                printf("\n");
                ADVWORDFILE();
                displayString(currentWordFile);
                printf("\n");
            }

        }
        CLOSEFILE();
        break;

    }
}