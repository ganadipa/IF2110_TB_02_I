/* File: charmachinefile.c */

#include <stdio.h>
#include "charmachinefile.h"
#include "../../lib.h"

FILE *pitafile;
int retvalfile;
char currentCharFile;
boolean EOP_FILE;
boolean EndFile = false;
const char source[50] = "./config/folder1/";
void OPENFILE(String filename)
{   
    String s;
    retvalfile = 0;
    currentCharFile = '\0';
    addChartoChar(s.buffer, source);
    s.maxLength = STRCAP;
    addString(&s, filename);
    pitafile = fopen(s.buffer, "r");
    if (pitafile == NULL){
        printf("File %s gagal dibuka\n", filename.buffer);
        EndFile = true;
    }
    
    
}

void CLOSEFILE() {
    fclose(pitafile);
}

void ADVCHARFILE()
{
    retvalfile = fscanf(pitafile, "%c", &currentCharFile);
    EOP_FILE = (currentCharFile == MARK_LAST_FILE);
}

