#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int arr[n][n];

    cout << "Masukkan elemen array 3x3:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    int jumlah_diagonal_utama = 0;
    int jumlah_diagonal_sekunder = 0;
    
    for (int i = 0; i < n; i++) {
        jumlah_diagonal_utama += arr[i][i];
        jumlah_diagonal_sekunder += arr[i][n - 1 - i];
    }

    cout <<"matriks 3x3:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Jumlah diagonal utama= " << jumlah_diagonal_utama << endl;
    cout << "Jumlah diagonal sekunder= " << jumlah_diagonal_sekunder << endl;
    return 0;
}