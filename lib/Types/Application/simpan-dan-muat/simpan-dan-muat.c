#include <stdio.h>
#include "simpan-dan-muat.h"

Application MuatFolder(Application *apporiginal, String pathfilefolder){
    Application app;
    CreateListUser(&LISTUSER(app)); 
    CreateGraph(&FRIENDSHIPS(app));
    CreateListKicau(&KICAUAN(app), 1000);
    LoadPengguna(&app, pathfilefolder);
    if(EndFile){
        printf("Tidak ada folder yang dimaksud!");
        return *apporiginal;
    }
    LoadKicauan(&app, pathfilefolder);
    LoadBalasan(&app,pathfilefolder);
    LoadDraft(&app, pathfilefolder);
    LoadUtas(&app, pathfilefolder);
    deleteRest(&pathfilefolder);
    printf("Anda akan melakukan pemuatan dari %s.\n", pathfilefolder.buffer);
    printf("Mohon tunggu...\n");
    printf("1...\n");
    printf("2...\n");
    printf("3...\n");
    printf("Pemuatan selesai!\n");
    LOGGEDIN(app) = false;
    LOGINID(app) = ID_UNDEF;
    return app;
}

void LoadPengguna(Application *app, String pathfilefolder){
    String folder = pathfilefolder;
    String filename = {"/pengguna.config", 20};
    addString(&folder, filename);
    int i,j;
    String photoString;
    createEmptyString(&photoString, 225);
    STARTWORDFILE(folder);
    if (retvalfile != -1 && !EndFile){
        app->users.length = stringToInt(currentWordFile);
        if(app->users.length > 0){
            for (i=0; i < app->users.length; i++){
                createRequestQueue(&app->users.contents[i].friendRequest);
                ADVWORDFILE();
                app->users.contents[i].ID = i;
                app->users.contents[i].name.maxLength = 20;
                app->users.contents[i].name = currentWordFile;
                ADVWORDFILE();
                app->users.contents[i].password.maxLength = 20;
                app->users.contents[i].password = currentWordFile;
                ADVWORDFILE();
                app->users.contents[i].profile.bio.maxLength = 135;
                app->users.contents[i].profile.bio = currentWordFile;
                ADVWORDFILE();
                app->users.contents[i].profile.phoneNumber.maxLength = stringLength(currentWordFile);
                app->users.contents[i].profile.phoneNumber = currentWordFile;
                ADVWORDFILE();
                app->users.contents[i].profile.weton.maxLength = stringLength(currentWordFile);
                app->users.contents[i].profile.weton = currentWordFile;
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

void LoadKicauan(Application *app, String pathfilefolder){
    String folder = pathfilefolder;
    String filename = {"/kicauan.config", 20};
    int i;
    // CreateListKicau(&app->listKicauan, 1000);
    addString(&folder, filename);
    STARTWORDFILE(folder);

    if (retvalfile != -1){
        int jumlahkicau = stringToInt(currentWordFile);
        for(i=0;i<jumlahkicau;i++){
            Kicauan kicau;
            ADVWORDFILE();
            int IdKicau = stringToInt(currentWordFile);
            ADVWORDFILE();
            String text = currentWordFile;
            ADVWORDFILE();
            int like = stringToInt(currentWordFile);
            ADVWORDFILE();
            int id = searchByName(app->users, currentWordFile);
            InisialisasiKicau(&kicau, id);
            ADVWORDFILE();
            kicau.dateTime = currentWordFile;
            kicau.IDKicau = IdKicau;
            kicau.like = like;
            kicau.IDuser = id;
            kicau.text = text;
            insertLastListKicau(&app->listKicauan, kicau);
        }

    }
    CLOSEFILE();
}

void LoadBalasan(Application *app, String pathfilefolder){
    String folder = pathfilefolder;
    String filename = {"/balasan.config", 20};
    int i,j;
    addString(&folder, filename);
    STARTWORDFILE(folder);
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
            for (j=0;j<balasan;j++){
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
                AddReplyDariConfig(&app->listKicauan.buffer[idkicau-1].balasan, &app->users, idkicau, IDBalasan, parentid, body, name, DATETIME); 
            }
        }
    }
    printf("\n");
    CLOSEFILE();
}

void LoadUtas(Application *app, String pathfilefolder){
    String folder = pathfilefolder;
    String filename = {"/utas.config", 20};
    int i,j;
    addString(&folder, filename);
    
    STARTWORDFILE(folder);
    if (retvalfile != -1){
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
        deleteRest(&currentWordFile);
    }
    CLOSEFILE();
}

void LoadDraft(Application *app, String pathfilefolder){
    String filename = {"/draf.config", 20};
    String folder = pathfilefolder;
    addString(&folder, filename);
    int i,j;
    STARTWORDFILE(folder);
    if(retvalfile != -1){
        int banyakpengguna = stringToInt(currentWordFile);
        for(i=0;i<banyakpengguna;i++){
            ADVWORDFILE();
            String username = currentWordFile;
            username.maxLength -= 2;
            int userid = searchByName(app->users, username);
            CreateDraftDin(&app->users.contents[userid].drafKicau);
            int banyakdraft = currentWordFile.buffer[currentWordFile.maxLength-1] - '0';
            Kicauan kicau;
            InisialisasiDrafDinKicau(&kicau, userid);
            for(j=0;j<banyakdraft;j++){
                ADVWORDFILE();
                kicau.text = currentWordFile;
                ADVWORDFILE();
                kicau.dateTime = currentWordFile;
                PushDrafDin(&app->users.contents[userid].drafKicau, kicau);
            }
            AddressDraf p = app->users.contents[userid].drafKicau.drafTop;
            while(p != NULL){
                p = p->next; 
            }
            
        }
    }
    CLOSEFILE();
}