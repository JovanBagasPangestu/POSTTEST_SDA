#include <iostream>
using namespace std;

void InputMatrix(float matrix[3][3])
{
    cout << "Masukkan elemen-elemen matrix: "<< endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << "masukkan elemen [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }       
}

void TampilkanMatrix(float matrix[3][3])
{
    cout << "Matrix: " << endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }       
}

float HitungDiagonalUtama(float matrix[3][3])
{
    float total = 0;
    for (int i=0; i<3; i++){
        total += matrix[i][i];
    }
    return total;
}

float HitungDiagonalSekunder(float matrix[3][3])
{
    float total = 0;
    for (int i=0; i<3; i++){
        total += matrix[i][2-i];
    }
    return total;
}

int main()
{
    float matrix[3][3];
    InputMatrix(matrix);
    float diagonalUtama = HitungDiagonalUtama(matrix);
    float diagonalSekunder = HitungDiagonalSekunder(matrix);
    float total = diagonalUtama + diagonalSekunder;

    TampilkanMatrix(matrix);
    cout << "Jumlah diagonal utama   : " << diagonalUtama << endl;
    cout << "Jumlah diagonal sekunder: " << diagonalSekunder << endl;
    cout << "total                   : " << diagonalUtama << " + " << diagonalSekunder << " = " << total << endl;

    return 0;
}