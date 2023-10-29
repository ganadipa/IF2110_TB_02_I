
#ifndef APPLICATION_H
#define APPLICATION_H

#include "../boolean.h"
#include "./ListUser.h"





typedef struct application {
    boolean isLoggedIn;
    ListUser users;
    int loginID;
} Application;

#define isLoggedIn(a) (a).isLoggedIn
#define ListUser(a) (a).users
#define loginID(a) (a).loginID

void AppInitialization(Application *app);
/**
 * I.S. Program baru dimulai.
 * F.S. Output UI CLI dan menampung data-data yang ada pada config yang telah dimasukkan.
*/

void Daftar(Application *app);
/**
 * I.S. app sudah terinisialisasi.
 * F.S. Menambahkan user ke dalam database.
*/


void Masuk(Application *app);
/**
 * I.S. app sudah terinisialisasi
 * F.S. app memasuki mode loggedIn.
*/

void Keluar(Application *app);
/**
 * I.S. app sudah terinisialisasi
 * F.S. app memasuki mode tak loggedIn.
*/

#endif