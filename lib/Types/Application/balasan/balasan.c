#include <stdio.h>
#include "balasan.h"

void Balas(Application *app, int IDKicau, int IDBalasan) {
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    if (IDKicau > KICAUAN(*app).nEff) {
        pritnf("\nWah tidak terdapat kicauan yang ingin Anda balas! Mungkin typo IDKicau ?\n");
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

    Kicauan *k = &KICAUAN(*app).buffer[IDKicau-1];
    ReplyTree *balasan = &BALASAN(*k);
    
    if (IDBalasan == -1) mainReply = true;

    // initial
    printf("\nMasukkan balasan:\n");
    readString(&body, 350);

    // proses
    addReply(balasan);


    ReplyAddress ra = newReply(body, mainReply);
    REPLYID(*ra) = generateReplyID(*balasan);
    AUTHORID(*ra) = LOGINID(*app);





    printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");




}