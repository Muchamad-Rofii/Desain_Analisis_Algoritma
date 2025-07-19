#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAKS = 10;
int biaya[MAKS][MAKS];
int jumlahKota;

int main() {
    cout << "Jumlah Kota yang Ingin Dihitung: ";
    cin >> jumlahKota;

    // Input matriks biaya
    cout << "\nMasukkan Nilai Matriks Biaya antar Kota:\n";
    for (int i = 0; i < jumlahKota; i++) {
        cout << "Baris ke-" << i + 1 << ":\n";
        for (int j = 0; j < jumlahKota; j++) {
            cin >> biaya[i][j];
            if (i != j && biaya[i][j] == 0)
                biaya[i][j] = INT_MAX; // Tidak terhubung dianggap sangat mahal
        }
    }

    // Tampilkan matriks biaya
    cout << "\nTabel Biaya antar Kota:\n";
    for (int i = 0; i < jumlahKota; i++) {
        for (int j = 0; j < jumlahKota; j++) {
            if (biaya[i][j] == INT_MAX)
                cout << "-\t";
            else
                cout << biaya[i][j] << "\t";
        }
        cout << endl;
    }

    // Siapkan permutasi untuk menjelajah semua kemungkinan rute
    vector<int> kota;
    for (int i = 0; i < jumlahKota; i++)
        kota.push_back(i);

    int biayaMinimum = INT_MAX;
    vector<int> ruteTerbaik;

    do {
        int totalBiaya = 0;
        bool bisaDilalui = true;

        for (int i = 0; i < jumlahKota - 1; i++) {
            int dari = kota[i];
            int ke = kota[i + 1];
            if (biaya[dari][ke] == INT_MAX) {
                bisaDilalui = false;
                break;
            }
            totalBiaya += biaya[dari][ke];
        }

        // Periksa kembali ke kota awal
        if (bisaDilalui && biaya[kota[jumlahKota - 1]][kota[0]] != INT_MAX) {
            totalBiaya += biaya[kota[jumlahKota - 1]][kota[0]];
            if (totalBiaya < biayaMinimum) {
                biayaMinimum = totalBiaya;
                ruteTerbaik = kota;
            }
        }

    } while (next_permutation(kota.begin(), kota.end()));

    // Tampilkan hasil
    if (!ruteTerbaik.empty()) {
        cout << "\nRute Paling Efisien:\n";
        for (int i = 0; i < ruteTerbaik.size(); i++) {
            cout << "K" << ruteTerbaik[i] + 1 << " ? ";
        }
        cout << "K" << ruteTerbaik[0] + 1 << endl;

        cout << "\nTotal Biaya Minimum: " << biayaMinimum << endl;
    } else {
        cout << "\nTidak ditemukan rute yang dapat melewati semua kota.\n";
    }

    return 0;
}

