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

void SavingFile(String* path, Application *app){
    SavingFilePengguna(path, app->users);
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