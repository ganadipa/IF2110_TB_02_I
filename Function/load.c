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
// #include "../lib/Types/ReplyTree.h"
// #include "../lib/ADT/Graf/graf.h"
// #include "../lib/Types/Application/Application.h"
// // #include "../lib/ADT/WordMachine/charmachinefile.c"
// // #include "../lib/ADT/WordMachine/wordmachinefile.c"
// // #include "../lib/ADT/WordMachine/wordmachine.c"
// // #include "../lib/ADT/WordMachine/charmachine.c"
// // #include "../lib/ADT/ListDinamik/listdinamik.c"
// // #include "../lib/ADT/String/string.c"
// // #include "../lib/ADT/PColor/pcolor.c"
// // #include "../lib/Types/Photo.c"
// // #include "../lib/ADT/Matriks/charMatriks.c"
// // #include "../lib/Types/Kicauan.c"
// // #include "../lib/Types/listKicauan.c"
// // #include "../lib/ADT/DateTime/datetime.c"
// // #include "../lib/Types/ListUser.c"
// // #include "../lib/Types/RequestQueue.c"
// // #include "../lib/Types/ReplyTree.c"
// // #include "../lib/ADT/Graf/graf.c"
// // #include "../lib/Types/listUtas.c"
// #include <stdio.h>

// /* Load pengguna tinggal baris akhir */
// /* LoadKicauan harusnya udh beres */
// void LoadPengguna(Application *app){
//     String filename;
//     int i,j;
//     char temp[20] = "pengguna.config";
//     String photoString;
//     createEmptyString(&photoString, 225);
//     addChartoChar(filename.buffer, temp);
//     filename.maxLength = STRCAP;
//     STARTWORDFILE(filename);
//     while (retvalfile != -1){
//         app->users.length = stringToInt(currentWordFile);
//         if(app->users.length > 0){
//             for (i=0; i < app->users.length; i++){
//                 createRequestQueue(&app->users.contents[i].friendRequest);
//                 ADVWORDFILE();
//                 app->users.contents[i].ID = i;
//                 app->users.contents[i].name.maxLength = 20;
//                 // displayString(currentWordFile);
//                 addString(&(app->users.contents[i].name), currentWordFile);
//                 ADVWORDFILE();
//                 app->users.contents[i].password.maxLength = 20;
//                 addString(&app->users.contents[i].password, currentWordFile);
//                 ADVWORDFILE();
//                 app->users.contents[i].profile.bio.maxLength = 135;
//                 addString(&app->users.contents[i].profile.bio, currentWordFile);
//                 ADVWORDFILE();
//                 app->users.contents[i].profile.phoneNumber.maxLength = stringLength(currentWordFile);
//                 addString(&app->users.contents[i].profile.phoneNumber, currentWordFile);
//                 ADVWORDFILE();
//                 app->users.contents[i].profile.weton.maxLength = stringLength(currentWordFile);
//                 addString(&app->users.contents[i].profile.weton, currentWordFile);
//                 ADVWORDFILE();
//                 app->users.contents[i].profile.isPrivate = (currentWordFile.buffer[1] == 'r');
//                 for (j=0; j<5; j++){
//                     ADVFILEPHOTO();
//                     replaceString(&photoString, j*20, (j*20)+21, currentWordFile);
//                 }
//                 readPhotoFile(&(app->users.contents[i].profile.photo), photoString);
                
//             }
//             /* disini currentwordfile masih baris terakhir dari 
//             foto profile */
//             Graf friendships;
//             CreateGraph(&friendships);
//             friendships.adjacencyMatrix.colEff = app->users.length;
//             friendships.adjacencyMatrix.rowEff = app->users.length;
//             for (i=0;i<app->users.length;i++){
//                 for(j=0;j<app->users.length;j++){
//                     ADVWORDFILE2();
//                     if (currentWordFile.buffer[0] - '0' == 1){
//                         addEdge(&friendships, i, j);
//                     }
//                 }
//                 addVertices(&friendships);
//             }
//             ADVWORDFILE();
//             int permintaan = currentWordFile.buffer[0] - '0';
//             Friend f;
//             int idyangminta, idyangdiminta, friendcountfile;
//             for (i = 0; i < permintaan; i++){
//                 ADVWORDFILE2();
//                 idyangminta = currentWordFile.buffer[0] - '0';
//                 ADVWORDFILE2();
//                 idyangdiminta = currentWordFile.buffer[0] - '0';
//                 ADVWORDFILE();
//                 // printf("%c\n", currentCharFile);
//                 friendcountfile = currentWordFile.buffer[0] - '0';
//                 f.friendCount = friendcountfile;
//                 app->users.contents[idyangminta].friendCount = friendcountfile;
//                 f.userID = idyangminta;
//                 enqueueRequestQueue(&app->users.contents[idyangdiminta].friendRequest, f);
//             }
//             // displayRequestQueue(app->users.contents[0].friendRequest, app->users);
//         }
//     }
    
//     CLOSEFILE();
// }
// void LoadKicauan(Application *app){
//     String filename;
//     int i;
//     CreateListKicau(&app->listKicauan, 1000);
//     char temp[20] = "kicauan.config";
//     addChartoChar(filename.buffer, temp);
//     filename.maxLength = STRCAP;
//     STARTWORDFILE(filename);
//     if (retvalfile != -1){
//         app->listKicauan.nEff = stringToInt(currentWordFile);
//         for(i=0;i<app->listKicauan.nEff;i++){
//             ADVWORDFILE();
//             int IdKicau = stringToInt(currentWordFile);
//             ADVWORDFILE();
//             String text = currentWordFile;
//             ADVWORDFILE();
//             int like = stringToInt(currentWordFile);
//             ADVWORDFILE();
//             app->listKicauan.buffer[i].IDuser = searchByName(app->users, currentWordFile);
//             InisialisasiKicau(&app->listKicauan.buffer[i], app->listKicauan.buffer[i].IDuser);
//             app->listKicauan.buffer[i].IDKicau = IdKicau;
//             app->listKicauan.buffer[i].like = like;
//             app->listKicauan.buffer[i].text = text;
//             ADVWORDFILE();
//             app->listKicauan.buffer[i].dateTime = currentWordFile;
        
//         }
//     }
//     CLOSEFILE();
// }
// void LoadBalasan(Application *app){
//     String filename;
//     int i,j;
//     char temp[20] = "balasan.config";
//     addChartoChar(filename.buffer, temp);
//     filename.maxLength = STRCAP;
//     STARTWORDFILE(filename);
//     if (retvalfile != -1){
//         int banyakkicauan = stringToInt(currentWordFile); /* banyak kicauan yang memiliki balasan*/
//         for (i=0;i<banyakkicauan;i++){
//             ADVWORDFILE();
//             int idkicau = stringToInt(currentWordFile); /* id kicauan */
//             app->listKicauan.buffer[idkicau-1].IDKicau = idkicau;
//             createReplyTree(&app->listKicauan.buffer[idkicau-1].balasan, 100);
//             ADVWORDFILE();
//             int balasan = stringToInt(currentWordFile); /* banyak balasan */
//             app->listKicauan.buffer[idkicau-1].balasan.numReplyEff = balasan;
//             for (i=0;i<balasan;i++){
//                 ADVWORDFILE2(); /* currenwordfile berisi parent id*/
//                 int parentid = stringToInt(currentWordFile);
//                 ADVWORDFILE(); /* currentwordfile berisi id balasan */
//                 int IDBalasan = stringToInt(currentWordFile);
//                 ADVWORDFILE(); /* currentwordfile berisi isi balasannya */
//                 String body = currentWordFile;
//                 ADVWORDFILE(); /* currentwordfile berisi author balasan */
//                 String name = currentWordFile;
//                 ADVWORDFILE(); /* currentwordfile berisi datetime */
//                 String DATETIME = currentWordFile;
//                 AddReplyDariConfig(&app->listKicauan.buffer[idkicau-1].balasan, app->users, idkicau, IDBalasan, body, name, DATETIME); 
//             }
//         }
//     }
//     CLOSEFILE();
// }
// void LoadUtas(Application *app){
//     String filename;
//     int i,j;
//     char temp[20] = "utas.config";
//     addChartoChar(filename.buffer, temp);
//     filename.maxLength = STRCAP;
//     STARTWORDFILE(filename);
//     while (retvalfile != -1){
//         int kicaudenganutas= stringToInt(currentWordFile); /* banyak kicauan yang memiliki utas */
//         app->JumlahUtas = kicaudenganutas;
//         for (i=0;i<kicaudenganutas;i++){
//             ADVWORDFILE(); /* currentwordfile berisi id kicauan yang memiliki utas */
//             int IDKicau = stringToInt(currentWordFile);
//             ADVWORDFILE(); /* currentwordfile berisi banyak utas */
//             int banyakutas = stringToInt(currentWordFile);
//             app->listKicauan.buffer[IDKicau-1].lenUtas = banyakutas; 
//             ADVWORDFILE();
//             String teks = currentWordFile;
//             ADVWORDFILE();
//             String nama = currentWordFile;
//             ADVWORDFILE();
//             String waktu = currentWordFile;
//             app->listKicauan.buffer[IDKicau-1].link =  newNodeUtas(teks, nama, waktu);
//             AddressUtas p = app->listKicauan.buffer[IDKicau-1].link;
//             app->listKicauan.buffer[IDKicau-1].IDUtas = i+1;
//             for (j=1;j<banyakutas;j++){
//                 ADVWORDFILE();
//                 String teks = currentWordFile;
//                 ADVWORDFILE();
//                 String nama = currentWordFile;
//                 ADVWORDFILE();
//                 String waktu = currentWordFile;
//                 AddressUtas node =  newNodeUtas(teks, nama, waktu);
//                 p->next = node;
//                 p = node;
//             }
//         }
//     }
//     CLOSEFILE();
// }
// // int main(){
// //     printf("1");
// //     Application app;
// //     String nama = {"john", 100};
// //     // LoadPengguna(&app);
// //     // LoadKicauan(&app);
// //     // LoadUtas(&app);
// //     // LoadBalasan(&app);
// //     // printf("%d", app.listKicauan.nEff);
// //     // displayString(app.users.contents[0].name);
// //     // printf("\n");
// //     // displayString(app.users.contents[0].password);
// //     // displayString(app.users.contents[0].profile.bio);
// //     // displayString(app.users.contents[0].profile.phoneNumber);
// //     // printf("\n");
// //     // displayString(app.users.contents[0].profile.weton);
// //     // readPhoto(&app.users.contents[0].profile.photo);
// //     // displayPhoto(app.users.contents[2].profile.photo);
// //     // display_listUtas(&app, 1)
// //     // // printf("%u", app->users.contents[2].profile.isPrivate);
// //     // // displayString(photoString);
// //     // // printf("%d", photoString.maxLength);
    
// //     // printf("%d", app.listKicauan.buffer[0].IDKicau);
// //     // printf("\n");
// //     // // displayString(app.listKicauan.buffer[0].text);
// //     // printf("\n");
// //     // printKicauan(app.listKicauan.buffer[1], nama);
// //     // // printf("%d", app.listKicauan.buffer[0].IDuser);
// //     // printf("\n");
// //     // displayString(app.listKicauan.buffer[0].dateTime);
// //     printAllReplyTree(app.listKicauan.buffer[4].balasan);

// //     // printf("%d", )
// //     // printf("%u", app.listKicauan.buffer[1].link->next->next->next);
// //     // displayString(app.listKicauan.buffer[1].link->next->next->teks);
// // }
// // int main(){
// //     DATETIME D; 
// //     String S;
// //     D = currentDateTime();
// //     S = DateTimeToString(D);
// //     D = StringToDateTime(S);
// //     printf("%d", D.Day);
// //     printf("%d", D.Month);
// //     printf("%d", D.Year);
// //     printf("%d", D.Hour);
// //     printf("%d", D.Minute);
// //     printf("%d", D.Second);

// // }

// // // 
// // int main(){
// //     Application app;
// //     printf("1");
// //     String nama = {"john", 100};
// //     return 0;
// // }