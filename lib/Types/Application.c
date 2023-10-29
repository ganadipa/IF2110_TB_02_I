#include <stdio.h>
#include "./Application.h"

void AppInitialization(Application *app)
    /**
     * I.S. Program baru dimulai.
     * F.S. Output UI CLI dan menampung data-data yang ada pada config yang telah dimasukkan.
    */
{

    printf(".______    __    __  .______      .______    __  .______   \n");   
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\    \n" );
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|     \n\n");

    printf("Selamat datang di BurBir. \n\n");

    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");

    boolean found = false;
    do {
        // use library


        // if folder is found
        found = true;
    } while (!found);

    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");




}

void Daftar(Application *app)
/**
 * I.S. app sudah terinisialisasi.
 * F.S. Menambahkan user ke dalam database.
*/
{
    String name;
    createEmptyString(&name, 350);

    String password;
    createEmptyString(&password, 350);


    printf("\nMasukkan nama:\n");
    readString(&name, 350);

    int i = searchByName(ListUser(*app), name);
    while (i != -1) {
        printf("Wah, sayang sekali nama tersebut telah diambil.\n");

        printf("\nMasukkan nama:\n");
        readString(&name, 350);
    }

    printf("\nMasukkan kata sandi:\n");
    readString(&password, 350);

    User u;
    initializeUser(&u, name, password, LENGTH_LISTUSER(ListUser(*app)));
    insertLast_ListUser(&ListUser(*app), u);

    printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    

}