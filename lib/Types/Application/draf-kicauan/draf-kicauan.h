#ifndef DRAFKICAU_H
#define DRAFKICAU_H


#include "../Application.h"
#include "../../../ADT/String/string.h"
#include "../../DrafKicauan.h"
#include "../../User.h"

void SimpanDraf(User* user, Kicauan kicau);

void UbahDraf(Application* app, User* user, Kicauan tempKicau);

void HapusDraf(User* user, Kicauan *sampahKicau);

void TerbitkanDraf(Application *app, Kicauan kicau, int IDUSER);

void LihatDraf(Application *app);

void BuatDraf(Application *app);


#endif