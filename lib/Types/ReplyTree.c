#include <stdio.h>
#include <stdlib.h>
#include "ReplyTree.h"

ReplyAddress newReply(String body, boolean isMain)
/*Membuat balasan dengan id null, authorid null, body terset, dan datetime juga terset*/
{
    ReplyAddress ra = (ReplyAddress) malloc(sizeof(Reply));
    REPLYID(*ra) = ID_UNDEF;
    BODY(*ra) = body;
    AUTHORID(*ra) = ID_UNDEF;
    DTIME(*ra) = currentDateTime();
    ISMAIN(*ra) = isMain;

    return ra;
}

void createReplyTree(ReplyTree *rt, int capacity)

{
    rt -> adjlists = (ListDin *) malloc(sizeof(int)*capacity*capacity);
    
    (rt -> listreply).buffer = (ReplyAddress *) malloc(sizeof(ReplyAddress)*capacity);
    (rt -> listreply).neff = 0;
    (rt -> listreply).capacity = capacity;

    
    CreateListDin(&(rt->used), capacity);

    CreateListDin(&(rt->parent), capacity);

    int i;
    for (i = 0; i < capacity; i++) {
        CreateListDin(&LISTDIN(*rt, i), capacity);

    }
    
    NUMREP(*rt) = 0;
    MAXREP(*rt) = capacity;
    rt -> availableID = 0;
    rt -> availableIDX = 0;
}

void extendReplyTree(ReplyTree *rt) 
{
    ReplyTree tmp;
    createReplyTree(&tmp, 2*(rt -> maxReply));

    tmp.numReplyEff = rt -> numReplyEff;
    tmp.availableID = rt -> availableID;
    tmp.availableIDX = rt -> availableIDX;
    tmp.maxReply = 2*(rt -> maxReply);
    LISTREP(tmp).neff = LISTREP(*rt).neff;

    int len = tmp.numReplyEff;
    int i;
    for (i = 0; i < len; i++) {
        LISTDIN(tmp, i) = LISTDIN(*rt, i);
        ADDR(LISTREP(tmp), i) = ADDR(LISTREP(*rt), i);
        ISUSED(tmp, i) = ISUSED(*rt, i);
        PARENT(tmp, i) = PARENT(*rt, i);
    }

    *rt = tmp;
}


int getIdxInReplyTree(ReplyTree rt, ReplyAddress addr)
{
    int i;
    int len = rt.maxReply;
    for (i= 0; i < len; i++) {
        if (ADDR(LISTREP(rt), i) == addr) break;
    }

    return i;
}

ReplyAddress getReplyAddress(ReplyTree rt, int replyID)
/**
 * replyID sudah pasti ada.
*/
{
    int lo = 0;
    int hi = rt.maxReply;
    int mid;

    ListReply l = LISTREP(rt);
    return ADDR(l, replyID);
}

void swapIndexTree(ReplyTree *rt, int i, int j)

{
    // Swaping the adjlists
    ListDin tmpld;
    tmpld =LISTDIN(*rt, i);
    LISTDIN(*rt, i) = LISTDIN(*rt, j);
    LISTDIN(*rt, j) = tmpld;

    // swap elmt inside list reply
    ReplyAddress tmpra;
    tmpra = ADDR(LISTREP(*rt), i);
    ADDR(LISTREP(*rt), i) = ADDR(LISTREP(*rt), j);
    ADDR(LISTREP(*rt), j) = tmpra;

    // swap elmt inside list used.
    int tmpi;
    tmpi = ((USED(*rt)).buffer[i]);
    ((USED(*rt)).buffer[i]) = ((USED(*rt)).buffer[j]);
    ((USED(*rt)).buffer[j]) = tmpi;
  
}

int generateReplyID(ReplyTree rt) {
    return rt.availableID;
}

void addReply(ReplyTree *rt)
{
    if (rt -> availableIDX == rt -> maxReply)
    {
        extendReplyTree(rt);
    }

     
    NUMREP(*rt) += 1;
    rt -> availableID += 1;
    rt -> availableIDX += 1;
    LISTREP(*rt).neff += 1;
}

void addChildToReply(ReplyTree *rt, ReplyAddress parent, ReplyAddress child)
/**
 * I.S. replyadrress dari parent dan child terdefinisi.
*/
{
    int idxParent = getIdxInReplyTree(*rt, parent);
    ListReply *lr = &LISTREP(*rt);


    insertLastListDin(&LISTDIN(*rt, idxParent), child->id);



    lr -> buffer[child->id] = child;
    ISUSED(*rt, child->id) = 1;
    insertLastListDin(&(rt->parent), idxParent);
    
}

void addMainReply(ReplyTree *rt, ReplyAddress addr) {
    ListReply *lr = &LISTREP(*rt);
    lr -> buffer[addr->id] = addr;
    ISUSED(*rt, addr->id) = 1;
    insertLastListDin(&(rt->parent), -1);
}


void printSpace(int num) {
    while (num > 0){
        printf("   ");
        num--;
    }
}

void displayReply(ReplyTree rt, ReplyAddress addr, ListUser l, int depth)
{
    int i = getIdxInReplyTree(rt, addr);
    if (!ISUSED(rt, i)) return;


    Reply rep = *addr;

    printSpace(depth);
    printf(" | ID = %d\n", REPLYID(rep));

    User u = ELMT_LISTUSER(l, AUTHORID(rep));
    boolean public = !ISPRIVATE(PROFILE(u));

    if (!public) {
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

void displayAllReply(ReplyTree rt, ListUser l)
// I.S. compressed rt
{
    int length = LISTREP(rt).neff;
    int i;
    for (i = 0; i < length; i++) {
        Reply r = (*ADDR(LISTREP(rt), i));
        if (ISMAIN(r) && ISUSED(rt, i)) {
            displayAllReply_helper(rt, l, 0, i);
        }
    }

}

void displayAllReply_helper(ReplyTree rt, ListUser l, int currDepth, int idx)
{
    ListDin adjlist = LISTDIN(rt, idx);
    ReplyAddress ra = ADDR(LISTREP(rt), idx);
    int neff = NEFF(adjlist);
    int i;

    displayReply(rt, ra, l, currDepth);

    for (i = 0; i < neff; i++) {
        displayAllReply_helper(rt, l, currDepth+1, adjlist.buffer[i]);
    }
}

int getIdxFromReplyId(ReplyTree rt, int replyID)
// compressed rt
{
    int i;
    
    for (i =0; i < rt.numReplyEff; i++) {
        if (REPLYID(*ADDR(LISTREP(rt), i)) == replyID) return i;
    }

    return -1;
}

void deleteReply(ReplyTree *rt, int replyID)

{
    int parent = PARENT(*rt, replyID);
    if (parent == -1) {
        ISMAIN(*ADDR(LISTREP(*rt), replyID)) = false;
    } else {
        // remove from parent
        removeElmt(&LISTDIN(*rt, PARENT(*rt, replyID)), replyID);
    }

    
    ISUSED(*rt, replyID) = 0;
    rt -> numReplyEff -=1;

    // remove the children.
    int neff = LISTDIN(*rt, replyID).nEff;
    int i;
    for (i = 0; i < neff; i++) {
        deleteReply(rt, LISTDIN(*rt, replyID).buffer[i]);
    }
    
}