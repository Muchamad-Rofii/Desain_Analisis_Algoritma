#include <iostream>       // Menyertakan pustaka iostream untuk input/output
using namespace std;      // Menggunakan namespace std agar tidak perlu menulis std:: setiap kali

// Mendefinisikan class bernama 'contoh'
class contoh
{
private:
    int nilai;            // Anggota data private bernama 'nilai'

public:
    // Konstruktor dengan parameter
    contoh(int n)
    {
        nilai = n;        // Menyimpan nilai parameter ke dalam atribut 'nilai'
    }

    // Fungsi anggota untuk mengembalikan nilai dari atribut 'nilai'
    int getNum()
    {
        return nilai;     // Mengembalikan nilai atribut 'nilai'
    }
};

// Fungsi utama program
int main()
{
    contoh obj(10);       // Membuat objek 'obj' dari class 'contoh' dengan nilai 10
    cout << "Nilai yang diinput: " << obj.getNum() << endl;  
                          // Menampilkan nilai dari objek dengan memanggil fungsi getNum()
    
    return 0;             // Mengembalikan nilai 0 menandakan program selesai dengan sukses
}

