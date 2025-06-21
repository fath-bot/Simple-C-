#include "relasi.h"

using namespace std;

void createListRelasi(List_Relasi &L){
    L.first = NULL;
    L.last = NULL;
}

relateAddress CreateElmRelasi(address_Parent P, address_Child Q){
    relateAddress R = new Relasi;
    R -> Atlet = P;
    R -> Club = Q;
    R -> next = NULL;
    R -> prev = NULL;
    P -> info.countAtlet++;
    Q -> info.countClub++;
    return R;
}

void insertRelasi(List_Relasi &L, relateAddress R){
    if (L.first == NULL) {
        L.first = R;
        L.last = R;
    } else {
        L.last -> next = R;
        R -> prev = L.last;
        L.last = R;
    }
}

void deleteFirstRelasi(List_Relasi &L, relateAddress &R){
    if (L.first != L.last) {
        R = L.first;
        L.first = R -> next;
        R -> next = NULL;
        L.first -> prev = NULL;
    }else {
        R = L.first;
        L.first = NULL;
        L.last = NULL;
    }

}

void deleteAfterRelasi(List_Relasi &L, relateAddress Prec, relateAddress &R){
    R = Prec -> next;
    Prec -> next = R -> next;
    R -> next -> prev = Prec;
    R -> prev = NULL;
    R -> next = NULL;

}

void deleteLastRelasi(List_Relasi &L, relateAddress &R){
    R = L.last;
    L.last = R -> prev;
    R -> prev = NULL;
    L.last -> next = NULL;

}

void deleteSpesificRelasi(List_Relasi &L, address_Parent P, address_Child Q){
    relateAddress R = L.first;
    if (R != NULL){
        if (L.first -> Atlet == P && L.first -> Club == Q){
            deleteFirstRelasi(L,R);
        } else if (L.last -> Atlet == P){
            deleteLastRelasi(L,R);
        } else {
            while (R != NULL && (R -> Atlet != P && R -> Club != Q)){
                R = R -> next;
            }
                if (R != NULL) {
                    deleteAfterRelasi(L,R -> prev,R);
                }else {
                    cout<<"Belum ada relasi."<<endl;
                }
        }
    }else {
        cout<<"Tidak ada relasi saat ini."<<endl;
    }
    cout<<endl;
}

relateAddress findElmRelasiParent(List_Relasi &L, string out){
    relateAddress R = L.first;
    while (R != NULL){
      if (R -> Atlet -> info.namaAtlet == out){
        return R;
      }
      R = R -> next;
    }
    return NULL;
}

void deleteAllRelasiParent(List_Relasi &L, address_Parent P){
    relateAddress R;
    while (findElmRelasiParent(L,P->info.namaAtlet) != NULL){
        if (L.first -> Atlet == P){
            deleteFirstRelasi(L,R);
        }
         else if (L.last -> Atlet == P){
            deleteLastRelasi(L,R);
        }else {
            R = L.first;
            while (findElmRelasiParent(L,P->info.namaAtlet) != NULL){
                if (R -> Atlet == P){
                    deleteAfterRelasi(L,R -> prev,R);
                }
                R = R -> next;
            }
        }
    }
}

relateAddress findElmRelasiChild(List_Relasi &L, string out){
    relateAddress R = L.first;
    while (R != NULL){
      if (R -> Club -> info.namaClub == out){
        return R;
      }
      R = R -> next;
    }
    return NULL;
}

void deleteAllRelasiChild(List_Relasi &L, address_Child Q){
    relateAddress R;
    while (findElmRelasiChild(L,Q->info.namaClub) != NULL){
        if (L.first -> Club == Q){
            deleteFirstRelasi(L,R);
        }
         else if (L.last -> Club == Q){
            deleteLastRelasi(L,R);
        }else {
            R = L.first;
            while (findElmRelasiChild(L,Q->info.namaClub) != NULL){
                if (R -> Club == Q){
                    deleteAfterRelasi(L,R -> prev,R);
                }
                R = R -> next;
            }
        }
    }
}

void countRelasiByChild(List_Relasi L){
    relateAddress R = L.first;
    relateAddress P;
    int max = 0;
    if (R != NULL) {
        while (R != NULL){
            if (max < R -> Club -> info.countClub){
                max = R -> Club -> info.countClub;
                P = R;
            }
            R = R -> next;
        }
        cout<<"Club dengan Kontrak terbanyak adalah ";
        cout<<P -> Club -> info.namaClub<<endl;
        printRelasiByChild(L,P -> Club -> info.namaClub);
    }
}

void printRelasiByChild(List_Relasi L, string out){
    relateAddress R = L.first;
    while (R != NULL){
        if (R -> Club -> info.namaClub == out){
            cout<<R -> Atlet -> info.namaAtlet<<" ";
        }
        R = R -> next;
    }
    cout<<endl;
}

void countRelasiByParent(List_Relasi L){
    relateAddress R = L.first;
relateAddress P;
int max = 0;
if (R != NULL) {
    while (R != NULL) {
        if (max < R->Atlet->info.countAtlet) {
            max = R->Atlet->info.countAtlet;
            P = R;
        }
        R = R->next;
    }

    cout << "Atlet dengan klub terbanyak adalah: " << P->Atlet->info.namaAtlet << endl;
    cout << "Jumlah klub: " << max << endl;

    cout << "Klub-klub yang mengontrak atlet ini: " << endl;;
    relateAddress temp = L.first;
    while (temp != NULL) {
        if (temp->Atlet == P->Atlet) {
            cout << "- " << temp->Club->info.namaClub << endl;
        }
        temp = temp->next;
    }
} else {
    cout << "Daftar relasi kosong." << endl;
}


}

void printRelasiByParent(List_Relasi L, string out){
    relateAddress R = L.first;
    while (R != NULL){
        if (R -> Atlet -> info.namaAtlet == out){
            cout<<R -> Club -> info.namaClub<<" ";
        }
        R = R -> next;
    }
    cout<<endl;
}

void printInfoRelasi(List_Relasi L){
    relateAddress R = L.first;
    while (R!=NULL){
        cout<<R -> Atlet -> info.namaAtlet<<" Kontrak di ";
        cout<< R -> Club -> info.namaClub <<endl;
        R = R -> next;
    }
    cout<<endl;
}

bool findRelasi(List_Relasi &L, address_Parent P, address_Child Q) {
    relateAddress R = L.first;
    while (R != NULL) {
        if (R->Atlet == P && R->Club == Q) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void showParentDataFromChild(List_Relasi &L, string ChildName) {
    relateAddress R = L.first;
    while (R != NULL) {
        if (R->Club->info.namaClub == ChildName) {
            cout << "Atlet: " << R->Atlet->info.namaAtlet << endl;
            cout << "ID Atlet: " << R->Atlet->info.IDAtlet << endl;
            cout << "************************************" << endl;
        }
        R = R->next;
    }
}

void showChildWithParentren(List_Relasi &L) {
    relateAddress R = L.first;
    while (R != NULL) {
        cout << "Club: " << R->Club->info.namaClub << endl;
        cout << "Atlet: " << R->Atlet->info.namaAtlet << endl;
        cout << "info: Club memiliki " << R->Club->info.countClub << " Atlet" << endl;
        cout << "************************************" << endl;
        R = R->next;
    }
}

void showParentWithChilds(List_Relasi &L) {
    relateAddress R = L.first;
    while (R != NULL) {
        cout << "Atlet: " << R->Atlet->info.namaAtlet << endl;
        cout << "Club: " << R->Club->info.namaClub << endl;
        cout << "info: Atlet memiliki kontrak " << R->Club->info.countClub << " Club" << endl;
        cout << "************************************" << endl;
        R = R->next;
    }
}

void countParentWithoutChild(List_Relasi &L, List_Parent &LC) {
    int count = 0;
    address_Parent P = LC.first;
    string firstAtlet = "";

    cout << "Atlet yang tidak berada di Club: "<< endl;

    while (P != NULL) {
        if (firstAtlet == "") {
            firstAtlet = P->info.namaAtlet;
        }
        if (P->info.namaAtlet == firstAtlet && count > 0) {
            cout << "Jumlah Atlet tanpa Club: " << count << endl;
            return;
        }

        if (findElmRelasiParent(L, P->info.namaAtlet) == NULL) {
            cout << "- " << P->info.namaAtlet << endl;
            count++;
        }

        P = P->next;
    }



}

void countChildWithoutParent(List_Relasi &L, List_Child &LP) {
    int count = 0;
    address_Child Q = LP.first;
    cout << "Club yang tidak memiliki Atlet: "<< endl;
    while (Q != NULL) {
        if (findElmRelasiChild(L, Q->info.namaClub) == NULL) {
            cout << "- " << Q->info.namaClub << endl;
            count++;
        }
        Q = Q->next;
    }
    cout << "Jumlah Club yang tidak memiliki Atlet: " << count << endl;

}


void editRelasi(List_Relasi &L, address_Parent P, address_Child newQ) {
    relateAddress R = L.first;
    while (R != NULL) {
        if (R->Atlet == P) {
            address_Child oldQ = R->Club;
            R->Club = newQ;
            newQ->info.countClub++;
            oldQ->info.countClub--;
            cout << "Atlet  " << P->info.namaAtlet << " ditransfer ke " << newQ->info.namaClub << endl;
            return;
        }
        R = R->next;
    }
    cout << "Kontrak tidak ditemukan!" << endl;
}


