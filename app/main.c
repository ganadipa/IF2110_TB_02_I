#include <stdio.h>
#include "../lib/lib.h"

void handleCommand(Application* app, String command, boolean *finish) 
/**
 * 
*/
{
    int numword = countWord(command);
    if (numword == 0) return;


    String firstWord = getWordAt(command, 0);
    String secondWord;
    String thirdWord;


    if (numword >= 1) secondWord = getWordAt(command, 1);
    if (numword >= 2) thirdWord = getWordAt(command, 2);


    if (compareString(firstWord, "DAFTAR")){
        Daftar(app);
    } else if (compareString(firstWord, "MASUK")) {
        Masuk(app);
    } else if (compareString(firstWord, "KELUAR")) {
        Keluar(app);
    } else if (compareString(firstWord, "DEVTOOLS")) {
        /**
         * Command Developer Tools akan dihilangkan saat pengumpulan, ini hanya alat untuk debugging.
        */
       DevTools(*app);
    } else if (compareString(firstWord, "TUTUP_PROGRAM")) {
        TutupProgram(app, finish);
    } else if (compareString(firstWord, "GANTI_PROFIL")) {
        GantiProfil(app);
    } else if (compareString(firstWord, "LIHAT_PROFIL")) {
        LihatProfil(app, secondWord);
    }
    
    else {
        printf("\nTidak ada perintah ");
        displayString(command);
        printf(". Berikut full list dari perintah peintah yang disediakan.\n");
        printf("1. DAFTAR\n");
        printf("2. MASUK\n");
        printf("3. KELUAR\n");
        printf("4. TUTUP_PROGRAM\n");
    }

}



int main()
{
    String command;
    createEmptyString(&command, 50);

    Application app;
    START();


    // 1. Inisialisasi
    AppInitialization(&app);

    boolean finish = false;
    while (!finish) {
        // 2. Perintah
        printf("\n>> ");
        readString(&command, 50);

        handleCommand(&app, command, &finish);
    }
    CLOSE();
    return 0;
}

