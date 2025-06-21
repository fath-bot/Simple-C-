#include <iostream>
#include "Child.h"

void createListChild(List_Child &L){
    L.first = NULL;
    L.last = NULL;
}

void inputDataClub(List_Child L,infotypeChild &in){
    cout<<"Nama Club: ";
    cin>>in.namaClub;
    while (findElmChild(L,in.namaClub) != NULL ) {
        cout<<"Nama sudah ada. Input kembali."<<endl;
        cout<<"Nama Club: ";
        cin>>in.namaClub;
    }
    cout<<"ukuran Club: ";
    cin >> in.ukuranClub;
    in.IDClub = generatorIDChild();
    while (findElmChild(L,in.IDClub) != NULL){
        in.IDClub = generatorIDChild();
    }
    cout<<"ID Club: "<<in.IDClub;
    in.countClub = 0;
}

address_Child CreateElmChild(infotypeChild X){
    address_Child P = new Child;
    P -> info = X;
    P -> next = NULL;
    return P;
}

void insertFirstChild(List_Child &L, address_Child P){
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P -> next = L.first;
        L.first = P;
    }
}

void insertAfterChild(List_Child &L, address_Child Prec, address_Child P){
    P -> next = Prec -> next;
    Prec -> next = P;
}

void insertLastChild(List_Child &L, address_Child P){
    if (L.first == NULL){
        insertFirstChild(L,P);
    }else {
        L.last -> next = P;
        L.last = P;
    }
}

void insertSortedChild(List_Child &L, infotypeChild in){
    if (L.first != NULL) {
        if (findElmChild(L,in.namaClub) == NULL){
            if (in.namaClub > L.first -> info.namaClub){
                insertFirstChild(L,CreateElmChild(in));

            } else if (in.namaClub < L.last -> info.namaClub){
                insertLastChild(L,CreateElmChild(in));
            } else {
                address_Child P = L.first;
                while (P != NULL && in.namaClub > P -> info.namaClub){
                    P = P -> next;
                }
                insertAfterChild(L,P,CreateElmChild(in));
            }
        } else {
            cout << "Club sudah terdaftar"<<endl;
        }
    }else {
        insertFirstChild(L,CreateElmChild(in));
    }
}

void deleteFirstChild(List_Child &L, address_Child &P){
    if (L.first != L.last) {
        P = L.first;
        L.first = P -> next;
        P -> next = NULL;
    }else {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }
}

void deleteAfterChild(List_Child &L, address_Child Prec, address_Child &P){
    P = Prec -> next;
    Prec -> next = P -> next;
    P -> next = NULL;
}

void deleteLastChild(List_Child &L, address_Child &P){
    address_Child Q = L.first;
    while (Q -> next -> next != NULL) {
        Q = Q -> next;
    }
    P = Q -> next;
    Q -> next = NULL;
}

void deleteSpesificChild(List_Child &L, string X){
    address_Child P = findElmChild(L,X);
    if (L.first != NULL && P != NULL){
        if (L.first -> info.namaClub == X){
            deleteFirstChild(L,P);
        } else if (L.last -> info.namaClub == X) {
            deleteLastChild(L,P);
        } else {
            P = L.first;
            address_Child Q;
            while (P -> info.namaClub != X){
                Q = P;
                P = P -> next;
            }
            deleteAfterChild(L,Q,P);
        }
        cout<<"Penghapusan Club "<<X<<" telah berhasil"<<endl;
    } else {
        cout<<"Club sudah tidak ada."<<endl;
    }
    cout<<endl;
}



address_Child findElmChild(List_Child &L, string X){
    address_Child P = L.first;
    while (P != NULL) {
        if (P -> info.namaClub == X || P -> info.IDClub == X){
            return P;
        }
        P = P -> next;
    }
    return NULL;
}

void printInfoChild(List_Child L){
    address_Child P = L.first;
    while (P!=NULL){
        cout<<"Nama:"<<P -> info.namaClub<<endl;
        cout<<"ukuran:"<<P -> info.ukuranClub<<endl;
        cout<<"ID:"<<P -> info.IDClub<<endl;
        cout<<"************************************"<<endl;
        P = P -> next;

    }
    cout<<endl;
}
void printInfoChild0(List_Child L){
       address_Child P = L.first;
       cout<<"Daftar Nama Club: "<<endl;
    while (P!=NULL){
        cout<<"Club: "<<P -> info.namaClub<<endl;
        P = P -> next;
        cout<<endl;
    }
    cout<<endl;
}

string generatorIDChild(){
    int r;
    stringstream sss;
    srand((int)time(0));
    r = (rand() % 850) + 1;
    sss<<r;
    string s;
    sss>>s;
    return s;
}
