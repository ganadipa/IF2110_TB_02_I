#include "simpan.h"


boolean isExist(String *path){
    struct stat buffer;
    return (stat(path->buffer, &buffer) == 0);
}

void TulisFile(FILE* filename, String kata){
    int i; 
    int len = kata.maxLength; 
    for(i = 0; i < len; i++){
        fprintf(filename, "%c", kata.buffer[i]);
    }
}

void deleteRest(String *string){
    string->buffer[string->maxLength] = '\0';
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
        fprintf(fileKicauan, "%s\n", kicauan.buffer[i].dateTime.buffer);
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
    fprintf(fileDraf, "%d\n", count); //print berapa banyak yang punya draf;
    for(i = 0; i < user.length; ++i){
        if(!isDrafDinEmpty(DRAFKICAU(user.contents[i]))){
            deleteRest(&user.contents[i].name);
            fprintf(fileDraf, "%s %d\n", user.contents[i].name.buffer, LengthDraf(DRAFKICAU(user.contents[i])));
        }
        for(j = 0; j < LengthDraf(DRAFKICAU(user.contents[i])); ++j){
            AddressDraf temp = ADDR_TOPDRAF(DRAFKICAU(user.contents[i]));
            deleteRest(&teksKicau(INFODRAF(temp)));
            deleteRest(&dateTimeKicau(INFODRAF(temp)));
            fprintf(fileDraf, "%s\n", teksKicau(INFODRAF(temp)).buffer); 
            fprintf(fileDraf, "%s\n", dateTimeKicau(INFODRAF(temp)).buffer);
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
                fprintf(fileUtas, "%s\n", TEKSDIUTAS(utas).buffer); 
                fprintf(fileUtas, "%s\n", NAMADIUTAS(utas).buffer); 
                fprintf(fileUtas, "%s\n", DATETIMEUTAS(utas).buffer);
                utas = NEXT_Linked(utas);
            }
        }
    }
    fclose(fileUtas);
}

void SavingFileBalasan(String *path, ListKicau kicauan, ListUser user){
    const char* reply = "balasan.config"; 
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, reply); 
    FILE *fileBalasan = fopen(Dir.buffer, "w");
    int i, j, k, totalBalasan = 0; 
    for(i = 0; i < NEFF(kicauan); i++){
        if(&BALASAN(ELMT(kicauan, i)) != NULL){
            totalBalasan++;
        }
    }

    fprintf(fileBalasan, "%d\n", totalBalasan);
    for(i = 0; i < NEFF(kicauan); i++){
        if(&BALASAN(ELMT(kicauan, i)) != NULL){
            fprintf(fileBalasan, "%d\n", kicauan.buffer[i].IDKicau);
            fprintf(fileBalasan, "%d\n", NUMREP(BALASAN(ELMT(kicauan, i))));
            for(j = 0; j < NUMREP(BALASAN(ELMT(kicauan, i))); j++){
                for(k = 0; k < NEFFLR(LISTREP(BALASAN(ELMT(kicauan, i)))); k++){
                    int IDparent = generateReplyID(BALASAN(ELMT(kicauan, j)));
                    fprintf(fileBalasan, "%d %d\n", IDparent, k);
                    ReplyAddress kicauBalasan = ADDR(LISTREP(BALASAN(ELMT(kicauan, j))), k);
                    String time = DateTimeToString(kicauBalasan->time);
                    fprintf(fileBalasan, "%s\n", ELMT_LISTUSER(user, kicauBalasan->authorID).name);
                    fprintf(fileBalasan, "%s\n", time.buffer);
                }
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
}

void SavingFolder(String *path, Application *app) {

    const char *parentPath = "./config/";
    String folderPath; 
    createEmptyString(&folderPath, 100); 
    snprintf(folderPath.buffer, 1000, "%s%s", parentPath, path->buffer);
    if(isExist(&folderPath)){
        printf("Folder sudah ada\n"); 
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