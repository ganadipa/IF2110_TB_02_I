#include <stdio.h>
#include "../lib/lib.h"

int main()
{
    String command;
    createEmptyString(&command, 50);

    Application app;
    START();
    // 1. Inisialisasi
    AppInitialization(&app);

    
    while (true) {
        // 2. Perintah
        printf(">> ");
        readString(&command, 50);

        if (compareString(command, "DAFTAR")){
            Daftar(&app);
         }
        //   else if (compareString(command, "MASUK")) {
        //     Masuk(&app);
        // }

    }
    CLOSE();
    return 0;
}