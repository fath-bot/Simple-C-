#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

struct infotypeChild {
    string namaClub;
    string IDClub;
    int ukuranClub;
    int countClub;
};

typedef struct Child *address_Child;

struct Child {
    infotypeChild info;
    address_Child next;
};

struct List_Child {
    address_Child first;
    address_Child last;
};


void createListChild(List_Child &L);
address_Child CreateElmChild(infotypeChild in);
void insertFirstChild(List_Child &L, address_Child P);
void insertAfterChild(List_Child &L, address_Child Prec, address_Child P);
void insertLastChild(List_Child &L, address_Child P);
void insertSortedChild(List_Child &L, infotypeChild X);
void deleteFirstChild(List_Child &L, address_Child &P);
void deleteAfterChild(List_Child &L, address_Child Prec, address_Child &P);
void deleteLastChild(List_Child &L, address_Child &P);
void deleteSpesificChild(List_Child &L, string X);
address_Child findElmChild(List_Child &L, string X);
void printInfoChild(List_Child L);
void printInfoChild0(List_Child L);

void inputDataClub(List_Child L,infotypeChild &in);

//string 3 digit
string generatorIDChild();

