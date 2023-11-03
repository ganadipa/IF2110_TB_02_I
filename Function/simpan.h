#ifndef _SIMPAN_h
#define _SIMPAN_h 

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../lib/lib.h"

boolean isExist(String* path);
void SavingFile(String* path);
void SavingFolder(String* path);
void SaveFolder();

#endif
