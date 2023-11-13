#include <stdio.h>
#include "balasan.h"

void Balas(Application *app, int IDKicau, int IDBalasan) {
    Kicauan *k = &KICAUAN(*app).buffer[IDKicau-1];
    ReplyTree *balasan = &BALASAN(*k);

    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    if (IDKicau > KICAUAN(*app).nEff) {
        printf("\nWah tidak terdapat kicauan yang ingin Anda balas! Mungkin typo IDKicau ?\n");
        return;
    }



    // while (IDBalasan != -1) printf("hello");
    int idx = getIdxFromReplyId(*balasan, IDBalasan);
    if ((idx == -1 && IDBalasan != -1) && !ISUSED(*balasan, IDBalasan)) {
        printf("\nWah, tidak terdapat balasan yang ingin Anda balas! Mungkin typo IDBalasan ?\n");
        return;
    }


    int userId = userKicau(KICAUAN(*app).buffer[IDKicau]);
    ListUser *lu = &LISTUSER(*app);


    if (ISPRIVATE(PROFILE(ELMT_LISTUSER(*lu, userId)))) {
        printf("\nWah akun tersebut merupakan akun privat dan Anda belum berteman dengan akun tersebut! \n");
        return;
    }

    String body;
    boolean mainReply = false;
    
    if (IDBalasan == -1) mainReply = true;

    // initial
    printf("\nMasukkan balasan:\n");
    readString(&body, 350);

    // proses

    ReplyAddress ra = newReply(body, mainReply);
    REPLYID(*ra) = generateReplyID(*balasan);
    AUTHORID(*ra) = LOGINID(*app);


    addReply(balasan);

    if (mainReply) addMainReply(balasan, ra);
    else {
        ReplyAddress parent = getReplyAddress(*balasan, IDBalasan);
        addChildToReply(balasan, parent, ra);
    }





    // penutup
    printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");
    displayReply(*balasan, ra, lu, 0, LOGINID(*app));
    printf("\n");



}

void Balasan(Application *app, int IDKicau){
    Kicauan *k = &KICAUAN(*app).buffer[IDKicau-1];
    ReplyTree *balasan = &BALASAN(*k);
    int userID = userKicau(*k);
    ListUser *lu = &LISTUSER(*app);

    if (IDKicau > KICAUAN(*app).nEff) {
        printf("\nWah tidak terdapat kicauan dengan ID tersebut! Mungkin typo IDKicau ?\n");
        return;
    }

    if (NUMREP(*balasan) == 0 || NUMREP(*balasan) == 0) {
        printf("\nBelum terdapat balasan apapun pada kicauan tersebut. Be the first one to break the silence!\n");
    }

    if (ISPRIVATE(PROFILE(ELMT_LISTUSER(*lu, userID)))){
        printf("\nWah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
    }

    displayAllReply(*balasan, *lu, LOGINID(*app));
}

void HapusBalasan(Application *app, int IDKicau, int IDBalasan){
    Kicauan *k = &KICAUAN(*app).buffer[IDKicau-1];
    ReplyTree *balasan = &BALASAN(*k);
    ReplyAddress rep = ADDR(LISTREP(*balasan), IDBalasan);



    int userID = userKicau(*k);
    ListUser *lu = &LISTUSER(*app);

    int idx = getIdxFromReplyId(*balasan, IDBalasan);
    if (idx == -1) {
        printf("\nBalasan tidak ditemukan.\n");
        return;
    }
    
    if (AUTHORID(*rep) != LOGINID(*app)) {
        printf("\nHei, ini balasan punya siapa? Jangan dihapus ya!\n");
        return;
    }

    // ISUSED(*balasan, IDBalasan) = 0;
    deleteReply(balasan, IDBalasan);
    printf("\nBalasan berhasil dihapus.\n");
}