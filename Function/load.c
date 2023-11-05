// #include "../lib/ADT/WordMachine/charmachinefile.h"
// #include "../lib/ADT/WordMachine/wordmachinefile.h"
// #include "../lib/ADT/WordMachine/wordmachine.h"
// #include "../lib/ADT/WordMachine/charmachine.h"
// #include "../lib/ADT/String/string.h"
// #include "../lib/ADT/PColor/pcolor.h"
// #include "../lib/Types/Photo.h"
// #include "../lib/ADT/Matriks/charMatriks.h"
// #include "../lib/Types/Kicauan.h"
// #include "../lib/Types/listKicauan.h"
// #include "../lib/ADT/DateTime/datetime.h"
// #include "../lib/Types/ListUser.h"
// #include "../lib/Types/RequestQueue.h"
// #include "../lib/ADT/ListDinamik/listdinamik.h"
#include "../lib/Types/ReplyTree.h"
#include "../lib/ADT/WordMachine/charmachinefile.c"
#include "../lib/ADT/WordMachine/wordmachinefile.c"
#include "../lib/ADT/WordMachine/wordmachine.c"
#include "../lib/ADT/WordMachine/charmachine.c"
#include "../lib/ADT/ListDinamik/listdinamik.c"
#include "../lib/ADT/String/string.c"
#include "../lib/ADT/PColor/pcolor.c"
#include "../lib/Types/Photo.c"
#include "../lib/ADT/Matriks/charMatriks.c"
#include "../lib/Types/Kicauan.c"
#include "../lib/Types/listKicauan.c"
#include "../lib/ADT/DateTime/datetime.c"
#include "../lib/Types/ListUser.c"
#include "../lib/Types/RequestQueue.c"
#include "../lib/Types/ReplyTree.c"
#include <stdio.h>



void LoadPengguna(Application *app){
    String filename;
    int i,j;
    char temp[20] = "pengguna.config";
    String photoString;
    createEmptyString(&photoString, 225);
    addChartoChar(filename.buffer, temp);
    filename.maxLength = STRCAP;
    STARTWORDFILE(filename);
    while (retvalfile != -1){
        app->users.length = stringToInt(currentWordFile);
        if(app->users.length > 0){
        for (i=0; i < app->users.length; i++){
            ADVWORDFILE();
            app->users.contents[i].ID = i;
            app->users.contents[i].name.maxLength = 20;
            // displayString(currentWordFile);
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
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
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
    while (retvalfile != -1){
        app->listKicauan.nEff = stringToInt(currentWordFile);
        // printf("%d", app->listKicauan.nEff);
        for(i=0;i<app->listKicauan.nEff;i++){
            ADVWORDFILE();
            app->listKicauan.buffer[i].IDKicau = stringToInt(currentWordFile);
            ADVWORDFILE();
            app->listKicauan.buffer[i].text = currentWordFile;
            ADVWORDFILE();
            app->listKicauan.buffer[i].like = stringToInt(currentWordFile);
            ADVWORDFILE();
            app->listKicauan.buffer[i].IDuser = searchByName(app->users, currentWordFile);
            ADVWORDFILE();
            app->listKicauan.buffer[i].dateTime = currentWordFile;
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

    }
}
int main(){
    Application app;
    String nama = {"john", 100};
    LoadPengguna(&app);
    LoadKicauan(&app);
    // printf("%d", app.listKicauan.nEff);
    // displayString(app.users.contents[0].name);
    // printf("\n");
    // displayString(app.users.contents[0].password);
    // displayString(app.users.contents[0].profile.bio);
    // displayString(app.users.contents[0].profile.phoneNumber);
    // printf("\n");
    // displayString(app.users.contents[0].profile.weton);
    // readPhoto(&app.users.contents[0].profile.photo);
    displayPhoto(app.users.contents[0].profile.photo);
    // // printf("%u", app->users.contents[2].profile.isPrivate);
    // // displayString(photoString);
    // // printf("%d", photoString.maxLength);
    
    // printf("%d", app.listKicauan.buffer[0].IDKicau);
    // printf("\n");
    // displayString(app.listKicauan.buffer[0].text);
    // printf("\n");
    // // // printKicauan(app.listKicauan.buffer[0], nama);
    // printf("%d", app.listKicauan.buffer[0].IDuser);
    // printf("\n");
    // displayString(app.listKicauan.buffer[0].dateTime);
}

// // // 