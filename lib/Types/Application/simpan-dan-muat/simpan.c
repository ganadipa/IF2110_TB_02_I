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
            fprintf(fileDraf, "%s %d\n", user.contents[i].name.buffer, LengthDraf(DRAFKICAU(user.contents[i])));
        }
        for(j = 0; j < LengthDraf(DRAFKICAU(user.contents[i])); ++j){
            AddressDraf temp = ADDR_TOPDRAF(DRAFKICAU(user.contents[i]));
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
                fprintf(fileUtas, "%s\n", TEKSDIUTAS(utas).buffer); 
                fprintf(fileUtas, "%s\n", NAMADIUTAS(utas).buffer); 
                fprintf(fileUtas, "%s\n", DATETIMEUTAS(utas).buffer);
                utas = NEXT_Linked(utas);
            }
        }
    }
    fclose(fileUtas);
}

void SavingFileBalasan(String *path, ListKicau kicauan){
    const char* reply = "balasan.config"; 
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, reply); 
    FILE *fileBalasan = fopen(Dir.buffer, "w"); 
    
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


// void SavingFile(String* path, Application *app){
//     const char *pengguna = "pengguna.config";
//     const char *kicauan = "kicauan.config";
//     const char *balasan = "balasan.config";
//     const char *draf = "draf.config";
//     const char *utas = "utas.config";

//     String parentDir; 
//     createEmptyString(&parentDir, 100);

//     snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, kicauan);
//     FILE *fileKicauan = fopen(parentDir.buffer, "w");
//     // Write to the file
//     if (fileKicauan != NULL) {
//         fprintf(fileKicauan, "kicauan.config.\n");
//         fclose(fileKicauan);
//     }

//     snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, draf);
//     FILE *fileDraf = fopen(parentDir.buffer, "w");
//     if (fileDraf != NULL) {
//         fprintf(fileDraf, "draf.config.\n");
//         fclose(fileDraf);
//     }

//     snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, pengguna);
//     FILE *filePengguna = fopen(parentDir.buffer, "w");
//     if (filePengguna != NULL) {
//         fprintf(filePengguna, "pengguna.config.\n");
//         fclose(filePengguna);
//     }

//     snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, utas);
//     FILE *fileUtas = fopen(parentDir.buffer, "w");
//     if (fileUtas != NULL) {
//         fprintf(fileUtas, "utas.config.\n");
//         fclose(fileUtas);
//     }

//     snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, balasan);
//     FILE *fileBalasan = fopen(parentDir.buffer, "w");
//     if (fileBalasan != NULL) {
//         fprintf(fileBalasan, "balasan.config.\n");
//         fclose(fileBalasan);
//     }
// }