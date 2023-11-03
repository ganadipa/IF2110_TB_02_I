#ifndef KICAU_H
#define KICAU_H

#include "../../../ADT/String/string.h"
#include "../Application.h"
#include "../../Kicauan.h"

boolean isFriend ( Application *app, int CurrentID, int friendID);

String returnUsername (Application app ,int  UserID);


void Kicau(Application *app);

void TampilinKicauan(Application *app);
/**
 * Untuk Menampilkan kicauan berdasarkan Pertemanan dari user
 */

 


void SukaKicauan(Application *app, int ID);


/**
 * Untuk Menambah jumlah like pada Kicauan dengan id "ID"
*/

void UbahKicauan(Application *app, int ID);
#endif
