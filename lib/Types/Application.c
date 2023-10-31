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



    // Inisialisasi app
    LOGGEDIN(*app) = false;
    LOGINID(*app) = ID_UNDEF;
    CreateListUser(&LISTUSER(*app)); 
    CreateGraph(&FRIENDSHIPS(*app), 20);




}

void Daftar(Application *app)
/**
 * I.S. app sudah terinisialisasi.
 * F.S. Menambahkan user ke dalam database.
*/
{
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
    insertLast_ListUser(&LISTUSER(*app), u);

    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n\n");
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

        int i = searchByName(LISTUSER(*app), name);
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

void GantiProfil(Application *app)

{
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    User* u = &ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
    displayProfile(*u);

    printf("\nMasukkan Bio Akun: \n");
    readBio(&PROFILE(*u), 135);

    printf("\nMasukkan No HP:\n");
    readPhoneNumber(&PROFILE(*u));

    printf("\nMasukkan Weton:\n");
    readWeton(&PROFILE(*u));

    printf("\nProfil Anda telah berhasil diperbarui!\n");
}

void LihatProfil(Application *app, String name) {
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    int ID = searchByName(LISTUSER(*app), name);
    User u = ELMT_LISTUSER(LISTUSER(*app), ID);

    if (ISPRIVATE(PROFILE(u))) {
        printf("\nWah, akun ");
        displayString(name);
        printf("diprivat nih. Ikuti dulu yuk untuk bisa melihat profil Tuan Prim!\n");
        return;
    } else {
        displayProfile(u);
        printf("\nFoto Profil:\n");
        displayPhoto(FOTO(PROFILE(u)));
        printf("\n");
    }
}

void AturJenisAkun(Application *app)

{

    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }


    User* u = &ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
    boolean *isPrivate = &ISPRIVATE(PROFILE(*u));


    printf("Saat ini, akun Anda adalah akun ");
    if (!*isPrivate) printf("publik");
    else printf("privat");
    printf(". Ingin mengubah ke akun ");
    if (*isPrivate) printf("publik");
    else printf("privat");
    printf("? (YA/TIDAK)");

    String ans;
    readString(&ans, 10);

    if (compareString(ans, "YA")) {
        *isPrivate = !*isPrivate;
    } else if (compareString(ans, "TIDAK")) {
        // do nothing
    } else {
        printf("Masukkan Anda bukan berupa \"YA\" atau \"TIDAK\". Perintah dibatalkan.");
    }
    
}

void UbahFotoProfil(Application *app) {
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    User* u = &ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
    Photo* p = &FOTO(PROFILE(*u));

    printf("Foto profil Anda saat ini adalah: \n");
    displayPhoto(*p);

    printf("Masukkan foto profil yang baru: \n");
    readPhoto(p);

    printf("Foto profil Anda sudah berhasil diganti!.");


}

void DaftarTeman(Application app) {
    if (!LOGGEDIN(app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    ListUser l = LISTUSER(app);
    int length = LENGTH_LISTUSER(LISTUSER(app));
    int k = 0;

    int numFriends =  countConnections(FRIENDSHIPS(app), LOGINID(app));
    if (numFriends == 0) {
        printf("\n");
        displayName(l, LOGINID(app));
        printf("belum memiliki teman.\n");
    } else {

        displayName(l, LOGINID(app));
        printf("memiliki %d teman:\n", numFriends);
        for (k = 0; k < length; k++) {
            if (CONNECTED(FRIENDSHIPS(app), k, LOGINID(app)) == true) {
                printf(" | ");
                displayName(l, k);
                printf("\n");
            }
        }
    }
}

void HapusTeman(Application *app) {
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    String name;
    createEmptyString(&name, 350);
    printf("Masukkan nama pengguna: \n");
    readString(&name, 350);

    int i = searchByName(LISTUSER(*app),name);
    if (i == IDX_UNDEF) {
        printf("\n");
        displayString(name);
        printf(" bukan teman Anda.");
        return ;
    }
     
    String ans;
    printf("\nApakah anda yakin ingin menghapus ");
    displayString(name);
    printf(" dari daftar teman Anda? (YA/TIDAK)");
    readString(&ans, 10);

    if (compareString(ans, "TIDAK")) {
        printf("\nPenghapusan teman dibatalkan\n");
        return;
    } 
    
    // Pemotongan hubungan pertemanan antara current user dengan "name".
    cutEdge(&FRIENDSHIPS(*app), LOGINID(*app), i); 
}

void DevTools(Application app) 

{
    printf("\nOops fitur ini belum dibuat.\n");
}