#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}
// Ini buat nambah node baru ke stack, data dimasukin dan top digeser ke node baru.

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}
// Ini ngambil data dari atas stack, pindahin top ke bawah, lalu hapus node lama biar rapi.

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // 1. Push setiap karakter dari string s ke dalam stack
    for (char c : s) {
        push(stackTop, c);
    }

    // 2. Pop setiap karakter dari stack dan tambahkan ke string reversed
    while (stackTop != nullptr) {
        char c = pop(stackTop);
        if (c != '\0') {
            reversed += c;
        }
    }

    return reversed;
}
// Fungsi ini pakai stack buat balik string, semua karakter dimasukin ke stack terus diambil balik buat urutannya terbalik.

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
    return 0;
}