
#include <stdio.h>
#include "draf-kicauan.h"

void SimpanDraf(User* user, Kicauan kicau){
    PushDraf(&DRAFKICAU(*user), kicau);
}

void LihatDraf(Application *app){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    User *user = &ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
    Kicauan temp;
    if(isDrafEmpty(DRAFKICAU(*user))){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu dong");
    }
    else{
        int IDUSER = LOGINID(*app);
        PopDraf(&DRAFKICAU(*user), &temp);
        setKicauID(&temp, NEFF(KICAUAN(*app)) + 1);
        
        printf("Ini draf terakhir anda\n"); 
        printf("|"); 
        displayString(dateTimeKicau(temp));
        printf("\n|"); 
        displayString(teksKicau(temp));

        printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini?");
        String choose; 

        readString(&choose, 20);

        // if(compareString(choose, "UBAH")){
        //     UbahDraf(app, user, temp);
        // } else if(compareString(choose, "HAPUS")){
        //     printf("Draf berhasil dihapus\n");
        // } 
        // else if(compareString(choose, "TERBIT")){
        //     TerbitkanDraf(app, temp, IDUSER);
        // } 
        // else if(compareString(choose, "KEMBALI")){
        //     SimpanDraf(&user, temp);
        // } else{
        //     printf("\nInput tidak valid");
        // }
    }
}

// void UbahDraf(Application *app, User user, Kicauan tempKicau){
//     String teks;
//     printf("Masukkan Perubahan: ");
//     readString(&teks, 280);
//     setText(&tempKicau, teks); 
//     setKicauID(&tempKicau, NEFF(KICAUAN(*app))+1);
//     setKicauDateTime(&tempKicau);
    
//     SimpanDraf(*user, tempKicau);
// }

// void HapusDraf(User* user, Kicauan *sampahKicau){
//     PopDraf(&DRAFKICAU(*user), sampahKicau);
//     printf("\nDraf berhasil diubah");
// }

// void TerbitkanDraf(Application *app, Kicauan kicau, int IDUSER){
//     User user = ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
//     printKicauan(kicau, ELMT_LISTUSER(LISTUSER(*app), IDUSER).name);
//     insertLastListKicau(&KICAUAN(*app), kicau);
//     printf("\n Selamat! Draf telah berhasil diterbitkan");
// }



void BuatDraf(Application *app){
    User user = ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
    displayProfile(user);
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

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
    String choose;
    readString(&choose, 20);
    if(compareString(choose, "SIMPAN")){
        SimpanDraf(&user, value);
        displayString(value.dateTime);
        printf("Draft berhasil disimpan\n");
        }
    // } else if(compareString(choose, "HAPUS")){
    //     if(!isDrafEmpty(DRAFKICAU(user))){
    //         printf("Draft berhasil dihapus\n");
    //     }
    // } 
    // else if(compareString(choose, "TERBIT")){
    //     TerbitkanDraf(&user, value, IDUSER);
    // }
}