/* File: charmachineload.h */

#ifndef __CHAR_MACHINE_FILE_H__
#define __CHAR_MACHINE_FILE_H__

#include "../../lib.h"
#include "../../boolean.h"

#define MARK_LAST_FILE '\n'
/* State Mesin */
extern char currentCharFile;
extern boolean EOP_FILE;
extern boolean EndFile;
extern int retvalfile;

void OPENFILE(String filename);
void CLOSEFILE();
// void READFILE();
void ADVCHARFILE();
#endif