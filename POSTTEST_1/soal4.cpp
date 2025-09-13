#include <iostream>
using namespace std;
void swap_interger (int **a, int **b){
    int temp = **a;
    **a = **b;
    **b = temp;
}
int main() {
    int x, y;
    cout << "Masukkan dua bilangan bulat: ";
    cin >> x >> y ;

    int *ptr_x = &x;
    int *ptr_y = &y;

    cout << "Sebelum ditukar: x = " << x << ", y = " << y << endl;
    swap_interger (&ptr_x, &ptr_y);
    cout << "Setelah ditukar: x = " << x << ", y = " << y << endl;
    return 0;
}