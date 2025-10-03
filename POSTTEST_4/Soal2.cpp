#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i]; // loop untuk mengecek setiap karakter pada string   

        // Jika kurung buka, push ke stack
        if (c == '(' || c == '{' || c == '[') {
            Node* newNode = new Node{c, stackTop};
            stackTop = newNode; //push ke stack 
        }
       
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) {
                return false; // stack kosong tapi ada kurung tutup
            }
            char topChar = stackTop->data;
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false; // Tidak cocok
            }
            // Pop stack
            Node* temp = stackTop;
            stackTop = stackTop->next;
            delete temp;
        }
    }

    if (stackTop == nullptr) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}