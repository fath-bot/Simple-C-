#include <iostream>
#include "Parent.h"

void createListParent(List_Parent &L) {
    L.first = NULL;
}

void inputDataAtlet(List_Parent L, infotypeParent &in){
    cout<<"Nama Atlet: ";
    cin>>in.namaAtlet;
    while (findElmParent(L , in.namaAtlet) != NULL ) {
        cout<<"Atlet sudah ada. Input kembali."<<endl;
        cout<<"Nama Atlet: ";
        cin>>in.namaAtlet;
    }
    cout<<"Umur Atlet: ";
    cin >> in.umurAtlet;
    in.IDAtlet = generatorIDParent();
    while (findElmParent(L,in.IDAtlet) != NULL){
        in.IDAtlet = generatorIDParent();
    }
    cout<<"ID Atlet: "<<in.IDAtlet;
    in.countAtlet = 0;
}

address_Parent CreateElmParent(infotypeParent in){
    address_Parent P = new Parent;
    P -> info = in;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

void insertFirstParent(List_Parent &L, address_Parent P){
    if (L.first == NULL) {
        L.first = P;
        P -> next = P;
        P -> prev = P;
    } else {
        P -> next = L.first;
        P -> prev = L.first -> prev;
        L.first -> prev -> next = P;
        L.first -> prev = P;
        L.first = P;
    }
}

void insertAfterParent(List_Parent &L, address_Parent Prec, address_Parent P){
    P -> next = Prec -> next;
    P -> prev = Prec;
    Prec -> next -> prev = P;
    Prec -> next = P;
}

void insertLastParent(List_Parent &L, address_Parent P){
    P -> next = L.first;
    L.first -> prev = P;
    L.first = P;
}

void insertSortedParent(List_Parent &L, infotypeParent in){
    if (L.first != NULL) {
        if (findElmParent(L,in.namaAtlet) == NULL){
            if (in.namaAtlet < L.first -> info.namaAtlet){
                insertFirstParent(L,CreateElmParent(in));
            } else {
                address_Parent P = L.first;
                do {
                    P = P -> next;
                } while(P!= L.first && P -> info.namaAtlet > in.namaAtlet);
                insertAfterParent(L,P -> prev,CreateElmParent(in));
            }
        } else {
            cout << "Atlet sudah terdaftar"<<endl;
        }
    }else {
        insertFirstParent(L,CreateElmParent(in));
    }
}

void deleteFirstParent(List_Parent &L, address_Parent &P) {
    if (L.first != NULL) {
        if (L.first == L.first->next) {
            P = L.first;
            L.first = NULL;
        } else {
            P = L.first;
            L.first = P->next;
            L.first->prev = P->prev;
            P->prev->next = L.first;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteAfterParent(List_Parent &L, address_Parent Prec, address_Parent &P) {
    P = Prec -> next;
    Prec -> next = P -> next;
    P -> next -> prev = Prec;
    P -> prev = NULL;
    P -> next = NULL;

}


void deleteLastParent(List_Parent &L, address_Parent &P) {
    if (L.first != NULL) {
        if (L.first == L.first->next) {
            P = L.first;
            L.first = NULL;
        } else {
            P = L.first->prev;
            P->prev->next = L.first;
            L.first->prev = P->prev;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteSpesificParent(List_Parent &L, string X) {
    address_Parent P = findElmParent(L, X);
    if (L.first != NULL && P != NULL) {
        if (L.first->info.namaAtlet == X) {
            deleteFirstParent(L, P);
        } else if (L.first->prev->info.namaAtlet == X) {
            deleteLastParent(L, P);
        } else {
            P = L.first;
            address_Parent Q;
            while (P -> info.namaAtlet != X){
                Q = P;
                P = P -> next;
            }
            deleteAfterParent(L,Q,P);
        }
        cout << "Penghapusan Atlet " << X << " telah berhasil" << endl;
    } else {
        cout << "Atlet tidak ditemukan." << endl;
    }
    cout << endl;
}



void deallocateParent(address_Parent &P){
    delete P;
}

address_Parent findElmParent(List_Parent L, string X){
    address_Parent P = L.first;
    if (P!= NULL) {
        do {
            P = P -> next;
             if (P -> info.namaAtlet == X || P -> info.IDAtlet == X){
                return P;
             }
        } while (P != L.first && P -> info.namaAtlet != X && P -> info.IDAtlet != X);
    }
    return NULL;
}



void printInfoParent(List_Parent L){
    address_Parent P = L.first;
    if (P != NULL){
        do {
            cout<<"Atlet: "<<P -> info.namaAtlet<<endl;
            cout<<"Umur Atlet: "<< P -> info.umurAtlet<<endl;
            cout<<"ID: "<<P -> info.IDAtlet<<endl;
            cout<<"************************************"<<endl;
            P = P -> next;
        }while(P != L.first);
    }
    cout<<endl;
}

void printInfoParent0(List_Parent L){
    address_Parent P = L.first;
     cout<<"Daftar Nama Atlet: "<<endl;
    if (P != NULL){
        do {
            cout<<"Atlet: "<<P -> info.namaAtlet<<endl;
            P = P -> next;
        }while(P != L.first);
    }
    cout<<endl;
}

string generatorIDParent(){
    int r;
    stringstream sss;
    srand((int)time(0));
    r = (rand() % 850) + 1;
    sss<<r;
    string s;
    sss>>s;
    return s;
}
