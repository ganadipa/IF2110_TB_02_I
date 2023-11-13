#include <stdio.h>
#include "./ListUser.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListUser(ListUser *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Set length = 0 */
{
    LENGTH_LISTUSER(*l) = 0;
}



/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListUser(ListUser l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return 0 <= i && i <= CAPACITY_ListUser;

}
boolean isIdxEff_ListUser(ListUser l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return 0 <= i && i<= LENGTH_LISTUSER(l) -1;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty_ListUser(ListUser l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return LENGTH_LISTUSER(l) == 0;
}
/* *** Test List penuh *** */
boolean isFull_ListUser(ListUser l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return LENGTH_LISTUSER(l) == CAPACITY_ListUser;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf_ListUser(ListUser l, User val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    return val.ID;
}


/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst_ListUser(ListUser *l, User val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
{
    insertAt_ListUser(l, val, 0);
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt_ListUser(ListUser *l, User val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l*/
/* *** Menambahkan elemen terakhir *** */
{
    int i = LENGTH_LISTUSER(*l);
    for (i = LENGTH_LISTUSER(*l); i >= idx + 1; i--) {
        ELMT_LISTUSER(*l, i-1) = ELMT_LISTUSER(*l, i);  
    }

    ELMT_LISTUSER(*l, idx) = val;
    LENGTH_LISTUSER(*l)++;
}
void insertLast_ListUser(ListUser *l, User val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT_LISTUSER(*l, LENGTH_LISTUSER(*l)) = val;
    LENGTH_LISTUSER(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst_ListUser(ListUser *l, User *val){
    deleteAt_ListUser(l, val, 0);
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt_ListUser(ListUser *l, User *val, IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT_LISTUSER(*l, idx);
    for (idx = idx; idx < LENGTH_LISTUSER(*l); idx++) {
        ELMT_LISTUSER(*l, idx) = ELMT_LISTUSER(*l, idx+1); 
    }
    LENGTH_LISTUSER(*l)--;
}

/* *** Menghapus elemen terakhir *** */
void deleteLast_ListUser(ListUser *l, User *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    deleteLast_ListUser(l, val);
}

IdxType searchByName(ListUser l, String name)
/**
 * Mengembalikan true apabila u1 dan u2 memiliki seluruh properti yang sama.
*/
{
    int i = 0;
    int length = LENGTH_LISTUSER(l);
    boolean found = false;
    while (i < length && !found) {
        if (isStringEqual(ELMT_LISTUSER(l,i).name, name)) found = true;
        else {
            i++;
        }
    }

    if (found) return i;
    else return IDX_UNDEF;
}

void displayName(ListUser l, int i) 
/**
 * I.S. i dan l terdefinisi sertva valid.
*/
{  
    displayString(NAME(ELMT_LISTUSER(l, i)));
}

void displayRequestQueue(RequestQueue Q, ListUser l)

{
    int nb = lengthRequestQueue(Q);
    printf("\nTerdapat %d permintaan pertemanan untuk Anda.\n", nb);

    while (!isEmptyRequestQueue(Q))
    {
        Friend F;
        dequeueRequestQueue(&Q, &F);
        User u = ELMT_LISTUSER(l, ID_REQQUEUE(F));
        printf("\n | Nama: ");
        displayString(NAME(u));
        printf("\n | Jumlah teman: %d\n", FRIEND_COUNT(u));
    }
}

void displayReply(ReplyTree rt, ReplyAddress addr, ListUser *l, int depth, int LOGINID)
{
    int i = getIdxInReplyTree(rt, addr);
    if (!ISUSED(rt, i)) return;


    Reply rep = *addr;

    printSpace(depth);
    printf(" | ID = %d\n", REPLYID(rep));



    User u = ELMT_LISTUSER(*l, AUTHORID(rep));
    boolean public = !ISPRIVATE(PROFILE(u));

    if (!public && AUTHORID(rep) != LOGINID) {
        printSpace(depth);
        printf(" | PRIVAT\n");

        printSpace(depth);
        printf(" | PRIVAT\n");
        
        printSpace(depth);
        printf(" | PRIVAT\n");

    } else {
        String authorName = NAME(u);

        printSpace(depth);
        printf(" | ");
        displayString(authorName);
        printf("\n");

        printSpace(depth);
        printf(" | ");
        displayString(DateTimeToString(DTIME(rep)));
        printf("\n");

        printSpace(depth);
        printf(" | ");
        displayString(BODY(rep));
        printf("\n");
    }
    printf("\n");
}

void displayAllReply(ReplyTree rt, ListUser l, int LOGINID)
// I.S. compressed rt
{
    
    int length = LISTREP(rt).neff;
    int i;
    for (i = 0; i < length; i++) {
        Reply r = (*ADDR(LISTREP(rt), i));
        
        if (ISMAIN(r) && ISUSED(rt, i)) {
            displayAllReply_helper(rt, &l, 0, i, LOGINID);
        }
        
    }

}
    


void displayAllReply_helper(ReplyTree rt, ListUser *l, int currDepth, int idx, int LOGINID)
{
    ListDin adjlist = LISTDIN(rt, idx);
    ReplyAddress ra = ADDR(LISTREP(rt), idx);
    int neff = NEFF(adjlist);
    int i;




    displayReply(rt, ra, l, currDepth, LOGINID);

    
    for (i = 0; i < neff; i++) {
        displayAllReply_helper(rt, l, currDepth+1, adjlist.buffer[i], LOGINID);
    }
}

void AddReplyDariConfig(ReplyTree *rt, ListUser lu,int IDKicau, int IDBalasan, String body, String name, String DATETIME)
// JANGAN LUPA REPLY TREE DI CREATE DULU, capacity 100 aja.
{
    addReply(rt);

    ReplyAddress ra = newReply(body, IDKicau == -1);
    REPLYID(*ra) = generateReplyID(*rt);
    AUTHORID(*ra) = searchByName(lu, name);
    // DTIME() /// BIKIN DULU STRING TO DATETIME ABIS ITU MASUKIN KE SINI, JANGN LUPA!

    

    if (IDKicau == -1) {
        addMainReply(rt, ra);
    } else {
        addChildToReply(rt, ADDR(LISTREP(*rt),IDBalasan), ra);
    }

}
