#include <iostream>
#include <vector>
using namespace std;

class Buku {
private:
    string judul;
    string penulis;
    bool tersedia;

public:
    Buku(string j, string p) : judul(j), penulis(p), tersedia(true) {}
    
    void setJudul(string j) { judul = j; }
    void setPenulis(string p) { penulis = p; }
    void setTersedia(bool t) { tersedia = t; }
    
    string getJudul() const { return judul; }
    string getPenulis() const { return penulis; }
    bool isTersedia() const { return tersedia; }
    
    void pinjamBuku() {
        if (tersedia) {
            tersedia = false;
            cout << "Buku '" << judul << "' berhasil dipinjam.\n";
        } else {
            cout << "Buku '" << judul << "' sedang tidak tersedia.\n";
        }
    }
    
    void kembalikanBuku() {
        tersedia = true;
        cout << "Buku '" << judul << "' telah dikembalikan.\n";
    }
    
    void tampilkanInfo() const {
        cout << "Judul: " << judul << ", Penulis: " << penulis << ", Status: " << (tersedia ? "Tersedia" : "Dipinjam") << endl;
    }
};

int main() {
    vector<Buku> perpustakaan;
    int jumlahBuku;
    
    cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
    cin >> jumlahBuku;
    cin.ignore();
    
    for (int i = 0; i < jumlahBuku; i++) {
        string judul, penulis;
        cout << "Masukkan judul buku ke-" << (i + 1) << ": ";
        getline(cin, judul);
        cout << "Masukkan penulis buku ke-" << (i + 1) << ": ";
        getline(cin, penulis);
        perpustakaan.push_back(Buku(judul, penulis));
    }
    
    int pilihan;
    do {
        cout << "\nMenu:\n1. Pinjam Buku\n2. Kembalikan Buku\n3. Tampilkan Daftar Buku\n4. Keluar\nPilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        if (pilihan == 1) {
            if (perpustakaan.empty()) {
                cout << "Tidak ada buku di perpustakaan!\n";
                continue;
            }
            int index;
            cout << "Masukkan nomor buku yang ingin dipinjam: ";
            cin >> index;
            if (index > 0 && index <= (int)perpustakaan.size()) {
                perpustakaan[index - 1].pinjamBuku();
            } else {
                cout << "Nomor buku tidak valid!\n";
            }
        } else if (pilihan == 2) {
            if (perpustakaan.empty()) {
                cout << "Tidak ada buku di perpustakaan!\n";
                continue;
            }
            int index;
            cout << "Masukkan nomor buku yang ingin dikembalikan: ";
            cin >> index;
            if (index > 0 && index <= (int)perpustakaan.size()) {
                perpustakaan[index - 1].kembalikanBuku();
            } else {
                cout << "Nomor buku tidak valid!\n";
            }
        } else if (pilihan == 3) {
            if (perpustakaan.empty()) {
                cout << "Tidak ada buku di perpustakaan!\n";
            } else {
                cout << "\nDaftar Buku di Perpustakaan:\n";
                for (size_t i = 0; i < perpustakaan.size(); i++) {
                    cout << i + 1 << ". ";
                    perpustakaan[i].tampilkanInfo();
                }
            }
        }
    } while (pilihan != 4);
    
    cout << "Program selesai. Terima kasih!\n";
    return 0;
}

