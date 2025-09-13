#include <iostream>
using namespace std;

void TampilkanArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BalikArray(int *ptr, int size) {
    int *awal = ptr;
    int *akhir = ptr + size - 1;
    while(awal<akhir){
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int data[7];

    for (int i = 0; i < 7; i++){
        data[i]=(i+1)*3;
    }
    cout << "Array sebelum dibalik: ";
    TampilkanArray(data, 7);
    BalikArray(data, 7);
    cout << "Array setelah dibalik: ";
    TampilkanArray(data, 7);

    return 0;
}