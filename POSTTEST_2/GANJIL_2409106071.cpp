#include <iostream>
using namespace std;

struct item 
{
    string nama_item;
    int jumlah;
    string tipe;
};

struct node 
{
    item data;
    node *next;
};

void tambah_item(node *&head)
{
    cin.ignore();
    node *node_baru = new node;
    cout << "Masukkan Nama Item : ";
    getline (cin, node_baru->data.nama_item);
    cout << "Masukkan Tipe Item : ";
    getline (cin, node_baru->data.tipe);

    node_baru->data.jumlah = 71;
    node_baru->next = nullptr;

    if (head==nullptr)
    {
        head = node_baru;
    }
    else

    {
        node *temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = node_baru;
    }
    cout << "Item berhasil ditambahkan dengan jumlah awal = 71" << endl;
}

void sisip_item(node *&head)
{
    int posisi = 1 + 1;
    cout << "Posisi sisip otomatis berdasarkan NIM = " << posisi << endl;

    cin.ignore();
    node *node_baru = new node;
    cout << "Masukkan Nama Item : ";    
    getline (cin, node_baru->data.nama_item);
    cout << "Masukkan Tipe Item : ";
    getline (cin, node_baru->data.tipe);
    node_baru->data.jumlah = 71;
    node_baru->next = nullptr;

    if (head == nullptr || posisi == 1) 
    {
        node_baru->next = head;
        head = node_baru;
    } 
    else 
    {
        node *temp = head;
        for (int i = 1; temp->next != nullptr && i < posisi - 1; i++) {
            temp = temp->next;
        }
        node_baru->next = temp->next;
        temp->next = node_baru;
    }
    cout << "Item berhasil disisipkan di posisi " << posisi << endl;
}

void hapus_item_terakhir(node *&head)
{
    if (head == nullptr)
    {
        cout << "inventory kosong!" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        cout << "item terakhir dihapus." << endl;
        return;
    }
    node *temp = head;
    while (temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    cout << "Item terakhir dihapus." << endl;
}

void gunakan_item(node *&head)
{
    if (head == nullptr)
    {
        cout << "inventory kosong!" << endl;
        return;
    }

    cin.ignore();
    string cari_nama;
    cout << "Masukkan nama item yang ingin digunakan: ";
    getline (cin, cari_nama);

    node *temp = head;
    node *prev = nullptr;
    
    while (temp != nullptr)
    {
        if(temp->data.nama_item == cari_nama)
        {
            temp->data.jumlah--;
            cout << "Menggunakan 1 " << cari_nama << ". Sisa: " << temp->data.jumlah << endl;
        
            if (temp->data.jumlah == 0) {
                if (prev == nullptr) { 
                    head = temp->next;
                    delete temp;
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
                cout << "Item " << cari_nama << " habis dan dihapus dari inventory." << endl;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item tidak ditemukan!" << endl;
}

void tampilkan_inventory(node *&head)
{
    if (head == nullptr)
    {
        cout << "Inventory kosong!" << endl;
        return;
    }
    cout <<"\n==Daftar Inventory:==\n"<< endl;
    int i = 1;
    node* temp = head; 
    while (temp != nullptr) 
    {
        cout << i++ << ". " << temp->data.nama_item
             << " (" << temp->data.tipe << ") - "
             << "Jumlah: " << temp->data.jumlah << endl;
        temp = temp->next;
    }
}

int main() 
{
    node *head = nullptr;
    int pilihan;

    do {
        cout << "\n+----------------------------------------------------------------------+\n";
        cout << "|                     GAME INVENTORY MANAGEMENT                        |\n";
        cout << "|                [ 2409106071 - JOVAN BAGAS PANGESTU ]                 |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                                                  |\n";
        cout << "| 2. Sisipkan Item                                                     |\n";
        cout << "| 3. Hapus Item Terakhir                                               |\n";
        cout << "| 4. Gunakan Item                                                      |\n";
        cout << "| 5. Tampilkan Inventory                                               |\n";
        cout << "| 0. Keluar                                                            |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus berupa angka!\n";
            pilihan = -1;
        }

        switch (pilihan) {
            case 1: tambah_item(head); break;
            case 2: sisip_item(head); break;
            case 3: hapus_item_terakhir(head); break; 
            case 4: gunakan_item(head); break;
            case 5: tampilkan_inventory(head); break; 
            case 0: cout << "Keluar dari program..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}