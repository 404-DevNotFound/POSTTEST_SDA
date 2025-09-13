#include <iostream>
using namespace std;

void balik_array (int *arr, int n){
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir){
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}
int main(){
    int n = 7;
    int arr [n];

    for (int i=0; i<n; i++){
        arr [i] = (i+1)*3;
    };

    cout << "Array sebelum dibalik: ";
    for (int i=0; i<n; i++){
        cout<< arr [i] << " ";
    };

    balik_array (arr, n); 
    cout << endl;

    cout << "Array setelah dibalik: ";
    for (int i=0; i<n; i++){
        cout << arr [i] << " ";
    };
    return 0;
}