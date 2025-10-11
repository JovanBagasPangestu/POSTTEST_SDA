#include <iostream>
using namespace std;
// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * 1. Cek jika tree kosong.
 * 2. Selama masih ada anak kanan (right child), terus telusuri ke kanan.
 * 3. Node paling kanan adalah node dengan nilai terbesar.
 */
int findMaxValue(Node* root) {
    // Jika tree kosong, kembalikan -1 
    if (root == nullptr) {
        return -1;
    }
    // Telusuri ke kanan sampai tidak ada lagi anak kanan
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    // current sekarang menunjuk node paling kanan -> nilai terbesar
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // Harusnya output: 80
    return 0;
}