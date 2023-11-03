#include "teman.h"
#include <stdio.h>

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
        printf("\n");
        displayName(l, LOGINID(app));
        printf(" memiliki %d teman:\n", numFriends);
        for (k = 0; k < length; k++) {
            if (LOGINID(app) == k) continue;

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