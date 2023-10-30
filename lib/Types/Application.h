
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

void TutupProgram(Application *app, boolean *finish);
/**
 * I.S. app sudah terinisialisasi
 * F.S. program ditutup tanpa menyimpan apapun dari app.
*/

void GantiProfil(Application *app);
/**
 * I.S. app suadah terinisialisasi, isLoggedIn belum tentu true;
 * F.S. Profil dari id "loginID" diperbarui
*/

void LihatProfil(Application *app, String name);
/**
 * I.S. app sudah terinisialisasi. isLoggedIn belum tentu true;
 * F.S. Menampilkan full profile dari name.
*/

void DevTools(Application app);
/**
 * JANGAN LUPA DIAPUS
*/

#endif