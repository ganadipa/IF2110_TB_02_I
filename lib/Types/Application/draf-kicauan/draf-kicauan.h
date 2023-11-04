#ifndef DRAFKICAU_H
#define DRAFKICAU_H


#include "Application.h"
#include "../ADT/String/string.h"
#include "../../DrafKicauan.h"

void SimpanDraf(User *app, Kicauan kicau);

void UbahDraf(Application *app, User *user, Kicauan tempKicau);

void HapusDraf(User *app, Kicauan *sampahKicau);

void TerbitkanDraf(Application *app, User *user, Kicauan kicau, int IDUSER);

void LihatDraf(Application *app, User *user);

void BuatDraf(Application *app, User *user);


#endif