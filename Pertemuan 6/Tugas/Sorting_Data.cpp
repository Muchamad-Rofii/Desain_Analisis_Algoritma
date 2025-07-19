#include <iostream>
using namespace std;

class Angka {
private:
    int data[5];

public:
    Angka() {
        data[0] = 5;
        data[1] = 2;
        data[2] = 9;
        data[3] = 1;
        data[4] = 7;
    }

    void tampilkan() {
        for (int i = 0; i < 5; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void bubbleSort() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 - i; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    Angka angka;
    cout << "Data sebelum sorting: ";
    angka.tampilkan();

    angka.bubbleSort();

    cout << "Data setelah sorting: ";
    angka.tampilkan();

    return 0;
}

