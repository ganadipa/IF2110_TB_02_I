#include <stdio.h>
#include "../lib/lib.h"

int main()
{
    String command;
    createEmptyString(&command, 1000);

    Application app;
    START();

    // 1. Inisialisasi
    AppInitialization(&app);

    boolean finish = false;
    while (!finish) {
        // 2. Perintah
        printf("\n>> ");
        readString(&command, 1000);

        handleCommand(&app, command, &finish);
    }
    CLOSE();
    return 0;
}

