#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // 1. Jika kosong
    if (front == nullptr) {
        front = rear = newNode;
    }
    // 2. Jika tidak kosong
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // 1. Simpan data
    string doc = front->document;

    // 2. Geser front
    Node* temp = front;
    front = front->next;

    // 3. Jika front kosong, maka rear juga harus di-set ke nullptr
    if (front == nullptr) {
        rear = nullptr;
    }

    // 4. Hapus node lama
    delete temp;
    return doc;
}

void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}