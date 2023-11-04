#include <stdio.h>
#include "./User.h"
#include "./Profile.h"


void initializeUser(User *u, String name, String password, int ID)
/**
 * I.S. u sembarang
 * F.S. u memiliki name "name" dan password "password", dan properti sisanya default.
*/
{
    NAME(*u) = name;
    PW(*u) = password;
    ID(*u) = ID;
    initProfile(&PROFILE(*u));
    createRequestQueue(&FRIEND_REQUEST(*u));
    CreateDraf(&DRAFKICAU(*u));
    
}

boolean isUserEqual(User u1, User u2)
/**
 * Mengembalikan true apabila u1 dan u2 memiliki ID yang sama.
*/
{
    return u1.ID == u2.ID;
}

void displayProfile(User u)
/**
 * I.S. user terdefinisi
 * F.S Menampilkan isi profil dari user u
*/
{
    printf("\n| nama: ");
    displayString(NAME(u));
    printf("\n| Bio Akun: ");
    displayString(BIO(PROFILE(u)));
    printf("\n| No HP: ");
    displayString(NOMORHP(PROFILE(u)));
    printf("\n| Weton: ");
    displayString(WETON(PROFILE(u)));
    printf("\n");
}


