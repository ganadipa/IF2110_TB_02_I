#include "../lib/ADT/WordMachine/charmachinefile.h"
#include "../lib/ADT/WordMachine/wordmachinefile.h"
#include "../lib/ADT/WordMachine/wordmachine.h"
#include "../lib/ADT/WordMachine/charmachine.h"
#include "../lib/ADT/String/string.h"
#include "../lib/ADT/PColor/pcolor.h"
#include "../lib/Types/Photo.h"
#include "../lib/ADT/Matriks/charMatriks.h"
// #include "../lib/ADT/WordMachine/charmachinefile.c"
// #include "../lib/ADT/WordMachine/wordmachinefile.c"
// #include "../lib/ADT/WordMachine/wordmachine.c"
// #include "../lib/ADT/WordMachine/charmachine.c"
// #include "../lib/ADT/String/string.c"
// #include "../lib/ADT/PColor/pcolor.c"
// #include "../lib/Types/Photo.c"
// #include "../lib/ADT/Matriks/charMatriks.c"
#include <stdio.h>



void LoadPengguna(Application *app){
    String filename;
    int i,j;
    char temp[20] = "pengguna.config";
    String photoString;
    createEmptyString(&photoString, 100);
    addChartoChar(filename.buffer, temp);
    filename.maxLength = STRCAP;
    STARTWORDFILE(filename);
    if (retvalfile != -1){
        app->users.length = currentWordFile.buffer[0] - '0';
        
    }
    if(app->users.length > 0){
        for (i=0; i < app->users.length; i++){
            ADVWORDFILE();
            app->users.contents[i].ID = i;
            app->users.contents[i].name.maxLength = 20;
            addString(&app->users.contents[i].name, currentWordFile);
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
            emptyString(&photoString);
            for (j=0; j<5; j++){
                ADVFILEPHOTO();
                addString(&photoString, currentWordFile);
            }
            readPhotoFile(&(app->users.contents[i].profile.photo), photoString);
            
        }
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
    }
        
}

int main(){
    Application app;
    LoadPengguna(&app);
    
    // displayString(app->users.contents[2].name);
    // printf("\n");
    // displayString(app->users.contents[2].password);
    // displayString(app->users.contents[2].profile.bio);
    // displayString(app->users.contents[2].profile.phoneNumber);
    // displayString(app->users.contents[2].profile.weton);
    // // displayPhoto(app->users.contents[1].profile.photo);
    // printf("%u", app->users.contents[2].profile.isPrivate);
    // displayString(photoString);
    // printf("%d", photoString.maxLength);
}