#include <iostream>
using namespace std;

int main() {
    int x[] = {6, 12, 18, 24};
    int cari;
    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    int L = 0;
    int R = 3; // jumlah elemen - 1
    int mid;
    bool ditemukan = false;

    while (L <= R) {
        mid = (L + R) / 2;

        if (x[mid] == cari) {
            cout << "Bilangan ditemukan." << endl;
            ditemukan = true;
            break;
        } else if (x[mid] < cari) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    if (!ditemukan) {
        cout << "Bilangan tidak ditemukan." << endl;
    }

    return 0;
}
