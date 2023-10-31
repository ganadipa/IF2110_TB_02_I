#include "simpan.h"


boolean isExist(String *path){
    DIR* dir = opendir(path->buffer); 
    if(dir){
        closedir(dir); 
        return 1; 
    }
    else{
        return 0;
    }
}

void SavingFile(String* path){
    const char *pengguna = "pengguna.config";
    const char *kicauan = "kicauan.config";
    const char *balasan = "balasan.config";
    const char *draf = "draf.config";
    const char *utas = "utas.config";

    String parentDir; 
    createEmptyString(&parentDir, 100);

    snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, kicauan);
    FILE *fileKicauan = fopen(parentDir.buffer, "w");
    // Write to the file
    if (fileKicauan != NULL) {
        fprintf(fileKicauan, "kicauan.config.\n");
        fclose(fileKicauan);
    }

    snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, draf);
    FILE *fileDraf = fopen(parentDir.buffer, "w");
    if (fileDraf != NULL) {
        fprintf(fileDraf, "draf.config.\n");
        fclose(fileDraf);
    }

    snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, pengguna);
    FILE *filePengguna = fopen(parentDir.buffer, "w");
    if (filePengguna != NULL) {
        fprintf(filePengguna, "pengguna.config.\n");
        fclose(filePengguna);
    }

    snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, utas);
    FILE *fileUtas = fopen(parentDir.buffer, "w");
    if (fileUtas != NULL) {
        fprintf(fileUtas, "utas.config.\n");
        fclose(fileUtas);
    }

    snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, balasan);
    FILE *fileBalasan = fopen(parentDir.buffer, "w");
    if (fileBalasan != NULL) {
        fprintf(fileBalasan, "balasan.config.\n");
        fclose(fileBalasan);
    }
}

void SavingFolder(String *path) {

    const char *parentPath = "./config/";
    String folderPath; 
    createEmptyString(&folderPath, 100); 
    snprintf(folderPath.buffer, 1000, "%s%s", parentPath, path->buffer);
    if(isExist(&folderPath)){
        printf("Folder sudah ada\n"); 
        SavingFile(&folderPath); 
    }
    else{
        printf("Belum terdapat %s. Akan dilakukan pemuatan %s terlebih dahulu\n", path->buffer, path->buffer); 
        printf("Mohon tunggu...\n1...\n2...\n3...\n");
        printf("%s berhasil dibuat\n", path->buffer);
        int result = mkdir(folderPath.buffer, 0777);
        if (!result) {
            printf("%s sudah dibuat\n", path->buffer);
            SavingFile(&folderPath);
        } else {
            perror("Error");
        }
    }
}

void SaveFolder(){
    String path; 
    printf("Masukkan nama folder: ");
    readString(&path, 100);
    SavingFolder(&path);
}

