#ifndef REPLYTREE_H
#define REPLYTREE_H

#include "../ADT/ListDinamik/listdinamik.h"
#include "../ADT/DateTime/datetime.h"
#include "ListUser.h"



typedef struct reply {
    int id;
    String body;
    int authorID;
    DATETIME time;
    boolean mainReply; // artinya dia attached to root atau ngga
} Reply;

typedef struct reply *ReplyAddress; 


#define REPLYID(r) (r).id
#define BODY(r) (r).body
#define AUTHORID(r) (r).authorID
#define DTIME(r) (r).time
#define ISMAIN(r) (r).mainReply

typedef struct listreply{
    ReplyAddress *buffer;
    int neff;
    int capacity;
} ListReply;

#define CAPLR(lr) (lr).capacity
#define NEFFLR(lr) (lr).neff
#define ADDR(lr, i) (lr).buffer[i]

typedef struct replytree {
    ListDin *adjlists; // pointer to first list dinamis
    ListReply *listreply; 
    ListDin* used;
    ListDin* parent;
    int numReplyEff;
    int availableID;
    int maxReply;
    int availableIDX;

} ReplyTree;

#define LISTDIN(rt, i) (rt).adjlists[i]
#define USED(rt) (*((rt).used))
#define ISUSED(rt, i) (*(rt).used).buffer[i]
#define MAXREP(rt) (rt).maxReply
#define LISTREP(rt) (*((rt).listreply))
#define NUMREP(rt) (rt).numReplyEff




int generateReplyID(ReplyTree rt);

void createReplyTree(ReplyTree *rt, int capacity);

void extendReplyTree(ReplyTree *rt);

void compressReplyTree(ReplyTree *rt);

void addReply(ReplyTree *rt);

void addChildToReply(ReplyTree *rt, ReplyAddress parent, ReplyAddress child);

void swapIndexTree(ReplyTree *rt, int i, int j);

void displayReply(ReplyAddress addr, ListUser l, int depth);

void displayAllReply(ReplyTree rt, ListUser l);

void displayAllReply_helper(ReplyTree rt, ListUser l, int currDepth, int idx);

ReplyAddress newReply(String body, boolean isMain);



#endif