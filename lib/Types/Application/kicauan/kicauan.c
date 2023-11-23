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
    // printf("%d\n", CAPACITY(KICAUAN(*app)) );
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
        boolean allSpace = isAllSpace(teksBaru);
        while (allSpace)
        {
            printf("Kicauan tidak boleh hanya spasi\n");
            printf("Ulang masukkan kicauan : ");
            readString(&teksBaru, 280);
            allSpace = isAllSpace(teksBaru);
        }
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

    boolean allSpace = isAllSpace(teks);
    while (allSpace)
    {
        printf("Kicauan tidak boleh hanya spasi\n");
        printf("Ulang masukkan kicauan : ");
        readString(&teks, 280);
        allSpace = isAllSpace(teks);
    }

    KicauanType value;
    InisialisasiKicau(&value, IDUSER);
    setKicauID(&value, NEFF(KICAUAN(*app))+1);
    setKicauDateTime(&value);
    setText(&value, teks);

    insertLastListKicau( &KICAUAN(*app),value);
    // UNTUK TAGAR;
    String TAGAR;
    printf("Masukkan tagar (maks 280 karakter) : ");
    readString(&TAGAR,280);
    printKicauan(value, ELMT_LISTUSER(LISTUSER(*app), IDUSER).name);
    insertKicauankeTable( &(*app).hashMap, TAGAR, &ELMT(   KICAUAN(*app),  NEFF(KICAUAN(*app))-1   ));
    // String namaa = {"GANA", 20};
    // printKicauan(*(*app).hashMap[63].kicauan, namaa);
    // displayString((*app).hashMap[63].tagar);
}

void cariKicauanDenganTagar(Application *app, String Tagar){
    unsigned long long int index = hashFunction(Tagar);
    // printf("%d\n", index);
    unsigned long long int i = index;
    // displayString((*app).hashMap[i].tagar);
    // String namaa = {"GANA", 20};
    // printKicauan(*(*app).hashMap[63].kicauan, namaa);
    
    // printf("hello\n");
    if (isStringInsensitivelyEqual( (*app).hashMap[i].tagar, Tagar)) {
        // printf("sampai sini 1\n");
        int iduser = (*app).hashMap[i].kicauan->IDuser;
        // printf("done here\n");
        String nama = returnUsername(*app, (*app).hashMap[i].kicauan->IDuser);
        // printf(" | Tagar : \n");
        // printKicauan(*(*app).hashMap[i].kicauan, nama);
        printf("\n");
        printf(" Detail Kicauan :");
        printf("\n| ID = %d", IDKicau(*(*app).hashMap[i].kicauan));
        printf("\n| ");
        displayString(nama);
        printf("\n| ");
        displayString(dateTimeKicau(*(*app).hashMap[i].kicauan));
        printf("\n| ");
        displayString((*app).hashMap[i].tagar);
        printf("\n| ");
        displayString(teksKicau(*(*app).hashMap[i].kicauan));
        printf("\n| Disukai : %d\n", likeKicau(*(*app).hashMap[i].kicauan));
        printf("\n");
        return;
        }
    i++;
    // printf("sampai sini 2\n");
    while ((*app).hashMap[index].isOccupied && i != index)
    {
        if (isStringEqual((*app).hashMap[i].tagar, Tagar))
        {
            String nama = returnUsername(*app, (*app).hashMap[i].kicauan->IDuser);
            // printf("\n");
            // printf(" Detail Kicauan :");
            // printf("\n| ID = %d", IDKicau(*(*app).hashMap[i].kicauan));
            printf("\n| ");
            displayString(nama);
            printf("\n| ");
            displayString(dateTimeKicau(*(*app).hashMap[i].kicauan));
            printf("\n| ");
            displayString((*app).hashMap[i].tagar);
            printf("\n| ");
            displayString(teksKicau(*(*app).hashMap[i].kicauan));
            printf("\n| Disukai : %d\n", likeKicau(*(*app).hashMap[i].kicauan));
            printf("\n");
            return;
        }
        i = (i + 1) % TABLE_SIZE;
    }
    printf("Tidak ditemukan kicauan dengan tagar tersebut!\n");
}