#include <iostream>
using namespace std;

// Struktur dasar untuk node pohon biner
struct Simpul {
    int data;
    Simpul* kiri;
    Simpul* kanan;
};

// Membuat simpul baru dengan nilai tertentu
Simpul* buatNodeBaru(int nilai) {
    Simpul* nodeBaru = new Simpul();
    nodeBaru->data = nilai;
    nodeBaru->kiri = NULL;
    nodeBaru->kanan = NULL;
    return nodeBaru;
}

// Menyisipkan nilai ke dalam pohon (rekursif)
Simpul* sisipkan(Simpul* akar, int nilai) {
    if (akar == NULL) {
        return buatNodeBaru(nilai);
    }

    if (nilai < akar->data) {
        akar->kiri = sisipkan(akar->kiri, nilai);
    } else {
        akar->kanan = sisipkan(akar->kanan, nilai);
    }

    return akar;
}

// Traversal Preorder: akar -> kiri -> kanan
void preorder(Simpul* akar) {
    if (akar != NULL) {
        cout << akar->data << " ";
        preorder(akar->kiri);
        preorder(akar->kanan);
    }
}

// Traversal Inorder: kiri -> akar -> kanan
void inorder(Simpul* akar) {
    if (akar != NULL) {
        inorder(akar->kiri);
        cout << akar->data << " ";
        inorder(akar->kanan);
    }
}

// Traversal Postorder: kiri -> kanan -> akar
void postorder(Simpul* akar) {
    if (akar != NULL) {
        postorder(akar->kiri);
        postorder(akar->kanan);
        cout << akar->data << " ";
    }
}

int main() {
    Simpul* akar = NULL;
    int jumlah, nilai;

    cout << "Masukkan jumlah elemen: ";
    cin >> jumlah;

    cout << "Masukkan " << jumlah << " nilai:\n";
    for (int i = 0; i < jumlah; ++i) {
        cin >> nilai;
        akar = sisipkan(akar, nilai);
    }

    cout << "\nHasil Preorder: ";
    preorder(akar);

    cout << "\nHasil Inorder: ";
    inorder(akar);

    cout << "\nHasil Postorder: ";
    postorder(akar);

    cout << endl;
    return 0;
}

