#ifndef DRAFKICAU_H
#define DRAFKICAU_H


#include "../Application.h"
#include "../ADT/String/string.h"
#include "../../DrafKicauan.h"

void SimpanDraf(Application *app, Kicauan kicau);

void UbahDraf(Application *app, Kicauan tempKicau);

void HapusDraf(Application *app, Kicauan *sampahKicau);

void TerbitkanDraf(Application *app, Kicauan kicau, int IDUSER);

void LihatDraf(Application *app);

void BuatDraf(Application *app);


#endif