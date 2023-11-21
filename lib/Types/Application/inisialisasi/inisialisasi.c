#include <stdio.h>
#include "inisialisasi.h"
#include "../../../ADT/WordMachine/charmachinefile.h"

String pathfilefolder;
void AppInitialization(Application *app)
    /**
     * I.S. Program baru dimulai.
     * F.S. Output UI CLI dan menampung data-data yang ada pada config yang telah dimasukkan.
    */
{
    // print opening
    Opening();

    
    CreateListUser(&LISTUSER(*app)); 
    CreateGraph(&FRIENDSHIPS(*app));
    CreateListKicau(&KICAUAN(*app), 1000);

    boolean found = false;
    // Setup(app); // Hapus kali udah ada database dari config.

    ReadConfig(app, &found);
    if (pitafile == NULL){
        printf("Folder tidak berhasil dimuat, jadi bikin baru\n");
    }
    LOGGEDIN(*app) = false;
    LOGINID(*app) = ID_UNDEF;
    // Inisialisasi app
     
}

void Opening() 
{
    
    printf(".______    __    __  .______      .______    __  .______   \n");   
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\    \n" );
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|     \n\n");

    printf("Selamat datang di BurBir. \n\n");

    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    readString(&pathfilefolder, 351);

}



void Setup(Application *app)
{
    LOGGEDIN(*app) = false;
    LOGINID(*app) = ID_UNDEF;
    JUMLAHUTAS(*app) = 0;
    CreateListUser(&LISTUSER(*app)); 
    CreateGraph(&FRIENDSHIPS(*app));
    CreateListKicau(&KICAUAN(*app), 1000); //Inisialisasi awal untuk ListKicauan 1000
}

void ReadConfig(Application *app, boolean *found) {
    LoadPengguna(app, pathfilefolder);
    if(EndFile){
        return;
    }
    LoadKicauan(app, pathfilefolder);
    LoadBalasan(app, pathfilefolder);
    LoadDraft(app, pathfilefolder);
    LoadUtas(app, pathfilefolder);
    
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");
}

