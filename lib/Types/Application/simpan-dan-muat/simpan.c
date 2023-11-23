#include "simpan.h"


boolean isExist(String *path){
    struct stat buffer;
    return (stat(path->buffer, &buffer) == 0);
}

void tulisGrafPertemanan(FILE* filepath, Graf graf){
    int i, j;
    for (i = 0; i < NUMVERTICES(graf); i++) {
        fprintf(filepath, "\n");
        for (j = 0; j < NUMVERTICES(graf); j++) {
            fprintf(filepath, "%d", CONNECTED(graf, i , j));
            if(j != NUMVERTICES(graf) - 1) {
                fprintf(filepath, " ");
            }
        }
    }
}

void SavingFilePengguna(String* path, ListUser user, Application app){
    const char *pengguna = "pengguna.config"; 

    String parentDir; 
    createEmptyString(&parentDir, 100);

    snprintf(parentDir.buffer, 1000, "%s/%s", path->buffer, pengguna);
    FILE *filePengguna = fopen(parentDir.buffer, "w");
    int i = 0; 
    int totalPermintaan = 0;
    fprintf(filePengguna, "%d", user.length);
    if(user.length > 0){
        for(i = 0; i < user.length; i++){
            deleteRest(&user.contents[i].name);
            deleteRest(&user.contents[i].password);
            deleteRest(&user.contents[i].profile.bio);
            deleteRest(&user.contents[i].profile.phoneNumber);
            deleteRest(&user.contents[i].profile.weton);
            fprintf(filePengguna, "\n%s", user.contents[i].name.buffer);
            fprintf(filePengguna, "\n%s", user.contents[i].password.buffer);
            fprintf(filePengguna, "\n%s", user.contents[i].profile.bio.buffer);
            fprintf(filePengguna, "\n%s", user.contents[i].profile.phoneNumber.buffer);
            fprintf(filePengguna, "\n%s", user.contents[i].profile.weton.buffer);
            if(user.contents[i].profile.isPrivate){
                fprintf(filePengguna, "\nPrivat");
            } else fprintf(filePengguna, "\nPublik");

            int row = user.contents[i].profile.photo.color.rowEff;
            int col = user.contents[i].profile.photo.color.colEff;
            int j, k;

            for(j = 0; j < row; j++){
                fprintf(filePengguna, "\n");
                for(k = 0; k < col; k++){
                    fprintf(filePengguna, "%c %c ", user.contents[i].profile.photo.color.mem[j][k], user.contents[i].profile.photo.symbols.mem[j][k]);
                }
                
            }
            totalPermintaan += lengthRequestQueue(user.contents[i].friendRequest);
            //tulis matrix jumlah permintaan teman 
        }
        tulisGrafPertemanan(filePengguna, FRIENDSHIPS(app));
        fprintf(filePengguna, "\n%d", totalPermintaan);
        int count = 0; 
        for(i = 0; i < user.length; i++){
            if(lengthRequestQueue(user.contents[i].friendRequest) != 0){
                int j;
                User u = user.contents[i];
                RequestQueue rq = FRIEND_REQUEST(u);
                int IDaccept = u.ID;
                for(j = 0; j < lengthRequestQueue(rq); j++){
                    count++;
                    int IDrequest = ELMT_ReqQue(rq, j).userID;
                    fprintf(filePengguna, "\n%d %d %d", IDrequest, IDaccept, user.contents[IDrequest].friendCount);
                }
            }
        }
    }
    fclose(filePengguna);
}

void SavingFileKicauan(String* path, ListKicau kicauan, ListUser user){
    const char* kicau = "kicauan.config";
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, kicau);
    FILE *fileKicauan = fopen(Dir.buffer, "w"); 
    int i = 0; 
    fprintf(fileKicauan, "%d", kicauan.nEff);
    for(i = 0; i < kicauan.nEff; ++i){
        deleteRest(&kicauan.buffer[i].text);
        deleteRest(&user.contents[kicauan.buffer[i].IDuser].name);
        deleteRest(&kicauan.buffer[i].dateTime);
        fprintf(fileKicauan, "\n%d", kicauan.buffer[i].IDKicau);
        fprintf(fileKicauan, "\n%s", kicauan.buffer[i].text.buffer); 
        fprintf(fileKicauan, "\n%d", kicauan.buffer[i].like);
        fprintf(fileKicauan, "\n%s", user.contents[kicauan.buffer[i].IDuser].name.buffer); 
        fprintf(fileKicauan, "\n%s", kicauan.buffer[i].dateTime.buffer);   
        
    }
    fclose(fileKicauan);
}

void SavingFileDraf(String* path, ListUser user){
    const char* draf ="draf.config"; 
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, draf);
    FILE* fileDraf = fopen(Dir.buffer, "w"); 
    int i, j; 
    int count = 0;
    for(i = 0; i < user.length; ++i){
        if(!isDrafDinEmpty(DRAFKICAU(user.contents[i]))){
            count++;
        }
    }
    fprintf(fileDraf, "%d", count); //print berapa banyak yang punya draf;
    for(i = 0; i < user.length; ++i){
        if(!isDrafDinEmpty(DRAFKICAU(user.contents[i]))){
            deleteRest(&user.contents[i].name);
            fprintf(fileDraf, "\n%s %d", user.contents[i].name.buffer, LengthDraf(DRAFKICAU(user.contents[i])));
        }
        for(j = 0; j < LengthDraf(DRAFKICAU(user.contents[i])); ++j){
            AddressDraf temp = ADDR_TOPDRAF(DRAFKICAU(user.contents[i]));
            deleteRest(&teksKicau(INFODRAF(temp)));
            deleteRest(&dateTimeKicau(INFODRAF(temp)));
            fprintf(fileDraf, "\n%s", teksKicau(INFODRAF(temp)).buffer); 
            fprintf(fileDraf, "\n%s", dateTimeKicau(INFODRAF(temp)).buffer);
        }
    }

    fclose(fileDraf);
}

void SavingFileUtas(String *path, ListKicau listKicau, Application *Utas){
    const char* utas ="utas.config"; 
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, utas);
    FILE* fileUtas = fopen(Dir.buffer, "w"); 
    int i, j; 
    fprintf(fileUtas, "%d", JUMLAHUTAS(*Utas));
    for(i = 0; i < NEFF(listKicau); i++){
        if(IDUTAS(ELMT(listKicau, i)) != 0){
            AddressUtas utas = FIRST(ELMT(listKicau, i));
            fprintf(fileUtas, "\n%d", IDKicau(ELMT(listKicau, i)));
            fprintf(fileUtas, "\n%d", LEN_ANAKUTAS(ELMT(listKicau, i)));
            for(j = 0; j < LEN_ANAKUTAS(ELMT(listKicau, i)); j++){
                deleteRest(&TEKSDIUTAS(utas));
                deleteRest(&NAMADIUTAS(utas));
                deleteRest(&DATETIMEUTAS(utas));
                fprintf(fileUtas, "\n%s", TEKSDIUTAS(utas).buffer); 
                fprintf(fileUtas, "\n%s", NAMADIUTAS(utas).buffer); 
                fprintf(fileUtas, "\n%s", DATETIMEUTAS(utas).buffer);
            
                utas = NEXT_Linked(utas);
            }
        }
    }
    fclose(fileUtas);
}

void TulisBalasan(FILE* filepath, ReplyTree rt, ReplyAddress addr, ListUser *l){
    int i = getIdxInReplyTree(rt, addr); 
    if(!ISUSED(rt, i)) return;

    Reply rep = *addr; 
    int currID = REPLYID(rep);
    int parentID = PARENT(rt, currID);
    User user = ELMT_LISTUSER(*l, AUTHORID(rep));
    String time = DateTimeToString(DTIME(rep)); 
    String Text = BODY(rep);

    fprintf(filepath, "\n%d %d", parentID, currID); 
    fprintf(filepath, "\n%s", Text.buffer); 
    fprintf(filepath, "\n%s", user.name.buffer);
    fprintf(filepath, "\n%s", time.buffer);
}

void TulisAllBalasan(FILE* filepath, ReplyTree rt, ListUser *l, int idx){
    ListDin adjlist = LISTDIN(rt, idx); 
    ReplyAddress ra = ADDR(LISTREP(rt), idx); 
    int neff = NEFF(adjlist); 
    int i; 
    TulisBalasan(filepath, rt, ra, l); 
    for(i = 0; i < neff; i++){
        TulisAllBalasan(filepath, rt, l, adjlist.buffer[i]);
    }

}

void SavingFileBalasan(String *path, ListKicau kicauan, ListUser user){
    const char* reply = "balasan.config"; 
    String Dir; 
    createEmptyString(&Dir, 100); 
    snprintf(Dir.buffer, 1000, "%s/%s", path->buffer, reply); 
    FILE *fileBalasan = fopen(Dir.buffer, "w");
    int i, j, totalBalasan = 0; 
    for(i = 0; i < NEFF(kicauan); i++){
        if(NUMREP(BALASAN(ELMT(kicauan, i))) != 0){
            totalBalasan++;
        }
    }

    fprintf(fileBalasan, "%d", totalBalasan);
    for(i = 0; i < NEFF(kicauan); i++){
        ReplyTree balasan = BALASAN(ELMT(kicauan, i));

        if(NUMREP(balasan) != 0){ ;
            //untuk menulis ID dari kicau yang memiliki balasan 
            fprintf(fileBalasan, "\n%d", IDKicau(ELMT(kicauan, i)));
            //untuk menulis banyaknya balasan dalam kicauan tersebut
            fprintf(fileBalasan, "\n%d", NUMREP(BALASAN(ELMT(kicauan, i))));
            //untuk menulis tiap balasan (unfinished)

            ListReply temp = LISTREP(balasan);
            for(j = 0; j <= NEFFLR(temp); j++){
                //blm ada untuk menulis 
                //balas-ke-node-mana  id-dari-balasan
                if(!ISUSED(balasan, j)){
                    continue; 
                }
                ReplyAddress kicauBalasan = ADDR(temp, j);
                if(ISMAIN(*kicauBalasan)){
                    TulisAllBalasan(fileBalasan, balasan, &user, j);
                }
            }
        }
    }
    fclose(fileBalasan);
}

void SavingFile(String* path, Application *app){
    SavingFilePengguna(path, app->users, *app);
    SavingFileKicauan(path, app->listKicauan, app->users);
    SavingFileDraf(path, app->users);
    SavingFileUtas(path, app->listKicauan, app);
    SavingFileBalasan(path, app->listKicauan, app->users);
}

void SavingFolder(String *path, Application *app) {

    const char *parentPath = "./config/";
    String folderPath; 
    createEmptyString(&folderPath, 100); 
    snprintf(folderPath.buffer, 1000, "%s%s", parentPath, path->buffer);
    if(isExist(&folderPath)){
        printf("Folder sudah ada\n"); 
        printf("Folder akan diperbarui\n");
        SavingFile(&folderPath, app); 
    }
    else{
        printf("Belum terdapat %s. Akan dilakukan pemuatan %s terlebih dahulu\n", path->buffer, path->buffer); 
        printf("Mohon tunggu...\n1...\n2...\n3...\n");
        printf("%s berhasil dibuat\n", path->buffer);
        int result = mkdir(folderPath.buffer, 0777);
        if (!result) {
            printf("%s sudah dibuat\n", path->buffer);
            SavingFile(&folderPath, app);
        } else {
            perror("Error");
        }
    }
}

void SaveFolder(Application *app){
    String path; 
    printf("Masukkan nama folder: ");
    readString(&path, 100);
    SavingFolder(&path, app);
}

