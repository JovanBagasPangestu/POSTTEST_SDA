#include <iostream>
using namespace std;

void Tukar_Nilai(int **a, int **b) 
{
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main()
{
    int x, y;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    cout << "\n=== SEBELUM PENUKARAN ===" << endl;
    cout << "Nilai x: " << x << " (Alamat: " << &x << ")" << endl;
    cout << "Nilai y: " << y << " (Alamat: " << &y << ")" << endl;

    int *ptrX = &x;
    int *ptrY = &y;

    cout << "\nPointer sebelum pertukaran:" << endl;
    cout << "ptrX menunjuk ke: " << ptrX << " (Nilai: " << *ptrX << ")" << endl;
    cout << "ptrY menunjuk ke: " << ptrY << " (Nilai: " << *ptrY << ")" << endl;

    Tukar_Nilai(&ptrX, &ptrY);

    cout << "\n=== SETELAH PENUKARAN ===" << endl;
    cout << "Nilai x: " << x << " (Alamat: " << &x << ")" << endl;
    cout << "Nilai y: " << y << " (Alamat: " << &y << ")" << endl;

    cout << "\nPointer setelah pertukaran:" << endl;
    cout << "ptrX menunjuk ke: " << ptrX << " (Nilai: " << *ptrX << ")" << endl;
    cout << "ptrY menunjuk ke: " << ptrY << " (Nilai: " << *ptrY << ")" << endl;
    
    return 0;
}