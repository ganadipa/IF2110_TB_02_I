#include <stdio.h>
#include "inisialisasi.h"

void AppInitialization(Application *app)
    /**
     * I.S. Program baru dimulai.
     * F.S. Output UI CLI dan menampung data-data yang ada pada config yang telah dimasukkan.
    */
{
    // print opening
    Opening();
    boolean found = false;
    ReadConfig(app, &found);
    // Inisialisasi app
    // Setup(app); // Hapus kali udah ada database dari config.
     
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
    // do {
    //     // use library


    //     // if folder is found
    //     *found = true;
    // } while (!*found);
    LoadPengguna(app);
    LoadKicauan(app);
    // LoadBalasan(app);
    LoadUtas(app);
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");


}

void LoadPengguna(Application *app){
    String filename = {"pengguna.config", 20};
    int i,j;
    String photoString;
    createEmptyString(&photoString, 225);
    STARTWORDFILE(filename);
    if (retvalfile != -1){
        app->users.length = stringToInt(currentWordFile);
        if(app->users.length > 0){
            for (i=0; i < app->users.length; i++){
                createRequestQueue(&app->users.contents[i].friendRequest);
                ADVWORDFILE();
                app->users.contents[i].ID = i;
                app->users.contents[i].name.maxLength = 20;
                addString(&(app->users.contents[i].name), currentWordFile);
                ADVWORDFILE();
                app->users.contents[i].password.maxLength = 20;
                addString(&app->users.contents[i].password, currentWordFile);
                ADVWORDFILE();
                app->users.contents[i].profile.bio.maxLength = 135;
                addString(&app->users.contents[i].profile.bio, currentWordFile);
                ADVWORDFILE();
                app->users.contents[i].profile.phoneNumber.maxLength = stringLength(currentWordFile);
                addString(&app->users.contents[i].profile.phoneNumber, currentWordFile);
                ADVWORDFILE();
                app->users.contents[i].profile.weton.maxLength = stringLength(currentWordFile);
                addString(&app->users.contents[i].profile.weton, currentWordFile);
                ADVWORDFILE();
                app->users.contents[i].profile.isPrivate = (currentWordFile.buffer[1] == 'r');
                for (j=0; j<5; j++){
                    ADVFILEPHOTO();
                    replaceString(&photoString, j*20, (j*20)+21, currentWordFile);
                }
                readPhotoFile(&(app->users.contents[i].profile.photo), photoString);
                
            }
            /* disini currentwordfile masih baris terakhir dari 
            foto profile */
            Graf friendships;
            CreateGraph(&friendships);
            friendships.adjacencyMatrix.colEff = app->users.length;
            friendships.adjacencyMatrix.rowEff = app->users.length;
            for (i=0;i<app->users.length;i++){
                for(j=0;j<app->users.length;j++){
                    ADVWORDFILE2();
                    if (currentWordFile.buffer[0] - '0' == 1){
                        addEdge(&friendships, i, j);
                    }
                }
                addVertices(&friendships);
            }
            app->friendships = friendships;
            // printGraph(app->friendships);
            ADVWORDFILE();
            int permintaan = currentWordFile.buffer[0] - '0';
            Friend f;
            int idyangminta, idyangdiminta, friendcountfile;
            for (i = 0; i < permintaan; i++){
                ADVWORDFILE2();
                idyangminta = currentWordFile.buffer[0] - '0';
                ADVWORDFILE2();
                idyangdiminta = currentWordFile.buffer[0] - '0';
                ADVWORDFILE();
                // printf("%c\n", currentCharFile);
                friendcountfile = currentWordFile.buffer[0] - '0';
                f.friendCount = friendcountfile;
                app->users.contents[idyangminta].friendCount = friendcountfile;
                f.userID = idyangminta;
                enqueueRequestQueue(&app->users.contents[idyangdiminta].friendRequest, f);
            }
            // displayRequestQueue(app->users.contents[1].friendRequest, app->users);
        }
    }
    
    CLOSEFILE();
}

void LoadKicauan(Application *app){
    String filename;
    int i;
    CreateListKicau(&app->listKicauan, 1000);
    char temp[20] = "kicauan.config";
    addChartoChar(filename.buffer, temp);
    filename.maxLength = STRCAP;
    STARTWORDFILE(filename);
    if (retvalfile != -1){
        app->listKicauan.nEff = stringToInt(currentWordFile);
        for(i=0;i<app->listKicauan.nEff;i++){
            ADVWORDFILE();
            int IdKicau = stringToInt(currentWordFile);
            ADVWORDFILE();
            String text = currentWordFile;
            ADVWORDFILE();
            int like = stringToInt(currentWordFile);
            ADVWORDFILE();
            app->listKicauan.buffer[i].IDuser = searchByName(app->users, currentWordFile);
            InisialisasiKicau(&app->listKicauan.buffer[i], app->listKicauan.buffer[i].IDuser);
            app->listKicauan.buffer[i].IDKicau = IdKicau;
            app->listKicauan.buffer[i].like = like;
            app->listKicauan.buffer[i].text = text;
            ADVWORDFILE();
            app->listKicauan.buffer[i].dateTime = currentWordFile;
        
        }
    }
    CLOSEFILE();
}

void LoadBalasan(Application *app){
    String filename;
    int i,j;
    char temp[20] = "balasan.config";
    addChartoChar(filename.buffer, temp);
    filename.maxLength = STRCAP;
    STARTWORDFILE(filename);
    if (retvalfile != -1){
        int banyakkicauan = stringToInt(currentWordFile); /* banyak kicauan yang memiliki balasan*/
        for (i=0;i<banyakkicauan;i++){
            ADVWORDFILE();
            int idkicau = stringToInt(currentWordFile); /* id kicauan */
            app->listKicauan.buffer[idkicau-1].IDKicau = idkicau;
            createReplyTree(&app->listKicauan.buffer[idkicau-1].balasan, 100);
            ADVWORDFILE();
            int balasan = stringToInt(currentWordFile); /* banyak balasan */
            app->listKicauan.buffer[idkicau-1].balasan.numReplyEff = balasan;
            for (i=0;i<balasan;i++){
                ADVWORDFILE2(); /* currenwordfile berisi parent id*/
                int parentid = stringToInt(currentWordFile);
                ADVWORDFILE(); /* currentwordfile berisi id balasan */
                int IDBalasan = stringToInt(currentWordFile);
                ADVWORDFILE(); /* currentwordfile berisi isi balasannya */
                String body = currentWordFile;
                ADVWORDFILE(); /* currentwordfile berisi author balasan */
                String name = currentWordFile;
                ADVWORDFILE(); /* currentwordfile berisi datetime */
                String DATETIME = currentWordFile;
                // AddReplyDariConfig(&app->listKicauan.buffer[idkicau-1].balasan, app->users, idkicau, IDBalasan, body, name, DATETIME); 
            }
        }
    }
    CLOSEFILE();
}

void LoadUtas(Application *app){
    String filename;
    int i,j;
    char temp[20] = "utas.config";
    addChartoChar(filename.buffer, temp);
    filename.maxLength = STRCAP;
    STARTWORDFILE(filename);
    if (retvalfile != -1){
        // printf("here");
        int kicaudenganutas= stringToInt(currentWordFile); /* banyak kicauan yang memiliki utas */
        app->JumlahUtas = kicaudenganutas;
        for (i=0;i<kicaudenganutas;i++){
            ADVWORDFILE(); /* currentwordfile berisi id kicauan yang memiliki utas */
            int IDKicau = stringToInt(currentWordFile);
            ADVWORDFILE(); /* currentwordfile berisi banyak utas */
            int banyakutas = stringToInt(currentWordFile);
            app->listKicauan.buffer[IDKicau-1].lenUtas = banyakutas; 
            ADVWORDFILE();
            String teks = currentWordFile;
            ADVWORDFILE();
            String nama = currentWordFile;
            ADVWORDFILE();
            String waktu = currentWordFile;
            app->listKicauan.buffer[IDKicau-1].link =  newNodeUtas(teks, nama, waktu);
            AddressUtas p = app->listKicauan.buffer[IDKicau-1].link;
            app->listKicauan.buffer[IDKicau-1].IDUtas = i+1;
            for (j=1;j<banyakutas;j++){
                ADVWORDFILE();
                String teks = currentWordFile;
                ADVWORDFILE();
                String nama = currentWordFile;
                ADVWORDFILE();
                String waktu = currentWordFile;
                AddressUtas node =  newNodeUtas(teks, nama, waktu);
                p->next = node;
                p = node;
            }
        }
    }
    CLOSEFILE();
}