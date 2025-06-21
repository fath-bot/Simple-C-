#include <iostream>
#include "relasi.h"
using namespace std;





int main()
{
    string any;
    int pilih;
    List_Parent List_Parent;
    List_Child List_Child;
    List_Relasi List_Relasi;
    infotypeParent DataAtlet;
    infotypeChild DataClub;
    address_Parent P;
    address_Child Q;
    relateAddress R;

    createListParent(List_Parent);
    createListChild(List_Child);
    createListRelasi(List_Relasi);

    do{
        cout << "************************************" << endl;
        cout << "         SELAMAT DATANG DI          " << endl;
        cout << "        Menu Atlet dan Club         " << endl;
        cout << "              Pethxv                " << endl;
        cout << "************************************" << endl << endl;

        // Menu options
        cout << "1. Mendaftarkan Atlet" << endl;
        cout << "2. Mendaftarkan Club" << endl;
        cout << "3. Melihat semua Atlet terdaftar" << endl;
        cout << "4. Melihat semua Club terdaftar" << endl;
        cout << "5. Memilih Atlet untuk Club" << endl;
        cout << "6. Melihat Club dan lokasi Atletnya" << endl;
        cout << "7. Melihat Club yang paling Banyak diKontrak" << endl;
        cout << "8. Melihat Atlet dengan jumlah Club terbanyak" << endl;
        cout << "9. Menghapus Atlet dari daftar Atlet" << endl;
        cout << "10. Menghapus Club dari daftar Club" << endl;
        cout << "11. Melepas Club dari Atlet" << endl;
        cout << "12. Mencari nama Atlet berdasarkan ID beserta Club di dalamnya" << endl;
        cout << "13. Mencari nama Club berdasarkan ID beserta Atlet yang ditempatinya" << endl;
        cout << "14. Menemukan apakah Child dan Parent memiliki relasi" << endl;
        cout << "15. Melihat data Parent dari Child tertentu" << endl;
        cout << "16. Melihat setiap Child dengan data Parent yang berelasi dengannya" << endl;
        cout << "17. Melihat setiap Parent dengan data Child yang berelasi dengannya" << endl;
        cout << "18. Menghitung Parent tanpa Child" << endl;
        cout << "19. Menghitung Child tanpa Parent" << endl;
        cout << "20. Mengedit Relasi (Mengganti Parent atau Child)" << endl;
        cout << "Pilihan menu: ";
        cin >> pilih;
        cout << endl << endl;
        system("CLS");

        // Implementing menu options
        if (pilih == 1) {
            inputDataAtlet(List_Parent, DataAtlet);
            insertSortedParent(List_Parent, DataAtlet);
        } else if (pilih == 2) {
            inputDataClub(List_Child, DataClub);
            insertSortedChild(List_Child, DataClub);
        } else if (pilih == 3) {
            printInfoParent(List_Parent);
        } else if (pilih == 4) {
            printInfoChild(List_Child);
        } else if (pilih == 5) {
            printInfoParent0(List_Parent);
            cout << "Nama Atlet: ";
            cin >> DataAtlet.namaAtlet;
            P = findElmParent(List_Parent, DataAtlet.namaAtlet);
            printInfoChild0(List_Child);
            cout << "Nama Club: ";
            cin >> DataClub.namaClub;
            Q = findElmChild(List_Child, DataClub.namaClub);
            if (P != NULL && Q != NULL) {
                R = CreateElmRelasi(P, Q);
                insertRelasi(List_Relasi, R);
            } else {
                if (P == NULL) cout << "Atlet belum terdaftar" << endl;
                if (Q == NULL) cout << "Club belum terdaftar" << endl;
            }
        } else if (pilih == 6) {
            printInfoRelasi(List_Relasi);
        } else if (pilih == 7) {
            countRelasiByChild(List_Relasi);
        } else if (pilih == 8) {
            countRelasiByParent(List_Relasi);
        } else if (pilih == 9) {
            cout << "Nama Atlet: ";
            cin >> DataAtlet.namaAtlet;
            P = findElmParent(List_Parent, DataAtlet.namaAtlet);
            R = findElmRelasiParent(List_Relasi, DataAtlet.namaAtlet);
            if (P != NULL) {
                if (R != NULL) deleteAllRelasiParent(List_Relasi, P);
                deleteSpesificParent(List_Parent, P->info.namaAtlet);

            } else {
                cout << "Atlet belum terdaftar." << endl;
            }
        } else if (pilih == 10) {
            cout << "Nama Club: ";
            cin >> DataClub.namaClub;
            Q = findElmChild(List_Child, DataClub.namaClub);
            R = findElmRelasiChild(List_Relasi, DataClub.namaClub);
            if (Q != NULL) {
                if (R != NULL) deleteAllRelasiChild(List_Relasi, Q);
                deleteSpesificChild(List_Child, Q->info.namaClub);

            } else {
                cout << "Club belum terdaftar." << endl;
            }
        } else if (pilih == 11) {
            cout << "Nama Atlet: ";
            cin >> DataAtlet.namaAtlet;
            P = findElmParent(List_Parent, DataAtlet.namaAtlet);
            cout << "Nama Club: ";
            cin >> DataClub.namaClub;
            Q = findElmChild(List_Child, DataClub.namaClub);
            deleteSpesificRelasi(List_Relasi, P, Q);
        } else if (pilih == 12) {
            cout << "ID Atlet: ";
            cin >> DataAtlet.IDAtlet;
            P = findElmParent(List_Parent, DataAtlet.IDAtlet);
            if (P != NULL) {
                cout << "Atlet: " << P->info.namaAtlet << endl;
                cout << "Umur Atlet: " << P->info.umurAtlet << endl;
                cout << "ID: " << P->info.IDAtlet << endl;
                cout << "Club: ";
                R = findElmRelasiParent(List_Relasi, P->info.namaAtlet);
                if (R != NULL) printRelasiByParent(List_Relasi, P->info.namaAtlet);
            } else {
                cout << DataAtlet.namaAtlet << " belum terdaftar." << endl;
            }
        } else if (pilih == 13) {
            cout << "ID Club: ";
            cin >> DataClub.IDClub;
            Q = findElmChild(List_Child, DataClub.IDClub);
            if (Q != NULL) {
                cout << "Nama: " << Q->info.namaClub << endl;
                cout << "Ukuran: " << Q->info.ukuranClub << endl;
                cout << "ID: " << Q->info.IDClub << endl;
                R = findElmRelasiChild(List_Relasi, Q->info.namaClub);
                if (R != NULL) printRelasiByChild(List_Relasi, Q->info.namaClub);
            } else {
                cout << DataClub.namaClub << " belum terdaftar." << endl;
            }
        } else if (pilih == 14) {
            cout << "Nama Atlet: ";
            cin >> DataAtlet.namaAtlet;
            cout << "Nama Club: ";
            cin >> DataClub.namaClub;
            P = findElmParent(List_Parent, DataAtlet.namaAtlet);
            Q = findElmChild(List_Child, DataClub.namaClub);
            if (findRelasi(List_Relasi, P, Q))
                cout << "Atlet dan Club memiliki relasi!" << endl;
            else
                cout << "Atlet dan Club tidak memiliki relasi." << endl;
        } else if (pilih == 15) {
            cout << "Nama Club: ";
            cin >> DataClub.namaClub;
            showParentDataFromChild(List_Relasi, DataClub.namaClub);
        } else if (pilih == 16) {
            showChildWithParentren(List_Relasi);
        } else if (pilih == 17) {
            showParentWithChilds(List_Relasi);
        } else if (pilih == 18) {
            countParentWithoutChild(List_Relasi, List_Parent);
        } else if (pilih == 19) {
            countChildWithoutParent(List_Relasi, List_Child);
        } else if (pilih == 20) {
            cout << "Nama Atlet: ";
            cin >> DataAtlet.namaAtlet;
            cout << "Nama Club lama: ";
            cin >> DataClub.namaClub;
            cout << "Nama Club baru: ";
            string newClub;
            cin >> newClub;

            address_Child newQ = findElmChild(List_Child, newClub);
            if (newQ == NULL) {
                cout << "Nama Club baru tidak ditemukan!" << endl;
                return false;
            }

            address_Child oldQ = findElmChild(List_Child, DataClub.namaClub);
            if (oldQ == NULL) {
                cout << "Nama Club lama tidak ditemukan!" << endl;
                return false;
            }

            address_Parent P = findElmParent(List_Parent, DataAtlet.namaAtlet);
            if (P == NULL) {
                cout << "Atlet tidak ditemukan!" << endl;
                return false;
            }

            editRelasi(List_Relasi, P, newQ);
        } else if (pilih == 0) {
            cout << "Terima kasih, Program selesai." << endl;
            return false;
        } else {
            cout << "Opsi tidak tersedia. Silakan pilih lagi." << endl;
        }

        cout << endl;
        cout << "Program berhasil dilakukan. Klik apapun untuk melanjutkan." << endl;
        cin.get();
        getline(cin, any);
        system("CLS");

    } while (true);

    return 0;
}
