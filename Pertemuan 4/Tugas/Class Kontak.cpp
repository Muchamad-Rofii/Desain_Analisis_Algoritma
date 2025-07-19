#include <iostream>
#include <vector>

using namespace std;

class Kontak {
private:
    string nama;
    string nomorTelepon;

public:
    // Constructor
    Kontak(string n, string no) {
        nama = n;
        nomorTelepon = no;
    }

    void tampilkan() {
        cout << "Nama: " << nama << endl;
        cout << "Nomor Telepon: " << nomorTelepon << endl;
        cout << "----------------------------------------" << endl;
    }

    // Destructor
    ~Kontak() {
        cout << "Kontak " << nama << " dihapus dari memori." << endl;
    }
};

int main() {
    vector<Kontak*> daftarKontak; 
    int jumlahKontak = 0;
    char pilihan;

    cout << "Masukkan kontak (maksimal 10 kontak)" << endl;

    do {
        if (jumlahKontak >= 10) {
            cout << "Kapasitas kontak penuh!" << endl;
            break;
        }

        string nama, nomor;
        cout << "\nMasukkan nama kontak ke-" << (jumlahKontak + 1) << " : ";
        getline(cin, nama);
        cout << "Masukkan nomor telepon kontak ke-" << (jumlahKontak + 1) << " : ";
        getline(cin, nomor);

        daftarKontak.push_back(new Kontak(nama, nomor));
        jumlahKontak++;

        cout << "Kontak berhasil ditambahkan" << endl;
        cout << "Tambahkan kontak lagi? (y/n): ";
        cin >> pilihan;
        cin.ignore(); 

    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "\nDaftar Kontak:\n";
    for (size_t i = 0; i < daftarKontak.size(); i++) {
        cout << "Kontak ke-" << (i + 1) << endl;
        daftarKontak[i]->tampilkan();
    }

    for (size_t i = 0; i < daftarKontak.size(); i++) {
        delete daftarKontak[i];
    }
    daftarKontak.clear();

    return 0;
}
