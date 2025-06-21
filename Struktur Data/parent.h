#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>


using namespace std;

struct infotypeParent {
    string namaAtlet;
    string IDAtlet;
    int umurAtlet;
    int countAtlet;
};

typedef struct Parent *address_Parent;

struct Parent {
    infotypeParent info;
    address_Parent next;
    address_Parent prev;
};

struct List_Parent {
    address_Parent first;
};


void createListParent(List_Parent &L);
address_Parent CreateElmParent(infotypeParent in);
void insertFirstParent(List_Parent &L, address_Parent P);
void insertAfterParent(List_Parent &L, address_Parent Prec, address_Parent P);
void insertLastParent(List_Parent &L, address_Parent P);
void insertSortedParent(List_Parent &L, infotypeParent in);
void deleteFirstParent(List_Parent &L, address_Parent &P);
void deleteAfterParent(List_Parent &L, address_Parent Prec, address_Parent &P);
void deleteLastParent(List_Parent &L, address_Parent &P);
void deleteSpesificParent(List_Parent &L, string X);
address_Parent findElmParent(List_Parent L, string X);
void printInfoParent(List_Parent L);
void printInfoParent0(List_Parent L);

void inputDataAtlet(List_Parent L,infotypeParent &in);

//string 3 digit
string generatorIDParent();

