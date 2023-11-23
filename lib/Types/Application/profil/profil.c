#include "profil.h"
#include <stdio.h>

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

    if (CanSee(&LISTUSER(*app),ID, LOGGEDIN(*app), &FRIENDSHIPS(*app))) {
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