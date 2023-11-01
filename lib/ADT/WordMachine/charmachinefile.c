/* File: charmachinefile.c */

#include <stdio.h>
#include "charmachinefile.h"
#include "../../lib.h"

static FILE *pitafile[5];
static int retvalfile;
static char file[50][50] = {"pengguna.config", "kicauan.config", "balasan.config", "draf.config", "utas.config"};
char currentCharFile;
boolean EOP_FILE;

void OPENFILE()
{   
    
    pitafile[0] = fopen("../config/folder1/pengguna.config", "r");
    if (pitafile[0] == NULL){
        printf("File %s gagal dibuka\n", file[0]);
    }
    
    
}

void CLOSEFILE() {
    for (int i = 0; i < 5 ; i++){
        fclose(pitafile[i]);
    }
}

void ADVCHARFILE()
{
    retvalfile = fscanf(pitafile[0], "%c", &currentCharFile);
    EOP_FILE = (currentCharFile == MARK_LAST_FILE);
}

