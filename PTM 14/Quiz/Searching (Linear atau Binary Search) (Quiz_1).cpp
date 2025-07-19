#include <iostream>
using namespace std;

int main() {
    int x[] = {11, 22, 33, 44, 55, 66, 77};
    int cari;
    cout << "Angka yang dicari: ";
    cin >> cari;

    int L = 0;
    int R = 6; // jumllah elemen
    int mid;
    bool ditemukan = false;

    while (L <= R) {
        mid = (L + R) / 2;

        if (x[mid] == cari) {
            cout << "Angka ditemukan." << endl;
            ditemukan = true;
            break;
        } else if (x[mid] < cari) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    if (!ditemukan) {
        cout << "posisi index atau Data tidak ditemukan" << endl;
    }

    return 0;
}
