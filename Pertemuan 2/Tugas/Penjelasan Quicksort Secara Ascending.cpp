#include <iostream>
using namespace std;

// Fungsi untuk menukar dua nilai dalam array
void swap (int arr[], int pos1, int pos2) {
    int temp; // Variabel sementara untuk menyimpan nilai
    temp = arr[pos1]; // Simpan nilai dari posisi pertama
    arr[pos1] = arr[pos2]; // Pindahkan nilai dari posisi kedua ke posisi pertama
    arr[pos2] = temp; // Masukkan nilai yang disimpan tadi ke posisi kedua
}

// Fungsi untuk membagi array menjadi dua bagian untuk quicksort
int partition (int arr[], int low, int high, int pivot) {
    int i = low; // Penunjuk untuk elemen yang sedang dicek
    int j = low; // Penunjuk untuk tempat menyimpan elemen yang lebih kecil dari pivot

    // Proses pengecekan elemen dari posisi low sampai high
    while (i <= high) {
        if (arr[i] > pivot) {
            // Jika nilai sekarang lebih besar dari pivot, lanjut ke elemen berikutnya
            i++;
        }
        else {
            // Jika nilai sekarang lebih kecil atau sama dengan pivot,
            // tukar posisinya ke bagian "kiri" array
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1; // Kembalikan posisi akhir dari elemen yang jadi pembatas
}

// Fungsi utama quicksort yang bekerja secara rekursif
void quicksort(int arr[], int low, int high) {
    if (low < high) { // Selama masih ada lebih dari satu elemen
        int pivot = arr[high]; // Ambil elemen terakhir sebagai pivot
        int pos = partition(arr, low, high, pivot); // Bagi array dan dapatkan posisi pivot yang baru

        // Lanjutkan quicksort untuk bagian kiri dan kanan dari pivot
        quicksort(arr, low, pos - 1); // Urutkan bagian kiri
        quicksort(arr, pos + 1, high); // Urutkan bagian kanan
    }
}

int main () {
    int n; // Menyimpan jumlah elemen dalam array
    cout << "Tentukan panjang array = ";
    cin >> n; // Input jumlah elemen dari pengguna

    int arr[n]; // Buat array dengan panjang sesuai input
    
    // Input nilai-nilai untuk array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Panggil fungsi quicksort untuk mengurutkan array
    quicksort(arr, 0, n - 1);

    // Tampilkan hasil array yang sudah diurutkan
    cout << "Berikutnya adalah array yang telah di sortir = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl; // Baris baru untuk merapikan tampilan
    return 0; // Program selesai dengan sukses
}
