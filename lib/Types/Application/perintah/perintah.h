#ifndef PERINTAH_H
#define PERINTAH_H

#include "../Application.h"
#include "../balasan/balasan.h"
#include "../draf-kicauan/draf-kicauan-din.h"
#include "../inisialisasi/inisialisasi.h"
#include "../kicauan/kicauan.h"
#include "../pengguna/pengguna.h"
#include "../profil/profil.h"
#include "../simpan-dan-muat/simpan.h"
#include "../simpan-dan-muat/muat.h"
#include "../permintaan-pertemanan/permintaan-pertemanan.h"
#include "../teman/teman.h"
#include "../utas/utas.h"
#include "../Devtools.h"

void handleCommand(Application* app, String command, boolean *finish);

#endif