#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "Parent.h"
#include "Child.h"

using namespace std;

typedef struct Relasi *relateAddress;

struct Relasi {
    address_Parent Atlet;
    address_Child Club;
    relateAddress next;
    relateAddress prev;
};

struct List_Relasi {
    relateAddress first;
    relateAddress last;
};

void createListRelasi(List_Relasi &L);
relateAddress CreateElmRelasi(address_Parent P, address_Child Q);
void insertRelasi(List_Relasi &L, relateAddress R);
void deleteFirstRelasi(List_Relasi &L, relateAddress &R);
void deleteAfterRelasi(List_Relasi &L, relateAddress Prec, relateAddress &R);
void deleteLastRelasi(List_Relasi &L, relateAddress &R);
void deleteSpesificRelasi(List_Relasi &L, address_Parent P, address_Child Q);
relateAddress findElmRelasiParent(List_Relasi &L, string out);
relateAddress findElmRelasiChild(List_Relasi &L, string out);
void printInfoRelasi(List_Relasi L);

void countRelasiByParent(List_Relasi L);
void countRelasiByChild(List_Relasi L);

void printRelasiByParent(List_Relasi L, string out);
void printRelasiByChild(List_Relasi L, string out);

void deleteAllRelasiParent(List_Relasi &L, address_Parent P);
void deleteAllRelasiChild(List_Relasi &L,address_Child Q);
void deallocateRelasi(relateAddress R);
bool findRelasi(List_Relasi &L, address_Parent P, address_Child Q);
void showParentDataFromChild(List_Relasi &L, string ChildName);
void showChildWithParentren(List_Relasi &L);
void showParentWithChilds(List_Relasi &L);
void countParentWithoutChild(List_Relasi &L, List_Parent &LC);
void countChildWithoutParent(List_Relasi &L, List_Child &LP);
void editRelasi(List_Relasi &L, address_Parent P, address_Child newQ);

#endif // RELASI_H_INCLUDED
