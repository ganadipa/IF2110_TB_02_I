#include "pengguna.h"
#include <stdio.h>

void Daftar(Application *app)
/**
 * I.S. app sudah terinisialisasi.
 * F.S. Menambahkan user ke dalam database.
*/
{
    if (LOGGEDIN(*app)) {
        printf("\nAnda sudah punya akun!!! Keluar terlebih dahulu untuk membuat akun yang lain.\n");
        return;
    }

    String name;
    createEmptyString(&name, 20);

    String password;
    createEmptyString(&password, 20);

    // Check whether if ListUser is full or not
    if (isFull_ListUser(LISTUSER(*app))) {
        printf("\nOops... Jumlah pengguna sudah mencapai 20. Tidak bisa melakukan pendaftaran lagi.\n");
        return;
    }

    // Get name with handle maximum length.
    printf("\nMasukkan nama:\n");
    readString(&name, 350);
    while (stringLength(name) > 20) {
        printf("\nMaaf, nama dan password maksimal 20 karakter. Ulangi.\n");
        printf("\nMasukkan nama:\n");
        readString(&name, 350);
    }


    // Handle retry when the name is taken
    int i = searchByName(LISTUSER(*app), name);
    while (i != -1) {
        printf("\nWah, sayang sekali nama tersebut telah diambil.\n");

        // Get name with handle maximum length.
        printf("\nMasukkan nama:\n");
        readString(&name, 350);
        while (stringLength(name) > 20) {
            printf("\nMaaf, nama dan password maksimal 20 karakter. Ulangi.\n");
            printf("\nMasukkan nama:\n");
            readString(&name, 350);
        }

        i = searchByName(LISTUSER(*app), name);
    }

    // Get password with handle maximum length.
    printf("\nMasukkan kata sandi:\n");
    readString(&password, 350);
    while (stringLength(password) > 20) {
        printf("\nMaaf, nama dan password maksimal 20 karakter. Ulangi.\n");
        printf("\nMasukkan kata sandi:\n");
        readString(&password, 350);
    }

    // Initialize user with the given name and password, insert it to database.
    User u;
    initializeUser(&u, name, password, LENGTH_LISTUSER(LISTUSER(*app)));
    addUser(&DSU(*app), LENGTH_LISTUSER(LISTUSER(*app)));
    insertLast_ListUser(&LISTUSER(*app), u);
    addVertices(&FRIENDSHIPS(*app));

    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
}

void Masuk(Application *app)
/**
 * I.S. app sudah terinisialisasi.
 * F.S. Jika belum login, tampilkan menu untuk login.
 *          Jika berhasil login, loginID ter-set dan isLoggedIn menjadi true;
 *      Jika sudah login, tampilkan pesan bahwa sudah login. 
*/
{
    if (LOGGEDIN(*app)) {
        printf("\nWah Anda sudah masuk. Keluar dulu yuk!\n");
        return;
    }

    if (LENGTH_LISTUSER(LISTUSER(*app)) == 0){
        printf("\nAnda belum mendaftarkan akun.\n");
        return;
    }

    String name;
    createEmptyString(&name, 350);

    String password;
    createEmptyString(&name, 350);

    // Read user input name.
    printf("\nMasukkan nama:\n");
    readString(&name, 350);

    // Handle reinput name
    int i = searchByName(LISTUSER(*app), name);
    while (i == -1) {
        printf("\nWah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");

        // Read user input name.
        printf("\nMasukkan nama:\n");
        readString(&name, 350);

        i = searchByName(LISTUSER(*app), name);
    }

    // Read user input password.
    printf("\nMasukkan kata sandi:\n");
    readString(&password, 350);

    // Handle reinput password
    String passwordReference = PW(ELMT_LISTUSER(LISTUSER(*app), i));
    while (!isStringEqual(password, passwordReference)) {
        printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");

        // Read user input password.
        printf("\nMasukkan kata sandi:\n");
        readString(&password, 350);
    }


    // Handle successfully logged in.
    LOGGEDIN(*app) = true;
    LOGINID(*app) = i;



    printf("\nAnda telah berhasil masuk dengan nama pengguna ");
    displayString(ELMT_LISTUSER(LISTUSER(*app), i).name);
    printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
}

void Keluar(Application *app) 

{
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    LOGGEDIN(*app) = false;
    LOGINID(*app) = ID_UNDEF;
}

void TutupProgram(Application *app, boolean  *finish)

{
    printf("\nAnda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    *finish = true;
}