#ifndef DRAFKICAUDIN_H 
#define DRAFKICAUDIN_H 

#include "../Application.h"
#include "../../../ADT/String/string.h" 
#include "../../DrafDinKicauan.h"
#include "../../User.h"

void SaveDraf(User* user, Kicauan kicau); 

void ChangeDraf(Application* app, User* user, Kicauan tempKicau); 

void DeleteDraf(User* user, Kicauan* sampahKicau); 

void ReleaseDraf(Application* app, Kicauan kicau, int IDUSER); 

void DisplayDraf(Application* app); 

void CreateDraf(Application* app);

#endif 