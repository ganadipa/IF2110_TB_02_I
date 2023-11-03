#include <stdio.h>
#include "../lib/lib.h"
#include "../Function/simpan.h"



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

