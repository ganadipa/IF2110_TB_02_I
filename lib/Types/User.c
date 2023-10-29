#include <stdio.h>
#include "./User.h"


void initializeUser(User *u, String name, String password, int ID)
/**
 * I.S. u sembarang
 * F.S. u memiliki name "name" dan password "password", dan properti sisanya default.
*/
{
    NAME(*u) = name;
    PW(*u) = password;
    ID(*u) = ID;
}

boolean isUserEqual(User u1, User u2)
/**
 * Mengembalikan true apabila u1 dan u2 memiliki ID yang sama.
*/
{
    return u1.ID == u2.ID;
}


