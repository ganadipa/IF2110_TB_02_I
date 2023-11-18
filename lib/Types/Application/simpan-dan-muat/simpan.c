#include "simpan.h"


boolean isExist(String *path){
    struct stat buffer;
    return (stat(path->buffer, &buffer) == 0);
}

void SavingFilePengguna(String* path, ListUser user){
    const char *pengguna = "pengguna.config"; 

    String parentDir; 
    createEmptyString(&parentDir, 100);

    snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, pengguna);
    FILE *filePengguna = fopen(parentDir.buffer, "w");
    int i = 0; 
    fprintf(filePengguna, "%d\n", user.length);
    for(i = 0; i < user.length; i++){
        deleteRest(&user.contents[i].name);
        deleteRest(&user.contents[i].password);
        deleteRest(&user.contents[i].profile.bio);
        deleteRest(&user.contents[i].profile.phoneNumber);
        deleteRest(&user.contents[i].profile.weton);
        fprintf(filePengguna, "%s\n", user.contents[i].name.buffer);
        fprintf(filePengguna, "%s\n", user.contents[i].password.buffer);
        fprintf(filePengguna, "%s\n", user.contents[i].profile.bio.buffer);
        fprintf(filePengguna, "%s\n", user.contents[i].profile.phoneNumber.buffer);
        fprintf(filePengguna, "%s\n", user.contents[i].profile.weton.buffer);
        if(user.contents[i].profile.isPrivate){
            fprintf(filePengguna, "Privat\n");
        } else fprintf(filePengguna, "Publik\n");

        int row = user.contents[i].profile.photo.color.rowEff;
        int col = user.contents[i].profile.photo.color.colEff;
        int j, k;

        for(j = 0; j < row; j++){
            for(k = 0; k < col; k++){
                printf("%c %c \n", user.contents[i].profile.photo.color.mem[j][k], user.contents[i].profile.photo.symbols.mem[j][k]);


                fprintf(filePengguna, "%c %c ", user.contents[i].profile.photo.color.mem[j][k], user.contents[i].profile.photo.symbols.mem[j][k]);
            }
            fprintf(filePengguna, "\n");
        }
    }
    fclose(filePengguna);
}

void SavingFileKicauan(String* path, ListKicau kicauan, ListUser user){
    const char* kicau = "kicauan.config";
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, kicau);
    FILE *fileKicauan = fopen(Dir.buffer, "w"); 
    int i = 0; 
    fprintf(fileKicauan, "%d\n", kicauan.nEff);
    for(i = 0; i < kicauan.nEff; ++i){
        deleteRest(&kicauan.buffer[i].text);
        deleteRest(&user.contents[kicauan.buffer[i].IDuser].name);
        deleteRest(&kicauan.buffer[i].dateTime);
        fprintf(fileKicauan, "%d\n", kicauan.buffer[i].IDKicau);
        fprintf(fileKicauan, "%s\n", kicauan.buffer[i].text.buffer); 
        fprintf(fileKicauan, "%d\n", kicauan.buffer[i].like);
        fprintf(fileKicauan, "%s\n", user.contents[kicauan.buffer[i].IDuser].name.buffer); 
        if (i == kicauan.nEff -1) {
            fprintf(fileKicauan, "%s", kicauan.buffer[i].dateTime.buffer);   
        } else {
            fprintf(fileKicauan, "%s\n", kicauan.buffer[i].dateTime.buffer);
        }
        
    }
    fclose(fileKicauan);
}

void SavingFileDraf(String* path, ListUser user){
    const char* draf ="draf.config"; 
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, draf);
    FILE* fileDraf = fopen(Dir.buffer, "w"); 
    int i, j; 
    int count = 0;
    for(i = 0; i < user.length; ++i){
        if(!isDrafDinEmpty(DRAFKICAU(user.contents[i]))){
            count++;
        }
    }
    fprintf(fileDraf, "%d", count); //print berapa banyak yang punya draf;
    for(i = 0; i < user.length; ++i){
        if(!isDrafDinEmpty(DRAFKICAU(user.contents[i]))){
            deleteRest(&user.contents[i].name);
            fprintf(fileDraf, "\n%s %d", user.contents[i].name.buffer, LengthDraf(DRAFKICAU(user.contents[i])));
        }
        for(j = 0; j < LengthDraf(DRAFKICAU(user.contents[i])); ++j){
            AddressDraf temp = ADDR_TOPDRAF(DRAFKICAU(user.contents[i]));
            deleteRest(&teksKicau(INFODRAF(temp)));
            deleteRest(&dateTimeKicau(INFODRAF(temp)));
            fprintf(fileDraf, "\n%s", teksKicau(INFODRAF(temp)).buffer); 
            fprintf(fileDraf, "\n%s", dateTimeKicau(INFODRAF(temp)).buffer);
        }
    }

    fclose(fileDraf);
}

void SavingFileUtas(String *path, ListKicau listKicau, Application *Utas){
    const char* utas ="utas.config"; 
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, utas);
    FILE* fileUtas = fopen(Dir.buffer, "w"); 
    int i, j; 
    fprintf(fileUtas, "%d\n", JUMLAHUTAS(*Utas));
    for(i = 0; i < NEFF(listKicau); i++){
        if(LEN_ANAKUTAS(ELMT(listKicau, i)) != 0){
            AddressUtas utas = FIRST(ELMT(listKicau, i));
            fprintf(fileUtas, "%d\n", IDKicau(ELMT(listKicau, i)));
            fprintf(fileUtas, "%d\n", LEN_ANAKUTAS(ELMT(listKicau, i)));
            for(j = 0; j < LEN_ANAKUTAS(ELMT(listKicau, i)); j++){
                deleteRest(&TEKSDIUTAS(utas));
                deleteRest(&NAMADIUTAS(utas));
                deleteRest(&DATETIMEUTAS(utas));
                // fprintf(fileUtas, "Utas ke-%d\n", );
                fprintf(fileUtas, "%s\n", TEKSDIUTAS(utas).buffer); 
                fprintf(fileUtas, "%s\n", NAMADIUTAS(utas).buffer); 

                if (i == NEFF(listKicau) -1) {
                    fprintf(fileUtas, "%s", DATETIMEUTAS(utas).buffer);
                } else {
                    fprintf(fileUtas, "%s\n", DATETIMEUTAS(utas).buffer);
                }
                utas = NEXT_Linked(utas);
            }
        }
    }
    fclose(fileUtas);
}

void TulisBalasan(FILE* filepath, ReplyTree rt, ReplyAddress addr, ListUser *l){
    int i = getIdxInReplyTree(rt, addr); 
    printf("isused: %d, ini i; %d\n", ISUSED(rt, i), i);
    if(!ISUSED(rt, i)) return;

    Reply rep = *addr; 
    int currID = REPLYID(rep);
    int parentID = PARENT(rt, currID);
    User user = ELMT_LISTUSER(*l, AUTHORID(rep));
    String time = DateTimeToString(DTIME(rep)); 
    String Text = BODY(rep);

    printf("\n%s", Text.buffer);
    fprintf(filepath, "\n%d %d", parentID, currID); 
    fprintf(filepath, "\n%s", Text.buffer); 
    fprintf(filepath, "\n%s", user.name.buffer);
    fprintf(filepath, "\n%s", time.buffer);

}

void TulisAllBalasan(FILE* filepath, ReplyTree rt, ListUser *l, int idx){
    ListDin adjlist = LISTDIN(rt, idx); 
    printf("idx is %d", idx);
    printListDin(adjlist);
    ReplyAddress ra = ADDR(LISTREP(rt), idx); 
    int neff = NEFF(adjlist); 
    int i; 
    printf("ini di tulisAllBalasan");
    TulisBalasan(filepath, rt, ra, l); 
    printf("\nneff is: %d", neff);
    for(i = 0; i < neff; i++){
        TulisAllBalasan(filepath, rt, l, adjlist.buffer[i]);
    }

}

void SavingFileBalasan(String *path, ListKicau kicauan, ListUser user){
    const char* reply = "balasan.config"; 
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, reply); 
    FILE *fileBalasan = fopen(Dir.buffer, "w");
    int i, j, k, totalBalasan = 0; 
    for(i = 0; i < NEFF(kicauan); i++){
        if(NUMREP(BALASAN(ELMT(kicauan, i))) != 0){
            totalBalasan++;
        }
    }

    fprintf(fileBalasan, "%d", totalBalasan);
    for(i = 0; i < NEFF(kicauan); i++){
        ReplyTree balasan = BALASAN(ELMT(kicauan, i));

        if(NUMREP(balasan) != 0){ ;
            //untuk menulis ID dari kicau yang memiliki balasan 
            fprintf(fileBalasan, "\n%d", IDKicau(ELMT(kicauan, i)));
            //untuk menulis banyaknya balasan dalam kicauan tersebut
            fprintf(fileBalasan, "\n%d", NUMREP(BALASAN(ELMT(kicauan, i))));
            //untuk menulis tiap balasan (unfinished)

            ListReply temp = LISTREP(balasan);
            printf("neff is %d", NEFFLR(temp));
            for(j = 0; j <= NEFFLR(temp); j++){
                //blm ada untuk menulis 
                //balas-ke-node-mana  id-dari-balasan
                if(!ISUSED(balasan, j)){
                    continue; 
                }
                printf("j is %d", j);
                ReplyAddress kicauBalasan = ADDR(temp, j);
                printf("ini sebelum masuk ALLbalasan\n");
                if(ISMAIN(*kicauBalasan)){
                    TulisAllBalasan(fileBalasan, balasan, &user, j);
                }
                
                // untuk menulis balasan ke dalam file

                // fprintf(fileBalasan, "%s\n", BODY(*kicauBalasan).buffer);
                // fprintf(fileBalasan, "%s\n", ELMT_LISTUSER(user, AUTHORID(*kicauBalasan)).name.buffer);
                // fprintf(fileBalasan, "%s\n", time.buffer);
            }
        }
    }
    fclose(fileBalasan);
}



void SavingFile(String* path, Application *app){
    SavingFilePengguna(path, app->users);
    SavingFileKicauan(path, app->listKicauan, app->users);
    SavingFileDraf(path, app->users);
    SavingFileUtas(path, app->listKicauan, app);
    SavingFileBalasan(path, app->listKicauan, app->users);
}

void SavingFolder(String *path, Application *app) {

    const char *parentPath = "./config/";
    String folderPath; 
    createEmptyString(&folderPath, 100); 
    snprintf(folderPath.buffer, 1000, "%s%s", parentPath, path->buffer);
    if(isExist(&folderPath)){
        printf("Folder sudah ada\n"); 
        printf("Folder akan diperbarui\n");
        SavingFile(&folderPath, app); 
    }
    else{
        printf("Belum terdapat %s. Akan dilakukan pemuatan %s terlebih dahulu\n", path->buffer, path->buffer); 
        printf("Mohon tunggu...\n1...\n2...\n3...\n");
        printf("%s berhasil dibuat\n", path->buffer);
        int result = mkdir(folderPath.buffer, 0777);
        if (!result) {
            printf("%s sudah dibuat\n", path->buffer);
            SavingFile(&folderPath, app);
        } else {
            perror("Error");
        }
    }
}

void SaveFolder(Application *app){
    String path; 
    printf("Masukkan nama folder: ");
    readString(&path, 100);
    SavingFolder(&path, app);
}


// void SavingFilePengguna(String* path, ListUser user){
//     const char *pengguna = "pengguna.config"; 

//     String parentDir; 
//     createEmptyString(&parentDir, 100);

//     snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, pengguna);
//     FILE *filePengguna = fopen(parentDir.buffer, "w");
//     int i = 0; 
//     fprintf(filePengguna, "%d\n", user.length);
//     for(i = 0; i < user.length; i++){
//         fprintf(filePengguna, "%s\n", user.contents[i].name.buffer);
//         fprintf(filePengguna, "%s\n", user.contents[i].password.buffer);
//         fprintf(filePengguna, "%s\n", user.contents[i].profile.bio.buffer);
//         fprintf(filePengguna, "%s\n", user.contents[i].profile.phoneNumber.buffer);
//         fprintf(filePengguna, "%s\n", user.contents[i].profile.weton.buffer);
//         if(user.contents[i].profile.isPrivate){
//             fprintf(filePengguna, "Privat\n");
//         } else fprintf(filePengguna, "Publik\n");

//         int row = user.contents[i].profile.photo.color.rowEff;
//         int col = user.contents[i].profile.photo.color.colEff;
//         int j, k; 
//         for(j = 0; j < row; j++){
//             for(k = 0; k < col; k++){
//                 fprintf(filePengguna, "%c %c ", user.contents[i].profile.photo.color.mem[j][k], user.contents[i].profile.photo.symbols.mem[j][k]);
//             }
//             fprintf(filePengguna, "\n");
//         }
//     }
//     fclose(filePengguna);
// }

// void SavingFileKicauan(String* path, ListKicau kicauan, ListUser user){
//     const char* kicau = "kicauan.config";
//     String Dir; 
//     createEmptyString(&Dir, 100); 
//     snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, kicau);
//     FILE *fileKicauan = fopen(Dir.buffer, "w"); 
//     int i = 0; 
//     fprintf(fileKicauan, "%d\n", kicauan.nEff);
//     for(i = 0; i < kicauan.nEff; ++i){
//         fprintf(fileKicauan, "%d\n", kicauan.buffer[i].IDKicau);
//         fprintf(fileKicauan, "%s\n", kicauan.buffer[i].text.buffer); 
//         fprintf(fileKicauan, "%d\n", kicauan.buffer[i].like); 
//         fprintf(fileKicauan, "%s\n", user.contents[kicauan.buffer[i].IDuser].name.buffer); 
//         fprintf(fileKicauan, "%s\n", kicauan.buffer[i].dateTime.buffer);
//     }
//     fclose(fileKicauan);
// }

// void SavingFileDraf(String* path, ListUser user){
//     const char* draf ="draf.config"; 
//     String Dir; 
//     createEmptyString(&Dir, 100); 
//     snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, draf);
//     FILE* fileDraf = fopen(Dir.buffer, "w"); 
//     int i, j; 
//     int count = 0;
//     for(i = 0; i < user.length; ++i){
//         if(!isDrafDinEmpty(DRAFKICAU(user.contents[i]))){
//             count++;
//         }
//     }
//     fprintf(fileDraf, "%d\n", count); //print berapa banyak yang punya draf;
//     for(i = 0; i < user.length; ++i){
//         if(!isDrafDinEmpty(DRAFKICAU(user.contents[i]))){
//             fprintf(fileDraf, "%s %d\n", user.contents[i].name.buffer, LengthDraf(DRAFKICAU(user.contents[i])));
//         }
//         for(j = 0; j < LengthDraf(DRAFKICAU(user.contents[i])); ++j){
//             AddressDraf temp = ADDR_TOPDRAF(DRAFKICAU(user.contents[i]));
//             fprintf(fileDraf, "%s\n", teksKicau(INFODRAF(temp)).buffer); 
//             fprintf(fileDraf, "%s\n", dateTimeKicau(INFODRAF(temp)).buffer);
//         }
//     }

//     fclose(fileDraf);
// }

// void SavingFileUtas(String *path, ListKicau listKicau, Application *Utas){
//     const char* utas ="utas.config"; 
//     String Dir; 
//     createEmptyString(&Dir, 100); 
//     snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, utas);
//     FILE* fileUtas = fopen(Dir.buffer, "w"); 
//     int i, j; 
//     fprintf(fileUtas, "%d\n", JUMLAHUTAS(*Utas));
//     for(i = 0; i < NEFF(listKicau); i++){
//         if(LEN_ANAKUTAS(ELMT(listKicau, i)) != 0){
//             AddressUtas utas = FIRST(ELMT(listKicau, i));
//             fprintf(fileUtas, "%d\n", IDKicau(ELMT(listKicau, i)));
//             fprintf(fileUtas, "%d\n", LEN_ANAKUTAS(ELMT(listKicau, i)));
//             for(j = 0; j < LEN_ANAKUTAS(ELMT(listKicau, i)); j++){
//                 fprintf(fileUtas, "%s\n", TEKSDIUTAS(utas).buffer); 
//                 fprintf(fileUtas, "%s\n", NAMADIUTAS(utas).buffer); 
//                 fprintf(fileUtas, "%s\n", DATETIMEUTAS(utas).buffer);
//                 utas = NEXT_Linked(utas);
//             }
//         }
//     }
//     fclose(fileUtas);
// }