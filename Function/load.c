#include "../lib/ADT/WordMachine/charmachinefile.h"
#include "../lib/ADT/WordMachine/wordmachinefile.h"
#include "../lib/ADT/WordMachine/wordmachine.h"
#include "../lib/ADT/WordMachine/charmachine.h"
#include "../lib/ADT/String/string.h"
#include "../lib/ADT/PColor/pcolor.h"
#include "../lib/Types/Photo.h"
#include "../lib/ADT/Matriks/charMatriks.h"
#include <stdio.h>
// int main(){
//     String s;
//     readString(&s, 351);
//     STARTWORDFILE(s);
//     printf("tanda");
//     // printf("%c", currentWordFile.buffer[1]);
//     while (!EndFile){ /* Mark = \n */
            
//             for (int i = 0 ; i < currentWordFile.maxLength; i++){
//                 printf("%c", currentWordFile.buffer[i]);
//             }
//             printf("\n");
//             ADVWORDFILE();
//     }

// }
Application app;
void LoadPengguna(){
    String filename;
    int i,j;
    char temp[20] = "pengguna.config";
    String photoString;
    createEmptyString(&photoString, 100);
    addChartoChar(filename.buffer, temp);
    filename.maxLength = STRCAP;
    STARTWORDFILE(filename);
    if (retvalfile != -1){
        app.users.length = currentWordFile.buffer[0] - '0';
        
    }
    if(app.users.length > 0){
        for (i=0; i < 1; i++){
            ADVWORDFILE();
            app.users.contents[i].ID = i;
            app.users.contents[i].name.maxLength = 20;
            addString(&app.users.contents[i].name, currentWordFile);
            ADVWORDFILE();
            app.users.contents[i].password.maxLength = 20;
            addString(&app.users.contents[i].password, currentWordFile);
            ADVWORDFILE();
            app.users.contents[i].profile.bio.maxLength = 135;
            addString(&app.users.contents[i].profile.bio, currentWordFile);
            ADVWORDFILE();
            app.users.contents[i].profile.phoneNumber.maxLength = stringLength(currentWordFile);
            addString(&app.users.contents[i].profile.phoneNumber, currentWordFile);
            ADVWORDFILE();
            app.users.contents[i].profile.weton.maxLength = stringLength(currentWordFile);
            addString(&app.users.contents[i].profile.weton, currentWordFile);
            ADVWORDFILE();
            app.users.contents[i].profile.isPrivate = (currentWordFile.buffer[1] == 'r');
            for (j=0; j<5; j++){
                ADVFILEPHOTO();
                addString(&photoString, currentWordFile);
                // displayString(currentWordFile);
                // printf("\n");
            }
            // displayString(photoString);/
            // printf("\n");
            // createEmptyString(&photoString, 100);
        }
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
        ADVWORDFILE();
    }
        
}

// int main(){
//     LoadPengguna();
    
//     // displayString(app.users.contents[0].name);
//     // printf("\n");
//     // displayString(app.users.contents[1].password);
//     // printf("\n");
//     // displayString(app.users.contents[1].profile.bio);
//     // printf("\n");
//     // displayString(app.users.contents[1].profile.phoneNumber);
//     // printf("\n");
//     // displayString(app.users.contents[1].profile.weton);
//     // printf("\n");
//     // displayPhoto(app.users.contents[0].profile.photo);
//     // printf("%u", app.users.contents[0].profile.isPrivate);
// }