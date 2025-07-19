#include <iostream>
#include <string>

using namespace std;

class AntrianTiket {
private:
    static const int MAX_ANTRIAN = 5;
    string daftarAntrian[MAX_ANTRIAN];
    int depanAntrian, belakangAntrian;

public:
    AntrianTiket() {
        depanAntrian = -1;
        belakangAntrian = -1;
    }

    bool isFull() {
        return belakangAntrian == MAX_ANTRIAN - 1;
    }

    bool isEmpty() {
        return depanAntrian == -1 || depanAntrian > belakangAntrian;
    }

    void tambahPembeli(const string& namaPembeli) {
        if (isFull()) {
            cout << "Maaf, antrian sudah penuh. Pembeli " << namaPembeli << " tidak bisa ditambahkan.\n\n";
            return;
        }
        if (isEmpty()) {
            depanAntrian = 0;
            belakangAntrian = 0;
        } else {
            belakangAntrian++;
        }
        daftarAntrian[belakangAntrian] = namaPembeli;
        cout << "Pembeli " << namaPembeli << " berhasil ditambahkan ke antrian.\n\n";
    }

    void layaniPembeli() {
        if (isEmpty()) {
            cout << "Maaf, antrian kosong. Tidak ada pembeli untuk dilayani.\n\n";
            return;
        }
        cout << "Pembeli " << daftarAntrian[depanAntrian] << " telah dilayani.\n\n";
        depanAntrian++;

        if (depanAntrian > belakangAntrian) {
            depanAntrian = -1;
            belakangAntrian = -1;
        }
    }

    void tampilkanAntrianSaatIni() {
        if (isEmpty()) {
            cout << "Antrian tiket saat ini kosong.\n\n";
        } else {
            cout << "\n--- DAFTAR ANTRIAN TIKET SAAT INI ---\n\n";
            for (int i = depanAntrian; i <= belakangAntrian; i++) {
                cout << "  " << (i - depanAntrian + 1) << ". " << daftarAntrian[i] << "\n";
            }
            cout << "------------------------------------------\n\n";
        }
    }
};

int main() {
    AntrianTiket loketTiket;
    int pilihanMenu;
    string namaPembeli;

    do {
        cout << "========== SISTEM ANTRIAN LOKET TIKET BIOSKOP ==========\n";
        cout << "1. Tambah Pembeli ke Antrian\n";
        cout << "2. Layani Pembeli Berikutnya\n";
        cout << "3. Lihat Antrian Saat Ini\n";
        cout << "4. Keluar dari Program\n";
        cout << "---------------------------------------------------------\n";
        cout << "Masukkan pilihan Anda (1-4): ";
        cin >> pilihanMenu;

        cin.ignore(); 

        switch (pilihanMenu) {
            case 1:
                cout << "Masukkan nama pembeli: ";
                getline(cin, namaPembeli);
                loketTiket.tambahPembeli(namaPembeli);
                break;
            case 2:
                loketTiket.layaniPembeli();
                break;
            case 3:
                loketTiket.tampilkanAntrianSaatIni();
                break;
            case 4:
                cout << "\nTerima kasih telah menggunakan sistem antrian.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan masukkan angka antara 1 dan 4.\n";
        }

    } while (pilihanMenu != 4);

    return 0;
}
