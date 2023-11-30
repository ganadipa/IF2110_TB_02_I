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

    if (ID == -1) {
        printf("\nTidak ditemukan akun tersebut.\n");
        return;
    }


    if (!CanSee(&LISTUSER(*app), ID, LOGINID(*app), &FRIENDSHIPS(*app))) {
        printf("\nWah, akun ");
        displayString(name);
        printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
        displayString(name);
        printf(" !\n");

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


    printf("\nSaat ini, akun Anda adalah akun ");
    if (!*isPrivate) printf("publik");
    else printf("privat");
    printf(". Ingin mengubah ke akun ");
    if (*isPrivate) printf("publik");
    else printf("privat");
    printf("? (YA/TIDAK)");

    String ans;
    readString(&ans, 10);
    printf("\n");

    if (compareString(ans, "YA")) {
        printf("Akun berhasil diganti.\n");
        *isPrivate = !*isPrivate;
    } else if (compareString(ans, "TIDAK")) {
        printf("Akun tidak berhasil diganti.\n");
    } else {
        printf("Masukkan Anda bukan berupa \"YA\" atau \"TIDAK\". Perintah dibatalkan.\n");
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