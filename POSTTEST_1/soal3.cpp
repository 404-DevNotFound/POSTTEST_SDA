#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    int n =5;
    mahasiswa mhs[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data mahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Nama: ";
        cin.ignore ();
        getline (cin, mhs[i].nama);
        cout << "NIM: ";
        getline (cin, mhs[i].nim);
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    int ipk_tertinggi = 0;
    for (int i = 1; i < n; i++) {
        if (mhs[i].ipk > mhs[ipk_tertinggi].ipk) {
            ipk_tertinggi = i;
        }
    }

    cout << "Data mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << mhs[ipk_tertinggi].nama << endl
        << "NIM: " << mhs[ipk_tertinggi].nim << endl
        << "IPK: " << mhs[ipk_tertinggi].ipk << endl;
    return 0;
}