#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "../Application.h"

void Daftar(Application *app);
/**
 * I.S. app sudah terinisialisasi.
 * F.S. Menambahkan user ke dalam database.
*/

void Masuk(Application *app);
/**
 * I.S. app sudah terinisialisasi.
 * F.S. Jika belum login, tampilkan menu untuk login.
 *          Jika berhasil login, loginID ter-set dan isLoggedIn menjadi true;
 *      Jika sudah login, tampilkan pesan bahwa sudah login. 
*/

void Keluar(Application *app) ;



void TutupProgram(Application *app, boolean  *finish);


#endif