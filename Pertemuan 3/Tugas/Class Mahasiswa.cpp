#include <iostream>
#include <vector>
using namespace std;


class Mahasiswa {
protected:
    string nama;
    int umur;
    string jurusan;
    string fakultas;

public:
    Mahasiswa(string nama, int umur, string jurusan, string fakultas) 
        : nama(nama), umur(umur), jurusan(jurusan), fakultas(fakultas) {}

    virtual void tampilkanData() {
        cout << "Nama     : " << nama << endl;
        cout << "Umur     : " << umur << endl;
        cout << "Jurusan  : " << jurusan << endl;
        cout << "Fakultas : " << fakultas << endl;
    }

    virtual ~Mahasiswa() {} 
};


class MahasiswaAktif : public Mahasiswa {
public:
    MahasiswaAktif(string nama, int umur, string jurusan, string fakultas) 
        : Mahasiswa(nama, umur, jurusan, fakultas) {}

    void tampilkanData() override {
        cout << "\n=== Mahasiswa Aktif ===\n";
        Mahasiswa::tampilkanData();
        cout << "Status   : Mahasiswa Aktif" << endl;
    }
};


class Alumni : public Mahasiswa {
public:
    Alumni(string nama, int umur, string jurusan, string fakultas) 
        : Mahasiswa(nama, umur, jurusan, fakultas) {}

    void tampilkanData() override {
        cout << "\n=== Alumni ===\n";
        Mahasiswa::tampilkanData();
        cout << "Status   : Alumni" << endl;
    }
};


void tambahMahasiswa(vector<Mahasiswa*>& daftarMahasiswa) {
    string nama, jurusan, fakultas, status;
    int umur;

    cin.ignore(); 
    cout << "\nMasukkan Nama: ";
    getline(cin, nama);

    cout << "Masukkan Umur: ";
    cin >> umur;
    cin.ignore(); 

    cout << "Masukkan Jurusan: ";
    getline(cin, jurusan);

    cout << "Masukkan Fakultas: ";
    getline(cin, fakultas);

    cout << "Status (Aktif/Alumni): ";
    getline(cin, status);

    if (status == "Aktif" || status == "aktif") {
        daftarMahasiswa.push_back(new MahasiswaAktif(nama, umur, jurusan, fakultas));
    } else {
        daftarMahasiswa.push_back(new Alumni(nama, umur, jurusan, fakultas));
    }

    cout << "Mahasiswa berhasil ditambahkan!\n";
}


void tampilkanSemuaMahasiswa(vector<Mahasiswa*>& daftarMahasiswa) {
    if (daftarMahasiswa.empty()) {
        cout << "\nBelum ada data mahasiswa.\n";
        return;
    }

    cout << "\n--- Daftar Mahasiswa ---\n";
    for (size_t i = 0; i < daftarMahasiswa.size(); i++) {
        daftarMahasiswa[i]->tampilkanData();
        cout << "----------------------" << endl;
    }
}


int main() {
    vector<Mahasiswa*> daftarMahasiswa;
    int pilihan;

    do {
        cout << "\n=== Menu ===";
        cout << "\n1. Tambah Mahasiswa";
        cout << "\n2. Tampilkan Semua Mahasiswa";
        cout << "\n3. Keluar";
        cout << "\nPilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa(daftarMahasiswa);
                break;
            case 2:
                tampilkanSemuaMahasiswa(daftarMahasiswa);
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 3);


    for (size_t i = 0; i < daftarMahasiswa.size(); i++) {
        delete daftarMahasiswa[i];
    }

    return 0;
}


