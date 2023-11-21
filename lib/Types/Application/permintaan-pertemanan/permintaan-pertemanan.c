#include "permintaan-pertemanan.h"
#include <stdio.h>

void TambahTeman(Application *app)
{
    Graf *friendships = &FRIENDSHIPS(*app);
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    String s;
    ListUser *l = &LISTUSER(*app);

    int friendReq = lengthRequestQueue(FRIEND_REQUEST(ELMT_LISTUSER(*l, LOGINID(*app))));
    
    if (friendReq > 0) {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.");
        return;
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
    if (CONNECTED(*friendships, idTeman, LOGINID(*app)))
    {
        printf("Anda sudah berteman kepada dia.");
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


// void BatalTambahTeman(Application *app)

// {
//     if (!LOGGEDIN(*app)) {
//         printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
//         return;
//     }


//     String s;
//     printf("\nMasukkan nama pengguna: \n");
//     readString(&s, 20);

//     ListUser *l = &LISTUSER(*app);
//     int idTeman = searchByName(*l, s);
//     User *targetUser = &ELMT_LISTUSER(*l, idTeman);

//     int idx = getIndex_RequestQueue(FRIEND_REQUEST(*targetUser), LOGINID(*app));
//     if (idx == IDX_UNDEF) {
//         printf(
//             "Anda belum mengirimkan permintaan pertemanan kepada "
//         );
//         displayString(s);
//         return;
//     }

//     removeElmt_RequestQueue(&FRIEND_REQUEST(*targetUser), idx);
//     printf("Permintaan pertemanan kepada ");
//     displayString(s);
//     printf(" telah dibatalkan.");
// }

void DaftarPermintaanPertemanan(Application app)

{
    ListUser l = LISTUSER(app);
    RequestQueue q = FRIEND_REQUEST(ELMT_LISTUSER(l, LOGINID(app)));
    displayRequestQueue(&q, &LISTUSER(app));
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
        displayName(*l, idTeman);
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
