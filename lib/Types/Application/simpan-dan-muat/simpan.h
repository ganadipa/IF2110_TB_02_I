#ifndef _SIMPAN_h
#define _SIMPAN_h 

#include <stdio.h>
// #include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../../../lib.h"
#include "../Application.h"
#include "../../../ADT/WordMachine/wordmachine.h"


boolean isExist(String* path);
/*Mengecek apakah folder ada atau tidak*/

void SavingFilePengguna(String* path, ListUser user, Application app);
/*Menyimpan file pengguna.config*/

void SavingFile(String* path, Application*app);
/*Membuat file .config di dalam directory*/

void SavingFolder(String* path, Application* app);
/*Membuat folder untuk menyimpan .config*/

void SaveFolder(Application *app);

#endif
