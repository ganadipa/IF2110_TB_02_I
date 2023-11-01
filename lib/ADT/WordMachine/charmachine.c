/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>

char currentChar_WordMachine;
boolean EOP_WordMachine;

static FILE *pita;
static int retval;

void START(int mode)
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : pita terbuka*/

       /* Algoritma */
       pita = stdin;
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar_WordMachine);
       EOP_WordMachine = (currentChar_WordMachine == MARK_WordMachine);
}

void CLOSE() {
       fclose(pita);
}
