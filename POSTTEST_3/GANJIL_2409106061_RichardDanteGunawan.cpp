#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ID;
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
    Node* prev;
};

Node *head = nullptr;
Node *tail = nullptr;
int nextID = 1;

void traversalHead(Node *head) {
    if (head == nullptr) {
        cout << "Inventory masih kosong" << endl;
        return;
    } else {
        Node *current = head;
        cout << "Isi Inventory (Dari Head):\n";
        while (current != nullptr) {
            cout << "ID Item: " << current->ID << endl;
            cout << "Nama Item: " << current->namaItem << endl;
            cout << "Jumlah: " << current->jumlah << endl;
            cout << "Tipe: " << current->tipe << endl;
            current = current->next;
            cout << endl;
        }
    }
    cout << "done" << endl;
}

void traversalTail(Node *tail) {
    if (tail == nullptr) {
        cout << "Inventory masih kosong" << endl;
        return;
    } else {
        Node *current = tail;
        cout << "Isi Inventory (Dari Tail):\n";
        while (current != nullptr) {
            cout << "ID Item: " << current->ID << endl;
            cout << "Nama Item: " << current->namaItem << endl;
            cout << "Jumlah: " << current->jumlah << endl;
            cout << "Tipe: " << current->tipe << endl;
            current = current->prev;
            cout << endl;
        }
    }
    cout << "done" << endl;
}

void tambahItem(Node *&head, Node *&tail, int jumlah, string namaItem, string tipe) {
    Node *nodebaru = new Node;
    nodebaru->ID = nextID++;
    nodebaru->namaItem = namaItem;
    nodebaru->jumlah = jumlah;
    nodebaru->tipe = tipe;
    nodebaru->next = nullptr;
    nodebaru->prev = nullptr;
    
    if (head == nullptr){
        head = nodebaru;
        tail = nodebaru;
    } else {
        tail->next = nodebaru;
        nodebaru->prev = tail;
        tail = nodebaru;
    }
    cout << "Item berhasil ditambahkan dengan ID :"<< nodebaru->ID << endl;
}

void sisipkanItem(Node *&head, Node *&tail, int jumlah, string namaItem, string tipe, int posisi){
   if (posisi == 1){
        Node *nodeBaru = new Node;
        nodeBaru->ID = nextID++;
        nodeBaru->namaItem = namaItem;
        nodeBaru->jumlah = jumlah;
        nodeBaru->tipe = tipe;
        nodeBaru->next = head;
        nodeBaru->prev = nullptr;
        
        if (head != nullptr) {
            head->prev = nodeBaru;
        }
        head = nodeBaru;
        
        if (tail == nullptr) {
            tail = nodeBaru;
        }
        
        cout << "Item berhasil disisipkan pada posisi " << posisi << " dengan ID: " << nodeBaru->ID << endl;
        return;
   }
   Node *current = head;
   for (int i = 1; i < posisi - 1 && current != 0; i++){
        current = current->next;
   }
   if (current == nullptr) {
       cout << "Posisi melebihi panjang inventory" << endl;
       return;
   }

   if (current->next == nullptr){
        tambahItem(head, tail, jumlah, namaItem, tipe);
   } else {
        Node *nodeBaru = new Node;
        nodeBaru->ID = nextID++;
        nodeBaru->namaItem = namaItem;
        nodeBaru->jumlah = jumlah;
        nodeBaru->tipe = tipe;
        nodeBaru->next = current->next;
        nodeBaru->prev = current;
        current->next->prev = nodeBaru;
        current->next = nodeBaru;

        cout << "Item berhasil disisipkan pada posisi " << posisi << " dengan ID: " << nodeBaru->ID << endl;
   }
}

void hapusItemTerakhir (Node *&head, Node *&tail) {
   if (tail == nullptr){
        cout << "Inventory kosong, tidak ada item yang dapat dihapus!" << endl;
        return;
   }

   Node *temp = tail;   
   if(head == tail){
        head = nullptr;
        tail = nullptr;
   } else {
        tail = tail->prev;
        tail->next = nullptr;
   }
    cout << "Item dengan ID " << temp->ID << " dihapus dari inventory." << endl;
    delete temp;
}

void gunakanItem(Node *&head, Node *&tail, string namaItem) {
    if (head == nullptr) {
        cout << "Inventory kosong, tidak ada item yang dapat digunakan!" << endl;
        return;
    }
    
    Node *temp = head;
    
    while (temp != nullptr) {
        if (temp->namaItem == namaItem) {
            temp->jumlah -= 1;
            cout << "Item " << temp->namaItem << " digunakan! Sisa: " << temp->jumlah << endl;
            
            if (temp->jumlah <= 0) {
                cout << "Item " << temp->namaItem << " habis dan dihapus dari inventory." << endl;
                
                // Hapus node
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                } else {
                    tail = temp->prev;
                }
                
                delete temp;
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Item " << namaItem << " tidak ditemukan!" << endl;
}

void tampilkanInventory(Node *head) {
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    
    Node *current = head;
    cout << "\n=== ISI INVENTORY ===\n";
    while (current != nullptr) {
        cout << "ID: " << current->ID << " | ";
        cout << "Nama: " << current->namaItem << " | ";
        cout << "Jumlah: " << current->jumlah << " | ";
        cout << "Tipe: " << current->tipe << endl;
        current = current->next;
    }
}

void tampilkanDetail(Node *head, string input) {
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    
    Node *current = head;
    bool found = false;
    
    bool isId = true;
    for (char c : input) {
        if (!isdigit(c)) {
            isId = false;
            break;
        }
    }
    
    while (current != nullptr) {
        bool match = false;
        
        if (isId) {
            int inputId = stoi(input);
            if (current->ID == inputId) {
                match = true;
            }
        } else {
            if (current->namaItem == input) {
                match = true;
            }
        }
        
        if (match) {
            cout << "\n=== DETAIL ITEM DITEMUKAN ===\n";
            cout << "ID: " << current->ID << endl;
            cout << "Nama Item: " << current->namaItem << endl;
            cout << "Jumlah: " << current->jumlah << endl;
            cout << "Tipe: " << current->tipe << endl;
            cout << "==========================\n";
            found = true;
            break;
        }
        current = current->next;
    }
    
    if (!found) {
        if (isId) {
            cout << "Item dengan ID " << input << " tidak ditemukan!" << endl;
        } else {
            cout << "Item dengan nama '" << input << "' tidak ditemukan!" << endl;
        }
    }
}

int main (){

    string namaItem, tipe, input;
    int pilihan;
    
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
        cout << "\n===============================================\n";
        cout << "|       GAME INVENTORY MANAGEMENT            |\n";
        cout << "|       " << nama << " - " << nim << "                      |\n";
        cout << "===============================================\n";
        cout << "| 1. Tambah Item Baru                        |\n";
        cout << "| 2. Sisipkan Item                           |\n";
        cout << "| 3. Hapus Item Terakhir                     |\n";
        cout << "| 4. Gunakan Item                            |\n";
        cout << "| 5. Tampilkan Inventory                     |\n";
        cout << "| 6. Tampilkan Inventory (Dari Depan)        |\n";
        cout << "| 7. Tampilkan Inventory (Dari Belakang)     |\n";
        cout << "| 8. Cari & Tampilkan Detail Item            |\n";
        cout << "| 0. Keluar                                  |\n";
        cout << "===============================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                tambahItem(head, tail, jumlahItem, namaItem, tipe);
                break;
                
            case 2:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                sisipkanItem(head, tail, jumlahItem, namaItem, tipe, posisiSisip);
                break;
                
            case 3: {
                cout << "Apakah Anda yakin ingin menghapus item terakhir? (y/n): ";
                char konfirmasi;
                cin >> konfirmasi;
                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    hapusItemTerakhir(head, tail);
                } else {
                    cout << "Item tidak jadi dihapus." << endl;
                }
                break;
            }
                
            case 4:
                tampilkanInventory(head);
                cout << endl;
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, namaItem);
                gunakanItem(head, tail, namaItem);
                break;
                
            case 5:
                tampilkanInventory(head);
                break;
                
            case 6:
                traversalHead(head);
                break;
                
            case 7:
                traversalTail(tail);
                break;
                
            case 8:
                cout << "Masukkan ID atau nama item yang ingin dicari: ";
                getline(cin, input);
                tampilkanDetail(head, input);
                break;
                
            case 0:
                cout << "Keluar dari program...\n";
                break;
                
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
    
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}

