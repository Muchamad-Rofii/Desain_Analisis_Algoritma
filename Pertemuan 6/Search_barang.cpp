#include <iostream>
#include <string>
using namespace std;

struct barang {
	string nama;
	int harga;
};

int search(const barang daftar[], int ukuran, string brg) {
	for (int i = 0; i < ukuran; i++) {
		if (daftar[i].nama == brg) {
			return i;
		}
	}
	return -1;
}

int main()
{
	string brg;
	char ulang;
	int ukuran_daftar = 5;

	barang daftarbarang[5] = { {"Buku",5000}, {"Pensil", 1000}, {"Pulpen", 2000}, {"Penghapus", 500}, {"Penggaris", 1500}
	};

	do {
		cout << "Masukkan nama barang yang ingin dicari: ";
		cin >> brg;

		int indeks = search (daftarbarang, ukuran_daftar, brg);

		if (indeks != -1) {
			cout << "Barang " << daftarbarang[indeks].nama << " ditemukan dengan harga " << daftarbarang[indeks].harga << endl;
		} else {
			cout << "Maaf, barang " << brg << " tidak ditemukan dalam daftar" << endl;
		}

		cout << "Apakah ingin mencari barang lagi? (y/n): ";
		cin >> ulang;
	} while (ulang == 'y' || ulang == 'Y');

	cout << "\nTerima kasih!\n";
	return 0;
}
