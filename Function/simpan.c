#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../ADT/WordMachine/wordmachine.h"
#include "../ADT/boolean.h"

boolean isExist(const char *path){
    DIR* dir = opendir(path); 
    if(dir){
        closedir(dir); 
        return 1; 
    }
    else{
        return 0;
    }
}

void createDirectory(const char *path) {
    char command[200];
    char folderDir[100]; 
    snprintf(folderDir, sizeof(folderDir), "../config/%s", path);
    snprintf(command, sizeof(command), "mkdir %s", folderDir);
    if(isExist(folderDir)){
        printf("Folder sudah ada\n"); 
    }
    else{
        printf("Folder belum ada\n"); 
        system(command);
        printf("Folder berhasil dibuat\n");
    }
}


void SaveFolder(){
    printf("Masukkan nama folder: ");
    char path[100];  
    scanf("%s", path);
    createDirectory(path);
}


void SavingFile(const char *path){
    FILE *file = fopen(path, "w"); 
    if(file == NULL){
        perror("file tidak bisa dibuka"); 
        return; 
    }
    fprintf(file, "Ini contoh nyimpan file");
    fclose(file); 
    printf("File berhasil disimpan"); 
}



int main(){
    SaveFolder(); 
    return 0; 
}


