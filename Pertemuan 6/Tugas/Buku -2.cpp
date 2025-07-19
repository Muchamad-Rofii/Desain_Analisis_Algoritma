#include <iostream>
#include <string>
using namespace std;

int main() {
    string buku[] = {
        "Algoritma dan Pemrograman",
        "Bahasa C++ Dasar",
        "Dasar-Dasar Jaringan",
        "Matematika Diskrit",
        "Pemrograman Web",
        "Sistem Basis Data",
        "Struktur Data"
    };
    
    string rak[] = {
        "Rak A1",
        "Rak A2",
        "Rak B1",
        "Rak C1",
        "Rak D3",
        "Rak E2",
        "Rak F4"
    };

    int jumlah = sizeof(buku) / sizeof(buku[0]);
    string dicari;
    
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, dicari); 

    int kiri = 0, kanan = jumlah - 1;
    int tengah;
    bool ditemukan = false;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;

        if (buku[tengah] == dicari) {
            cout << "Buku ditemukan di " << rak[tengah] << endl;
            ditemukan = true;
            break;
        } else if (buku[tengah] < dicari) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    if (!ditemukan) {
        cout << "Buku tidak ditemukan di perpustakaan." << endl;
    }

    return 0;
}
