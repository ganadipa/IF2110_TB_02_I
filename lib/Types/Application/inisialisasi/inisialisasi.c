#include <stdio.h>
#include "inisialisasi.h"

void AppInitialization(Application *app)
    /**
     * I.S. Program baru dimulai.
     * F.S. Output UI CLI dan menampung data-data yang ada pada config yang telah dimasukkan.
    */
{
    // print opening
    Opening();
    boolean found = false;
    ReadConfig(app, &found);
    // Inisialisasi app
    Setup(app); // Hapus kali udah ada database dari config.
     
}

void Opening() 
{
    
    printf(".______    __    __  .______      .______    __  .______   \n");   
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\    \n" );
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|     \n\n");

    printf("Selamat datang di BurBir. \n\n");

    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");

}



void Setup(Application *app)
{
    LOGGEDIN(*app) = false;
    LOGINID(*app) = ID_UNDEF;
    CreateListUser(&LISTUSER(*app)); 
    CreateGraph(&FRIENDSHIPS(*app));
    CreateListKicau(&KICAUAN(*app), 1000); //Inisialisasi awal untuk ListKicauan 1000
}

void ReadConfig(Application *app, boolean *found) {
    do {
        // use library


        // if folder is found
        *found = true;
    } while (!*found);
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");


}
