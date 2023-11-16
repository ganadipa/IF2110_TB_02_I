#include <stdio.h>
#include "kicauan.h"

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
    for (i = NEFF(KICAUAN(*app))-1 ; i >=  0; i--){
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
    if ( KICAUAN(*app).nEff < ID ){
        printf("Tidak ditemukan kicauan dengan ID = %d\n", ID);
        return;
    }
    if (ID <1){
        printf("Kamu tidak bisa menyukai Kicauan dengan id kicau %d", ID);
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
                printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
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
    if (ID <1){
        printf("Kamu tidak bisa mengubah Kicauan dengan id kicau %d", ID);
        return;
    }
    // printf("%d %d\n", KICAUAN(*app).nEff,ID); //DEBUGGING
    if ( (KICAUAN(*app).nEff) < ID ){
        printf("Tidak ditemukan kicauan dengan ID = %d\n", ID);
        return;
    }
    if (LOGINID(*app) ==ELMT( KICAUAN(*app), ID - 1).IDuser  ){
        String teksBaru;
        createEmptyString(&teksBaru, 280);
        printf("Kicauan yang dimasukkan terpotong secara otomatis apabila jumlah karakter lebih dari 280.\n");
        printf("Masukkan Kicauan : ");
        readString(&teksBaru, 280);
        setText(&ELMT(KICAUAN(*app), ID - 1), teksBaru);
    }else{
        printf("Kamu hanya bisa mengubah kicauan milikmu sendiri\n");
    }
}

void Kicau(Application *app) {
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    String teks;
    printf("\nKicauan yang dimasukkan terpotong secara otomatis apabila jumlah karakter lebih dari 280.\n");
    printf("\nMasukkan Kicauan : ");
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