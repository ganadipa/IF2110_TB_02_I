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
    CreateListKicau(&KICAUAN(*app),1000); //Inisialisasi awal untuk ListKicauan 1000
    CreateDraf(&DRAFKICAU(*app)); //
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
    removeEdge(&FRIENDSHIPS(*app), LOGINID(*app), i); 
}

void Kicau(Application *app){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    String teks;
    printf("Kicauan yang dimasukkan terpotong secara otomatis apabila jumlah karakter lebih dari 280.");
    createEmptyString(&teks, 280);
    printf("Masukkan Kicauan : ");
    readString(&teks, 280);

    int IDUSER = LOGINID(*app);

    KicauanType value;
    InisialisasiKicau(&value, IDUSER);
    setKicauID(&value, NEFF(KICAUAN(*app))+1);
    setKicauDateTime(&value);
    setText(&value, teks);
    insertLastListKicau( &KICAUAN(*app),value);
    printKicauan(value, ELMT_LISTUSER(LISTUSER(*app), IDUSER).name);
}
/**
 * Untuk Add kicauan
*/

boolean isFriend ( Application *app, int CurrentID, int friendID){
    return FRIENDSHIPS(*app).adjacencyMatrix.mem[CurrentID][friendID] == true;
}

String returnUsername (Application app ,int  UserID){
    return ELMT_LISTUSER(LISTUSER(app), UserID).name;
}

void TampilinKicauan(Application *app){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    int i;
    int CurUser = LOGINID(*app);
    for (i = NEFF(KICAUAN(*app)); i >= 0; i--){
        if ( KICAUAN(*app).buffer[i].IDuser == CurUser || isFriend(app, CurUser, KICAUAN(*app).buffer[i].IDuser)){
            printKicauan( KICAUAN(*app).buffer[i], returnUsername(*app,KICAUAN(*app).buffer[i].IDuser ));
        }
    }
}
/**
 * Untuk Menampilkan kicauan berdasarkan Pertemanan dari user
 */

 


void SukaKicauan(Application *app, int ID){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }


    if (LOGINID(*app) == ELMT(KICAUAN(*app), ID - 1).IDuser){
        addLike( &ELMT(KICAUAN(*app) , ID - 1) );
        printKicauan( KICAUAN(*app).buffer[ ID-1 ], returnUsername(*app, KICAUAN(*app).buffer[ID-1].IDuser));
    } else {
        User u = ELMT_LISTUSER(LISTUSER(*app), ELMT(KICAUAN(*app), ID - 1).IDuser);
        if (ISPRIVATE(PROFILE(u))){
            if (isFriend (app, LOGINID(*app), ELMT(KICAUAN(*app), ID - 1).IDuser)){
                addLike( &ELMT(KICAUAN(*app) , ID - 1) );
                printKicauan( KICAUAN(*app).buffer[ ID-1 ], returnUsername(*app, KICAUAN(*app).buffer[ID-1].IDuser));
            } else {
                printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya");
            }
        } else {
            addLike( &ELMT(KICAUAN(*app) , ID - 1) );
            printKicauan( KICAUAN(*app).buffer[ ID-1 ], returnUsername(*app, KICAUAN(*app).buffer[ID-1].IDuser));
        }
    }
}


/**
 * Untuk Menambah jumlah like pada Kicauan dengan id "ID"
*/

void UbahKicauan(Application *app, int ID){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    String teksBaru;
    createEmptyString(&teksBaru, 280);
    readString(&teksBaru, 280);
    if (stringLength(teksBaru) > 280){
        printf("Kicauan yang dimasukkan terpotong secara otomatis dengan jumlah karakter maksimum 280.");
    }

    if (LOGINID(*app) ==ELMT( KICAUAN(*app), ID - 1).IDuser  ){
        setText(&ELMT(KICAUAN(*app), ID - 1), teksBaru);
    }else{
        printf("Kamu hanya bisa mengubah kicauan milikmu sendiri");
    }
}
/**
 * Untuk mengUpdate teks kicauan menjadi yang baru pada Kicauan dengan id "ID"
*/

void drafQuestion(){
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
}

void SimpanDraf(Application *app, Kicauan kicau){
    PushDraf(&DRAFKICAU(*app), kicau);
}

void UbahDraf(Application *app, Kicauan tempKicau){
    String teks;
    printf("Masukkan Perubahan: ");
    readString(&teks, 280);
    setText(&tempKicau, teks); 
    setKicauID(&tempKicau, NEFF(KICAUAN(*app))+1);
    SimpanDraf(app, tempKicau);
}

void HapusDraf(Application *app, Kicauan *sampahKicau){
    PopDraf(&DRAFKICAU(*app), sampahKicau);
}

void TerbitkanDraf(Application *app, Kicauan kicau, int IDUSER){
    printKicauan(kicau, ELMT_LISTUSER(LISTUSER(*app), IDUSER).name);
    insertLastListKicau( &KICAUAN(*app), kicau);
}

void LihatDraf(Application *app){
    Kicauan temp; 
    if(isDrafEmpty(DRAFKICAU(*app))){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu dong");
    }
    else{
        int IDUSER = LOGINID(*app);
        PopDraf(&DRAFKICAU(*app), &temp);
        setKicauID(&temp, NEFF(KICAUAN(*app)) + 1);
        
        printf("Ini draf terakhir anda\n"); 
        printf("|"); 
        displayString(dateTimeKicau(temp));
        printf("\n|"); 
        displayString(teksKicau(temp));

        printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini?");
        String choose; 

        readString(&choose, 20);
        if(compareString(choose, "UBAH")){
            UbahDraf(app, temp);
        } else if(compareString(choose, "HAPUS")){
            if(!isDrafEmpty(DRAFKICAU(*app))){
                printf("Draft berhasil dihapus");
            }
        } else if(compareString(choose, "TERBIT")){
            TerbitkanDraf(app, temp, IDUSER);
        } else if(compareString(choose, "KEMBALI")){
            SimpanDraf(app, temp);
        }
    }
    
}


void BuatDraf(Application *app){

    String teks;
    createEmptyString(&teks, 280);
    printf("Masukkan Draf: ");
    readString(&teks, 280);

    int IDUSER = LOGINID(*app);
    KicauanType value;
    InisialisasiDrafKicau(&value, IDUSER);
    setText(&value, teks); 
    setKicauID(&value, NEFF(KICAUAN(*app))+1);

    drafQuestion(); 
    String choose;
    readString(&choose, 20);
    if(compareString(choose, "SIMPAN")){
        SimpanDraf(app, value);
        printf("Draft berhasil disimpan\n");
    } else if(compareString(choose, "HAPUS")){
        if(!isDrafEmpty(DRAFKICAU(*app))){
            printf("Draft berhasil dihapus\n");
        }
    } else if(compareString(choose, "TERBIT")){
        TerbitkanDraf(app, value, IDUSER);
        printf("Selamat! draf Kicauan telah diterbitkan.\n");
    }
    
    // setKicauDateTime(&value);  TUNGGU DATETIME SELESAI
}


void TambahTeman(Application *app)
{
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    String s;
    ListUser *l = &LISTUSER(*app);

    int friendReq = FRIEND_COUNT(ELMT_LISTUSER(*l, LOGINID(*app)));
    if (friendReq > 0) {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.");
        return;
    } else {
        printf("Tidak terdapat permintaan pertemenan");
    }
    
    printf("\nMasukkan nama pengguna:\n");
    readString(&s, 20);

    int idTeman = searchByName(*l, s);
    if (idTeman == -1) {
        printf("\nPengguna bernama ");
        displayString(s);
        printf(" tidak ditemukan.\n");
        return;
    } else if (idTeman == LOGINID(*app))  {
        printf("\nTidak bisa meminta pertemanan kepada diri sendiri.\n");
        return;
    }


    User* targetUser = &ELMT_LISTUSER(LISTUSER(*app), idTeman);

    int i = getIndex_RequestQueue(FRIEND_REQUEST(*targetUser), LOGINID(*app));
    
    if (i != -1)
    {
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
        displayString(s);
        printf(" Silakan tunggu hingga permintaan Anda disetujui.");
        return;
    }
    
    Friend f;
    f.userID = LOGINID(*app);
    f.friendCount = FRIEND_COUNT(ELMT_LISTUSER(*l, LOGGEDIN(*app)));

    RequestQueue *q = &FRIEND_REQUEST(*targetUser);
    enqueueRequestQueue(q, f);

    printf("\nPermintaan pertemanan kepada ");
    displayString(s);
    printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.");
}


void BatalTambahTeman(Application *app)

{
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }


    String s;
    printf("\nMasukkan nama pengguna: \n");
    readString(&s, 20);

    ListUser *l = &LISTUSER(*app);
    int idTeman = searchByName(*l, s);
    User *targetUser = &ELMT_LISTUSER(*l, idTeman);

    int idx = getIndex_RequestQueue(FRIEND_REQUEST(*targetUser), LOGINID(*app));
    if (idx == IDX_UNDEF) {
        printf(
            "Anda belum mengirimkan permintaan pertemanan kepada "
        );
        displayString(s);
        return;
    }

    removeElmt_RequestQueue(&FRIEND_REQUEST(*targetUser), idx);
    printf("Permintaan pertemanan kepada ");
    displayString(s);
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

    if (!lengthRequestQueue(*q)) {
        printf("Belum ada yang mengajak Anda berteman.");
        return;
    }

    Friend f;
    dequeueRequestQueue(q, &f);

    int idTeman = ID_REQQUEUE(f);
    User *u = &ELMT_LISTUSER(*l, idTeman);

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
        addEdge(&FRIENDSHIPS(*app), idTeman, LOGINID(*app));
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
        printf("\n\n");
    }
}
