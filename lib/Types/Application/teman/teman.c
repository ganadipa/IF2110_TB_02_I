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
        printf(" belum memiliki teman.\n");
    } else {
        printf("\n");
        displayName(l, LOGINID(app));
        printf(" memiliki %d teman:\n", numFriends);
        for (k = 0; k < length; k++) {
            if(LOGINID(app) == k){
                continue;
            }
            
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

    User* u = &ELMT_LISTUSER(LISTUSER(*app), LOGINID(*app));
    if(u->friendCount == 0){
        printf("\nAnda belum mempunyai teman.\n");
        return;
    }

    String name;
    createEmptyString(&name, 350);
    printf("\nMasukkan nama pengguna: \n");
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
    
    if (compareString(ans, "YA")) {
        removeEdge(&FRIENDSHIPS(*app), LOGINID(*app), i); 
        u->friendCount --;
        User *f = &ELMT_LISTUSER(LISTUSER(*app), i);
        f->friendCount --;
        return;
    }
    
    
}

void KelompokTeman(Application *app) {
    DisjointSet* dsu = &DSU(*app);
    int i, count = 0;
    for (i = 0; i < dsu->count; i++) {
        if (i == LOGINID(*app)) {
            continue;
        }

        if (check(dsu, i , LOGINID(*app))){
            count++;
        }
    }

    printf("Terdapat %d orang dalam kelompok teman ", count);
    displayName(LISTUSER(*app), LOGINID(*app));
    printf(" :\n");
    for (i = 0; i < dsu->count; i++) {
        if (i == LOGINID(*app)) {
            continue;
        }

        if (check(dsu, i , LOGINID(*app))){
            printf(" | ");
            displayName(LISTUSER(*app), i);
            printf("\n");
        }
    }
}