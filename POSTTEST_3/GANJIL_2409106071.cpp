#include <iostream>
using namespace std;

struct item 
{
    int id;            
    string nama_item;
    int jumlah;
    string tipe;
};

struct node 
{
    item data;
    node *next;
    node *prev;
};

node *tail = nullptr; 


void tambah_item(node *&head) 
{
    node *node_baru = new node;

    cout << "Masukkan ID Item   : ";
    cin >> node_baru->data.id;

    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input ID harus berupa angka!\n";
        delete node_baru;   
        return;             
    }

    node *cek = head;
    while (cek != nullptr) 
    {
        if (cek->data.id == node_baru->data.id) {
            cout << "ID " << node_baru->data.id << " sudah digunakan!\n";
            delete node_baru;
            return;
        }
        cek = cek->next;
    }

    cin.ignore();
    cout << "Masukkan Nama Item : ";
    getline(cin, node_baru->data.nama_item);
    cout << "Masukkan Tipe Item : ";
    getline(cin, node_baru->data.tipe);

    node_baru->data.jumlah = 71; 
    node_baru->next = nullptr;
    node_baru->prev = nullptr;

    if (head == nullptr) {
        head = node_baru;
        tail = node_baru;
    } else {
        tail->next = node_baru;
        node_baru->prev = tail;
        tail = node_baru;
    }
    cout << "Item berhasil ditambahkan dengan jumlah awal = 71" << endl;
}

void sisip_item(node *&head) 
{
    int posisi = 1 + 1; 
    cout << "Posisi sisip otomatis berdasarkan NIM = " << posisi << endl;

    node *node_baru = new node;
    cout << "Masukkan ID Item   : ";
    cin >> node_baru->data.id;

    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input ID harus berupa angka!\n";
        delete node_baru;   
        return;             
    }

    node *cek = head;
    while (cek != nullptr) {
        if (cek->data.id == node_baru->data.id) {
            cout << "ID sudah dipakai!\n";
            delete node_baru;
            return;
        }
        cek = cek->next;
    }

    cin.ignore();
    cout << "Masukkan Nama Item : "; getline(cin, node_baru->data.nama_item);
    cout << "Masukkan Tipe Item : "; getline(cin, node_baru->data.tipe);

    node_baru->data.jumlah = 71;
    node_baru->next = nullptr;
    node_baru->prev = nullptr;

    if (head == nullptr || posisi == 1) {
        node_baru->next = head;
        if (head != nullptr) head->prev = node_baru;
        head = node_baru;
        if (tail == nullptr) tail = node_baru;
    } else {
        node *temp = head;
        for (int i = 1; temp->next != nullptr && i < posisi - 1; i++) {
            temp = temp->next;
        }
        node_baru->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = node_baru;
        temp->next = node_baru;
        node_baru->prev = temp;
        if (node_baru->next == nullptr) tail = node_baru;
    }
    cout << "Item berhasil disisipkan di posisi " << posisi << endl;
}

void hapus_item_terakhir(node *&head) 
{
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << "Item " << head->data.nama_item << " dihapus.\n";
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    cout << "Item " << tail->data.nama_item << " dihapus.\n";
    node *hapus = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete hapus;
}

void gunakan_item(node *&head) 
{
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    cin.ignore();
    string cari_nama;
    cout << "Masukkan nama item yang ingin digunakan: ";
    getline(cin, cari_nama);

    node *temp = head;
    while (temp != nullptr) {
        if (temp->data.nama_item == cari_nama) {
            temp->data.jumlah--;
            cout << "Menggunakan 1 " << cari_nama 
                 << ". Sisa: " << temp->data.jumlah << endl;

            if (temp->data.jumlah == 0) {
                cout << "Item " << cari_nama << " habis dan dihapus.\n";
                if (temp == head) {
                    head = temp->next;
                    if (head != nullptr) head->prev = nullptr;
                    else tail = nullptr;
                } else if (temp == tail) {
                    tail = temp->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Item tidak ditemukan!" << endl;
}

void tampilkan_inventory(node *head) 
{
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    cout << "\n==Daftar Inventory (Maju)==\n";
    int i = 1;
    node *temp = head;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->data.id << " - " << temp->data.nama_item
             << " (" << temp->data.tipe << ") - Jumlah: " 
             << temp->data.jumlah << endl;
        temp = temp->next;
    }
}

void tampilkan_inventory_reverse(node *tail) 
{
    if (tail == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    cout << "\n==Daftar Inventory (Mundur)==\n";
    int i = 1;
    node *temp = tail;
    while (temp != nullptr) {
        cout << i++ << ". " << temp->data.id << " - " << temp->data.nama_item
             << " (" << temp->data.tipe << ") - Jumlah: " 
             << temp->data.jumlah << endl;
        temp = temp->prev;
    }
}

void detail_item(node *head) 
{
    if (head == nullptr) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    cout << "Cari berdasarkan (1=ID, 2=Nama): ";
    int pilih; cin >> pilih;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus berupa angka!\n";
        return;
    }

    if (pilih == 1) {
        int id;
        cout << "Masukkan ID: ";
        cin >> id;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input ID harus angka!\n";
            return;
        }
        while (head != nullptr) {
            if (head->data.id == id) 
            {
                cout << "== Detail Item ==" << endl;
                cout << "ID     : " << head->data.id << endl;
                cout << "Nama   : " << head->data.nama_item << endl;
                cout << "Tipe   : " << head->data.tipe << endl;
                cout << "Jumlah : " << head->data.jumlah << endl;
                return;
            }
            head = head->next;
        }
    } else if (pilih == 2) {
        cin.ignore();
        string nama;
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        while (head != nullptr) {
            if (head->data.nama_item == nama) 
            {
                cout << "== Detail Item ==" << endl;
                cout << "ID     : " << head->data.id << endl;
                cout << "Nama   : " << head->data.nama_item << endl;
                cout << "Tipe   : " << head->data.tipe << endl;
                cout << "Jumlah : " << head->data.jumlah << endl;
                return;
            }
            head = head->next;
        }
    } else {
        cout << "Pilihan tidak valid!\n";
        return;
    }
    cout << "Item tidak ditemukan!" << endl;
}

int main() 
{
    node *head = nullptr;
    int pilihan;

    do {
        cout << "\n+----------------------------------------------------------------------+\n";
        cout << "|                      GAME INVENTORY MANAGEMENT                       |\n";
        cout << "|                [ 2409106071 - JOVAN BAGAS PANGESTU ]                 |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                                                  |\n";
        cout << "| 2. Sisipkan Item                                                     |\n";
        cout << "| 3. Hapus Item Terakhir                                               |\n";
        cout << "| 4. Gunakan Item                                                      |\n";
        cout << "| 5. Tampilkan Inventory (Maju)                                        |\n";
        cout << "| 6. Tampilkan Inventory (Mundur)                                      |\n";
        cout << "| 7. Detail Item (Cari ID/Nama)                                        |\n";
        cout << "| 0. Keluar                                                            |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus berupa angka!\n";
            pilihan = -1;
        }

        switch (pilihan) 
        {
            case 1: tambah_item(head); break;
            case 2: sisip_item(head); break;
            case 3: hapus_item_terakhir(head); break;
            case 4: gunakan_item(head); break;
            case 5: tampilkan_inventory(head); break;
            case 6: tampilkan_inventory_reverse(tail); break;
            case 7: detail_item(head); break;
            case 0: cout << "Keluar dari program..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}