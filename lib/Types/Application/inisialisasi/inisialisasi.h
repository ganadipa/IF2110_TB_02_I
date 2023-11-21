#ifndef INISIALISASI_H
#define INISIALISASI_H
#include "../Application.h"
#include "../../../lib.h"

void AppInitialization(Application *app);
/**
 * I.S. Program baru dimulai.
 * F.S. Output UI CLI dan menampung data-data yang ada pada config yang telah dimasukkan.
*/

void Opening();

void Setup(Application *app);

void ReadConfig(Application *app, boolean *found);

void LoadPengguna(Application *app, String pathfilefolder);

void LoadKicauan(Application *app, String pathfilefolder);

void LoadDraft(Application *app, String pathfilefolder);

void LoadBalasan(Application *app, String pathfilefolder);

void LoadUtas(Application *app, String pathfilefolder);
#endif