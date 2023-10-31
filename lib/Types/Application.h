
#ifndef APPLICATION_H
#define APPLICATION_H

#include "../boolean.h"
#include "./ListUser.h"
#include "../ADT/Graf/graf.h"




typedef struct application {
    boolean isLoggedIn;
    int loginID;
    ListUser users; // Used list dengan array statik
    Graf friendships;
} Application;

#define LOGGEDIN(a) (a).isLoggedIn
#define LISTUSER(a) (a).users
#define LOGINID(a) (a).loginID
#define FRIENDSHIPS(a) (a).friendships

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
void AturJenisAkun(Application *app);
/**
 * I.S. app sudah terinisialisasi. IsLoggedIn belum tentu true
 * F.S. Mengubah isPrivate User dengan ID == loginID sesuai input.
*/

void DaftarTeman(Application app);
/**
 * 
*/


void DevTools(Application app);
/**
 * JANGAN LUPA DIAPUS
*/

#endif