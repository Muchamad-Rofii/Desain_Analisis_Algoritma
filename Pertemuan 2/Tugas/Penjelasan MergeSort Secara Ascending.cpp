#include <iostream>
using namespace std;

// Fungsi untuk menggabungkan dua subarray yang telah terurut menjadi satu subarray yang juga terurut
void merge(int arr[], int l, int m, int r) {
    int x, y, z; // Indeks untuk proses iterasi
    int n1 = m - l + 1; // Jumlah elemen pada subarray sebelah kiri
    int n2 = r - m;     // Jumlah elemen pada subarray sebelah kanan

    int L[n1], R[n2]; // Array sementara untuk menyimpan elemen-elemen dari masing-masing subarray

    // Menyalin elemen dari array utama ke dalam array sementara L[] dan R[]
    for (x = 0; x < n1; x++)
        L[x] = arr[l + x];
    for (y = 0; y < n2; y++)
        R[y] = arr[m + 1 + y];

    x = 0; // Indeks awal untuk L[]
    y = 0; // Indeks awal untuk R[]
    z = l; // Indeks awal untuk array gabungan arr[]

    // Proses penggabungan elemen dari L[] dan R[] ke dalam arr[] dengan urutan yang terjaga
    while (x < n1 && y < n2) {
        if (L[x] <= R[y]) { // Jika elemen di L lebih kecil atau sama dengan elemen di R
            arr[z] = L[x];  // Salin elemen dari L ke arr
            x++;            // Pindah ke elemen berikutnya di L
        } else {            // Jika elemen di R lebih kecil dari elemen di L
            arr[z] = R[y];  // Salin elemen dari R ke arr
            y++;            // Pindah ke elemen berikutnya di R
        }
        z++; // Lanjutkan ke posisi berikutnya dalam array gabungan
    }

    // Menyalin sisa elemen dari L[], jika masih ada
    while (x < n1) {
        arr[z] = L[x];
        x++;
        z++;
    }

    // Menyalin sisa elemen dari R[], jika masih ada
    while (y < n2) {
        arr[z] = R[y];
        y++;
        z++;
    }
}

// Fungsi utama untuk melakukan merge sort secara rekursif
void mergeSort(int arr[], int l, int r) {
    if (l < r) { // Jika masih terdapat lebih dari satu elemen dalam subarray
        int m = l + (r - l) / 2; // Menentukan titik tengah dari subarray

        // Memanggil mergeSort secara rekursif untuk bagian kiri dan kanan
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Menggabungkan dua bagian yang telah diurutkan
        merge(arr, l, m, r);
    }
}

// Fungsi untuk menampilkan isi array
void show(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main() {
    int size; // Variabel untuk menyimpan jumlah elemen array
    cout << "\nMasukan Banyak Data : ";
    cin >> size; // Membaca jumlah elemen dari input pengguna

    int arr[size]; // Mendeklarasikan array dengan panjang sesuai input

    // Input nilai-nilai array dari pengguna
    for (int i = 0; i < size; i++) {
        cout << "\nMasukan Data array ke-" << i << " : ";
        cin >> arr[i];
    }

    // Memanggil fungsi merge sort untuk mengurutkan array
    mergeSort(arr, 0, size - 1);

    // Menampilkan hasil array yang telah diurutkan
    cout << "\nHasil\n";
    show(arr, size);

    return 0; // Mengembalikan 0 menandakan bahwa program telah selesai dijalankan dengan sukses
}
