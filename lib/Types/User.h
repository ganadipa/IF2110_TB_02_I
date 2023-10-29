
#ifndef USER_H
#define USER_H

#include "../boolean.h"
#include "../ADT/String/string.h"

#define USERCAP 20;
#define ID_UNDEF -1;

typedef struct user {
    int ID;
    String name;
    String password;
} User;


#define ID(u) (u).ID
#define NAME(u) (u).name
#define PW(u) (u).password

void initializeUser(User *u, String name, String password, int ID);
/**
 * I.S. u sembarang
 * F.S. u memiliki name "name" dan password "password", dan properti sisanya default.
*/

boolean isUserEqual(User u1, User u2);
/**
 * Mengembalikan true apabila u1 dan u2 memiliki seluruh properti yang sama.
*/

#endif