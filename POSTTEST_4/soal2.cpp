#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char value) {
    Node* nodeBaru = new Node();
    nodeBaru->data = value;
    nodeBaru->next = top;
    top = nodeBaru;
}
// tambah karakter ke stack, bikin node baru, isi datanya, sambung ke top lama, lalu geser top ke node baru.

char pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack underflow" << endl;
        return '\0';
    }
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}
//ambil karakter dari atas stack, cek kalau kosong dulu, simpen data, geser top ke bawah, hapus node lama, lalu kembalikan datanya.

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // 1. Loop setiap karakter dalam `expr`
    for (char c : expr) {
        // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek
        else if (c == ')' || c == '}' || c == ']') {
            // a. Apakah stack kosong? Jika ya, return false
            if (stackTop == nullptr) {
                return false;
            }
            // b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka
            char topChar = pop(stackTop);
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false
    return stackTop == nullptr;
}
// cek apakah kurung dalam string seimbang, simpen kurung buka di stack, cek pasangan kurung tutup, kalau nggak cocok atau stack nggak kosong di akhir, kembalikan false.

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}