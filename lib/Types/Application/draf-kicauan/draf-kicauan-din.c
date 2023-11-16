#include <stdio.h>
#include "draf-kicauan-din.h"

void SaveDraf(User* user, Kicauan kicau){
    PushDrafDin(&DRAFKICAU(*user), kicau);
}

void ChangeDraf(Application* app, User* user, Kicauan tempKicau){
    String teks;
    printf("Masukkan Perubahan: ");
    readString(&teks, 280);
    setText(&tempKicau, teks); 
    setKicauID(&tempKicau, NEFF(KICAUAN(*app))+1);
    setKicauDateTime(&tempKicau);
    
    SaveDraf(user, tempKicau);
}

void DeleteDraf(User* user, Kicauan* sampahKicau){
    PopDrafDin(&DRAFKICAU(*user), sampahKicau);
}

void ReleaseDraf(Application *app, Kicauan kicau, int IDUSER){
    printKicauan(kicau, ELMT_LISTUSER(LISTUSER(*app), IDUSER).name);
    insertLastListKicau(&KICAUAN(*app), kicau);
    printf("\n Selamat! Draf telah berhasil diterbitkan");
}

void DisplayDraf(Application *app){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    User *user = &ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
    Kicauan temp;
    if(isDrafDinEmpty(DRAFKICAU(*user))){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu dong");
    }
    else{
        int IDUSER = LOGINID(*app);
        PopDrafDin(&DRAFKICAU(*user), &temp);
        setKicauID(&temp, NEFF(KICAUAN(*app)) + 1);
        
        printf("Ini draf terakhir anda\n"); 
        printf("|"); 
        displayString(dateTimeKicau(temp));
        printf("\n|"); 
        displayString(teksKicau(temp));


        printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? ");
        String choose; 

        while(true){
            readString(&choose, 20);

            if(compareString(choose, "UBAH")){
                ChangeDraf(app, user, temp);
                printf("Draf berhasil diubah\n");
                break;
            } else if(compareString(choose, "HAPUS")){
                printf("Draf berhasil dihapus\n");
                break;
            } else if(compareString(choose, "TERBIT")){
                ReleaseDraf(app, temp, IDUSER);
                break;
            } else if(compareString(choose, "KEMBALI")){
                SaveDraf(user, temp);
                break;
            } else{
                printf("\nInput tidak valid");
                printf("\nMasukkan input kembali: ");
            }
        }
    }
}

void CreateDraf(Application *app){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    String teks;
    User *user = &ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
    createEmptyString(&teks, 280);
    printf("Masukkan Draf: ");
    readString(&teks, 280);

    int IDUSER = LOGINID(*app);
    Kicauan value;
    InisialisasiDrafDinKicau(&value, IDUSER);
    setKicauID(&value, NEFF(KICAUAN(*app))+1);
    setKicauDateTime(&value); 
    setText(&value, teks); 

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini? ");
    String choose;
    while(true){
        readString(&choose, 20);
        if(compareString(choose, "SIMPAN")){
            SaveDraf(user, value);
            printf("Draft berhasil disimpan\n");
            break;
        }else if(compareString(choose, "HAPUS")){
            if(!isDrafDinEmpty(DRAFKICAU(*user))){
                printf("Draft berhasil dihapus\n");
                break;
                }
        }else if(compareString(choose, "TERBIT")){
            ReleaseDraf(app, value, IDUSER);
            break;
        }else{
            printf("\nInput tidak valid"); 
            printf("\nMasukkan input kembali: ");
        }
    }
}
