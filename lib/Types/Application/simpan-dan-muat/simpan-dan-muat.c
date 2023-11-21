#include <stdio.h>
#include "../inisialisasi/inisialisasi.h"

void MuatFolder(Application *app, String pathfilefolder){
    CreateListUser(&LISTUSER(*app)); 
    CreateGraph(&FRIENDSHIPS(*app));
    CreateListKicau(&KICAUAN(*app), 1000);
    LoadPengguna(app, pathfilefolder);
    if(EndFile){
        printf("Tidak ada folder yang dimaksud!");
        return;
    }
    LoadKicauan(app, pathfilefolder);
    LoadBalasan(app,pathfilefolder);
    LoadDraft(app, pathfilefolder);
    LoadUtas(app, pathfilefolder);
    deleteRest(&pathfilefolder);
    printf("Anda akan melakukan pemuatan dari %s.\n", pathfilefolder.buffer);
    printf("Mohon tunggu...\n");
    printf("1...\n");
    printf("2...\n");
    printf("3...\n");
    printf("Pemuatan selesai!\n");
    LOGGEDIN(*app) = false;
    LOGINID(*app) = ID_UNDEF;
}