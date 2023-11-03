
#include <stdio.h>
#include "draf-kicauan.h"


void SimpanDraf(Application *app, Kicauan kicau){
    PushDraf(&DRAFKICAU(*app), kicau);
}

void UbahDraf(Application *app, Kicauan tempKicau){
    String teks;
    printf("Masukkan Perubahan: ");
    readString(&teks, 280);
    setText(&tempKicau, teks); 
    setKicauID(&tempKicau, NEFF(KICAUAN(*app))+1);
    setKicauDateTime(&tempKicau);
    
    SimpanDraf(app, tempKicau);
}

void HapusDraf(Application *app, Kicauan *sampahKicau){
    PopDraf(&DRAFKICAU(*app), sampahKicau);
    printf("\nDraf berhasil diubah");
}

void TerbitkanDraf(Application *app, Kicauan kicau, int IDUSER){
    printKicauan(kicau, ELMT_LISTUSER(LISTUSER(*app), IDUSER).name);
    insertLastListKicau( &KICAUAN(*app), kicau);
    printf("\n Selamat! Draf telah berhasil diterbitkan");
}

void LihatDraf(Application *app){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
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

        printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? ");
        String choose; 

        readString(&choose, 20);
        while(true){
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
            } else{
                printf("\nInput tidak valid");
            }
        }
    }
}


void BuatDraf(Application *app){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    String teks;
    createEmptyString(&teks, 280);
    printf("Masukkan Draf: ");
    readString(&teks, 280);

    int IDUSER = LOGINID(*app);
    Kicauan value;
    InisialisasiDrafKicau(&value, IDUSER);
    setKicauID(&value, NEFF(KICAUAN(*app))+1);
    setKicauDateTime(&value); 
    setText(&value, teks); 

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini? ");
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
    }
}