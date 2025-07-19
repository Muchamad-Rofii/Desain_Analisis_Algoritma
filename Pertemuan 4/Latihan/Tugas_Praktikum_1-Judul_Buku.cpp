#include <iostream>
#include <string>
using namespace std;

class Buku {
    public:
    
        Buku(string judul)
        : judul_(judul) {
            cout << "Buku '" << judul_ << "' telah ditambahkan!" << endl;
        }

        
        ~Buku() {
            cout << "Buku '" << judul_ << "' telah dihapus!" << endl;
        }

        
        void TampilkanJudul() {
            cout << "Judul Buku: ";
            getline(cin, judul_);
            
        }

    private:
        string judul_;
};

int main() {
    
    Buku buku1("Harry potter"); // Membuat objek Buku dengan judul


    buku1.TampilkanJudul(); // Menampilkan judul buku

    
    Buku buku2("Sapu terbang");
    
    buku2.TampilkanJudul();

    return 0;
}
