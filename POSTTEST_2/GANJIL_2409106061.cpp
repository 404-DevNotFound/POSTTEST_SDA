#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
};

Node *head = nullptr;
Node *tail = nullptr;

void tranversal (Node *head) {
    if (head == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    } else {
        Node *current = head;
        while (current != nullptr) {
            cout << "Nama Item: " << current->namaItem << endl;
            cout << "Jumlah: " << current->jumlah << endl;
            cout << "Tipe: " << current->tipe << endl;
            current = current->next;
            cout << endl;
        }
    }
    cout << "done" << endl;
}

void tambahItem (Node *&head, int jumlah, string namaItem, string tipe){
    Node *nodebaru = new Node;
    nodebaru->namaItem = namaItem;
    nodebaru->jumlah = jumlah;
    nodebaru->tipe = tipe;
    
    if (head == nullptr){
        head = nodebaru;
        nodebaru->next = nullptr;
    } 
    else {
        Node *current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = nodebaru;
        nodebaru->next = nullptr;
    }
    cout << "Item berhasil ditambahkan" << endl;
}

void sisipkanItem (Node *&head, int jumlah, string namaItem, string tipe, int posisi){
    Node *temp = head;
    for (int i = 1; i < posisi - 1; i++){
        if (temp == nullptr){
            cout << "Melebihi inventorynya bang!" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp == nullptr){
        cout << "Inventorynya masih kosong bang!" << endl;
        return;
    } else if (temp->next == nullptr) {
        tambahItem(head, jumlah, namaItem, tipe);
        return;
    } else {
        Node *nodeBaru = new Node;
        nodeBaru->namaItem = namaItem;
        nodeBaru->jumlah = jumlah;
        nodeBaru->tipe = tipe;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
    cout << "Item berhasil disisipkan pada posisi " << posisi << endl;
}

void hapusItemTerakhir (Node *&head, Node *&tail){
    Node *current = head;
    while (current->next != tail){
        current = current->next;
    }

    if (head-> next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node *temp = head;
        while (temp->next !=tail ){
            temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
    }
    cout << "Item berhasil dihapus" << endl;
}

void gunakanItem (Node *&head, string namaItem){
    if (head == nullptr){
        cout << "Inventory kosong, tidak ada item yang dapat digunakan!" << endl;
        return;
    }
    Node *temp = head;
    Node *prev =nullptr;

    while (temp != nullptr) {
        if (temp->namaItem == namaItem) {
            temp->jumlah -= 1;
            cout << "Item " << temp->namaItem << " digunakan! Sisa: " << temp->jumlah << endl;

            if (temp->jumlah <= 0) {
                cout << "Item " << temp->namaItem << " habis dan dihapus dari inventory.\n";
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item " << namaItem << " tidak ditemukan!\n";
}

void tampilkanInventory (Node *head){
    if (head == nullptr){
        cout << "Inventory kosong!" << endl;
        return;
    }
    Node *current = head;
    cout << "Isi Inventory:\n";
    while (current != nullptr){
        cout << "Nama Item: " << current->namaItem << ", Jumlah: " << current->jumlah << ", Tipe: " << current->tipe << endl;
        current = current->next;
    }
}

int main (){

    string namaItem, tipe;
    int pilihan,jumlah;

    string nama = "Dnt";
    string nim = "2409106061";

    int jumlahItem = (nim[nim.length() - 2] - '0') * 10 + (nim[nim.length() - 1] - '0');
    int posisiItem = nim[nim.length() - 1] - '0';

    int posisiSisip;
    if (posisiItem == 0) {
        posisiSisip = 2;
    } else {
        posisiSisip = posisiItem + 1;
    }

    do {
        cout << "\n================================================\n";
        cout << "|          GAME INVENTORY MANAGEMENT              |\n";
        cout << "|         " << nama << " - " << nim << "                        |\n";
        cout << "\n================================================\n";
        cout << "| 1. Tambah Item Baru                             |\n";
        cout << "| 2. Sisipkan Item                                |\n";
        cout << "| 3. Hapus Item Terakhir                          |\n";
        cout << "| 4. Gunakan Item                                 |\n";
        cout << "| 5. Tampilkan Inventory                          |\n";
        cout << "| 0. Keluar                                       |\n";
        cout << "\n=================================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                tambahItem(head, jumlahItem, namaItem, tipe);
                break;
        
            case 2:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                sisipkanItem(head, jumlahItem, namaItem, tipe, posisiSisip);
                break;
        
            case 3:
                cout << "Apakah abang yakin ingin menghapus item terakhir? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;
                if (konfirmasi == 'y') {
                    hapusItemTerakhir(head, tail);
                    break;
                }else {
                    cout << "Item tidak jadi dihapus." << endl;
                    break;
                }
        
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, namaItem);
                gunakanItem(head, namaItem);
                break;
        
            case 5:
                tampilkanInventory(head);
                break;
        
            case 0:
                cout << "Keluar dari program...\n";
                break;
        
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}