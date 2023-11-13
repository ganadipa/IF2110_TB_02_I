// #include "../lib/ADT/WordMachine/charmachinefile.h"
// #include "../lib/ADT/WordMachine/wordmachinefile.h"
// #include "../lib/ADT/WordMachine/wordmachine.h"
// #include "../lib/ADT/WordMachine/charmachine.h"
// #include "../lib/ADT/String/string.h"
// #include "../lib/ADT/PColor/pcolor.h"
// #include "../lib/Types/Photo.h"
// #include "../lib/ADT/Matriks/charMatriks.h"
// // #include "../lib/ADT/WordMachine/charmachinefile.c"
// // #include "../lib/ADT/WordMachine/wordmachinefile.c"
// // #include "../lib/ADT/WordMachine/wordmachine.c"
// // #include "../lib/ADT/WordMachine/charmachine.c"
// // #include "../lib/ADT/String/string.c"
// // #include "../lib/ADT/PColor/pcolor.c"
// // #include "../lib/Types/Photo.c"
// // #include "../lib/ADT/Matriks/charMatriks.c"
// // #include "../lib/Types/Kicauan.c"
// // #include "../lib/Types/listKicauan.c"
// // #include "../lib/ADT/DateTime/datetime.c"
// // #include "../lib/Types/ListUser.c"
// // #include "../lib/Types/RequestQueue.c"
// #include <stdio.h>

// void LoadKicauan(Application *app){
//     String filename;
//     int i;
//     CreateListKicau(&app->listKicauan, 1000);
//     char temp[20] = "kicauan.config";
//     addChartoChar(filename.buffer, temp);
//     filename.maxLength = STRCAP;
//     STARTWORDFILE(filename);
//     while (retvalfile != -1){
//         app->listKicauan.nEff = stringToInt(currentWordFile);
//         // printf("%d", app->listKicauan.nEff);
//         // printf("aneh");
//         for(i=0;i<app->listKicauan.nEff;i++){
//             ADVWORDFILE();
//             app->listKicauan.buffer[i].IDKicau = stringToInt(currentWordFile);
//             // setKicauID(&app->listKicauan.buffer[i], stringToInt(currentWordFile));
//             ADVWORDFILE();
//             // addString(&app->listKicauan.buffer[i].text, currentWordFile);
//             app->listKicauan.buffer[i].text = currentWordFile;
//             ADVWORDFILE();
//             app->listKicauan.buffer[i].like = stringToInt(currentWordFile);
//             ADVWORDFILE();
//             app->listKicauan.buffer[i].IDuser = searchByName(app->users, currentWordFile);
//             ADVWORDFILE();
//             // addString(&app->listKicauan.buffer[i].dateTime, currentWordFile); 
//             app->listKicauan.buffer[i].dateTime = currentWordFile;
//         }
//     }
//     CLOSEFILE();
// }

// int main(){
//     Application app;
//     // CreateListKicau(&app.listKicauan, 1000);
//     String nama = {"john", 100};
//     // LoadKicauan(&app);
//     // app.listKicauan.buffer[0].text = nama;
//     // displayString(app.listKicauan.buffer[0].text);
//     LoadKicauan(&app);
//     // displayString(app.users.contents[2].name);
//     // // // printf("\n");
//     // displayString(app.users.contents[2].password);
//     // displayString(app.users.contents[2].profile.bio);
//     // displayString(app.users.contents[2].profile.phoneNumber);
//     // displayString(app.users.contents[2].profile.weton);
//     // // displayPhoto(app->users.contents[1].profile.photo);
//     // // printf("%u", app->users.contents[2].profile.isPrivate);
//     // // displayString(photoString);
//     // // printf("%d", photoString.maxLength);
    
//     printf("%d\n", app.listKicauan.buffer[0].IDKicau);
//     displayString(app.listKicauan.buffer[0].text);
//     printf("\n");
//     // printKicauan(app.listKicauan.buffer[0], nama);
//     printf("%d\n", app.listKicauan.buffer[0].IDuser);
//     displayString(app.listKicauan.buffer[0].dateTime);
// }
