#ifndef INISIALISASI_H
#define INISIALISASI_H
#include "../Application.h"

void AppInitialization(Application *app);
/**
 * I.S. Program baru dimulai.
 * F.S. Output UI CLI dan menampung data-data yang ada pada config yang telah dimasukkan.
*/

void Opening();

void Setup(Application *app);

void ReadConfig(Application *app, boolean *found);

#endif