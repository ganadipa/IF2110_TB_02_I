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
    CreateGraph(&FRIENDSHIPS(*app));




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
    addVertices(&FRIENDSHIPS(*app));

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

        displayString(name);
        printf("\nwith length: %d", stringLength(name));

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
        printf(" belum memiliki teman.\n");
    } else {

        displayName(l, LOGINID(app));
        printf(" memiliki %d teman:\n", numFriends);
        for (k = 0; k < length; k++) {
            if (CONNECTED(FRIENDSHIPS(app), k, LOGINID(app)) == true && k != LOGINID(app)) {
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
    removeEdge(&FRIENDSHIPS(*app), LOGINID(*app), i); 
}

void TambahTeman(Application *app)

{

    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }



    String name;
    ListUser *l = &LISTUSER(*app);

    int numFriendRequest = FRIEND_COUNT(ELMT_LISTUSER(*l, LOGINID(*app)));
    if (numFriendRequest > 0) {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.");
        return;
    }


    
    printf("\nMasukkan nama pengguna:\n");
    readString(&name, 350);

    int idTarget = searchByName(*l, name);
    if (idTarget == -1) {
        printf("\nPengguna bernama ");
        displayString(name);
        printf(" tidak ditemukan.\n");
        return;
    } else if (idTarget == LOGINID(*app))  {
        printf("\nTidak bisa meminta pertemanan kepada diri sendiri.\n");
        return;
    }


    User* targetUser = &ELMT_LISTUSER(LISTUSER(*app), idTarget);

    int i = getIndex_RequestQueue(FRIEND_REQUEST(*targetUser), LOGINID(*app));
    
    if (i != -1)
    {
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
        displayString(name);
        printf(" Silakan tunggu hingga permintaan Anda disetujui.");
        return;
    }
    
    UserID current;
    current.userID = LOGINID(*app);
    current.friendCount = FRIEND_COUNT(ELMT_LISTUSER(*l, LOGGEDIN(*app)));

    RequestQueue *q = &FRIEND_REQUEST(*targetUser);
    enqueue_RequestQueue(q, current);

    printf("\nPermintaan pertemanan kepada ");
    displayString(name);
    printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.");
    
    

}


void BatalTambahTeman(Application *app)

{
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }


    String name;
    printf("\nMasukkan nama pengguna: \n");
    readString(&name, 350);

    ListUser *l = &LISTUSER(*app);
    int idTarget = searchByName(*l, name);
    User *targetUser = &ELMT_LISTUSER(*l, idTarget);

    int idx = getIndex_RequestQueue(FRIEND_REQUEST(*targetUser), LOGINID(*app));
    if (idx == NIL) {
        printf(
            "Anda belum mengirimkan permintaan pertemanan kepada "
        );
        displayString(name);
        return;
    }

    removeElmt_RequestQueue(&FRIEND_REQUEST(*targetUser), idx);
    printf("Permintaan pertemanan kepada ");
    displayString(name);
    printf(" telah dibatalkan.");
}

void DaftarPermintaanPertemanan(Application app)

{
    ListUser l = LISTUSER(app);
    RequestQueue q = FRIEND_REQUEST(ELMT_LISTUSER(l, LOGINID(app)));
    displayRequestQueue(q, LISTUSER(app));
}

void SetujuiPertemanan(Application *app)
{

    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }


    ListUser *l = &LISTUSER(*app);
    RequestQueue *q = &FRIEND_REQUEST(ELMT_LISTUSER(*l, LOGINID(*app)));

    if (!nbElmt_RequestQueue(*q)) {
        printf("Belum ada yang mengajak Anda berteman.");
        return;
    }

    UserID uid;
    dequeque_RequestQueue(q, &uid);

    int idTarget = ID_REQQUEUE(uid);
    User *u = &ELMT_LISTUSER(*l, idTarget);

    printf("\nPermintaan pertemanan teratas dari ");
    displayString(NAME(*u));
    printf("\n");

    printf("\n | Nama: ");
    displayString(NAME(*u));
    printf("\n | Jumlah teman: %d\n", FRIEND_COUNT(*u));

    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");

    String ans;
    readString(&ans, 10);

    if (compareString(ans, "TIDAK")) {
        printf("\nPermintaan pertemanan dari ");
        printf(" telah ditolak.\n");
    } else if (compareString(ans, "YA")) {
        addEdge(&FRIENDSHIPS(*app), idTarget, LOGINID(*app));
        printf("Permintaan pertemanan dari ");
        displayString(NAME(*u));
        printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
        displayString(NAME(*u));
        printf(".\n");
    } else {
        printf("Input tidak diketahui, gagal menyetujui pertemanan.");
    }
}



void DevTools(Application app) 

{



    printf("\nisLoggedIn : ");
    if (LOGGEDIN(app)) {
        printf("TRUE");
        printf("\nLogged in as ");
        displayName(LISTUSER(app), LOGINID(app));
        printf("  (ID : %d)\n", LOGINID(app));
    }
    else printf("FALSE");

    printf("\n\nGraph pertemanan: \n");
    printGraph(FRIENDSHIPS(app));


    printf("\n\nisi ListUser:\n\n");
    int i;
    for (i = 0; i < LENGTH_LISTUSER(LISTUSER(app)); i++) 
    {
        printf("ID : %d", i);
        displayProfile(ELMT_LISTUSER(LISTUSER(app), i));
        displayPhoto(FOTO(PROFILE(ELMT_LISTUSER(LISTUSER(app), i))));
        displayRequestQueue(FRIEND_REQUEST(ELMT_LISTUSER(LISTUSER(app), i)), LISTUSER(app));
        printf("\n\n");
    }
}