#include <iostream>
using namespace std;

struct Mahasiswa 
{
    string nama;
    string NIM;
    float ipk;
};

void InputData(Mahasiswa mhs[], int jumlah)
{
    for(int i=0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        getline(cin, mhs[i].nama);
        cout << "NIM : ";
        getline(cin, mhs[i].NIM);
        cout << "IPK : ";
        cin >> mhs[i].ipk;
        cin.ignore(); 
    }
}

void TampilkanSemua(Mahasiswa mhs[], int jumlah)
{
    cout << "\n===Data Mahasiswa=== " << endl;
    for(int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].NIM << endl;
        cout << "IPK : " << mhs[i].ipk << endl;
    }
}

float cariIPKTertinggi(Mahasiswa mhs[], int jumlah) {
    float tertinggi = mhs[0].ipk;
    for (int i = 1; i < jumlah; i++) {
        if (mhs[i].ipk > tertinggi) {
            tertinggi = mhs[i].ipk;
        }
    }
    return tertinggi;
}

void tampilkanIPKTertinggi(Mahasiswa mhs[], int jumlah, float ipkTertinggi)
{
    cout << "\n===Mahasiswa dengan IPK tertinggi===" << endl;
    for (int i = 0; i < jumlah; i++) {
        if (mhs[i].ipk == ipkTertinggi) {
            cout << "Nama: " << mhs[i].nama << endl;
            cout << "NIM : " << mhs[i].NIM << endl;
            cout << "IPK : " << mhs[i].ipk << endl;
        }
    }
}

int main()
{
    Mahasiswa mhs[5];
    InputData(mhs, 5);
    system("cls");
    TampilkanSemua(mhs, 5);
    float ipkTertinggi = cariIPKTertinggi(mhs, 5);

    tampilkanIPKTertinggi(mhs, 5, ipkTertinggi);

    return 0;
}