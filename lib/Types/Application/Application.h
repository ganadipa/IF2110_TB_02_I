
#ifndef APPLICATION_H
#define APPLICATION_H

#include "../../boolean.h"
#include "../ListUser.h"
#include "../../ADT/Graf/graf.h"
#include "../listKicauan.h"
#include "../RequestQueue.h"



typedef struct application {
    boolean isLoggedIn;
    int loginID;
    ListUser users; // Used list dengan array statik
    Graf friendships;
    ListKicau listKicauan;
    int JumlahKicauTOTAL;
} Application;

#define LOGGEDIN(a) (a).isLoggedIn
#define LISTUSER(a) (a).users
#define LOGINID(a) (a).loginID
#define FRIENDSHIPS(a) (a).friendships
#define KICAUAN(a)  (a).listKicauan
#define JUMLAHTOTALKICAU(a) (a).JumlahKicauTOTAL;

void DevTools(Application app);
/**
 * JANGAN LUPA DIAPUS
*/

#endif