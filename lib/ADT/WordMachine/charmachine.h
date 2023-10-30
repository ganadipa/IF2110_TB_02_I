/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __CHAR_MACHINE_H__
#define __CHAR_MACHINE_H__

#include "../../boolean.h"

#define MARK_WordMachine ';'
/* State Mesin */
extern char currentChar_WordMachine;
extern boolean EOP_WordMachine;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void CLOSE();
/**
 * I.S. Pita terbuka
 * F.S. Pita tertutup
*/
#endif