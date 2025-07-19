#include <iostream>
using namespace std;

void selectionSort(int arr[], int n);

int main (){
	int n, i;
	cout << "Masukan jumlah elemen : ";
	cin >> n;
	int arr[n];
	
	cout<<endl;
	
	for (i = 0; i < n; i++){
		cout << "Masukan nilai elemen : ";
		cin >> arr[i];
	}
	
	cout << "\nData sebelum sorting : ";
	for (i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	selectionSort (arr, n);
	cout << "Data setelah sorting : ";
	for (i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

void selectionSort (int arr[], int n) {
	int i, j, Indeks_Terbesar, temp;
	for (i = 0; i < n-1; i++){
		Indeks_Terbesar = i;
		for (j = i+1; j < n; j++){
			if (arr[j] > arr[Indeks_Terbesar]) {
				Indeks_Terbesar = j;
			}
		}
		temp = arr[Indeks_Terbesar];
		arr[Indeks_Terbesar] = arr[i];
		arr[i] = temp;
		cout << "Iterasi ke-" << i+1 << ": ";
		for (int k = 0; k < n; k++){
			cout << arr[k] << " ";
		}
		cout << endl;
	}
	
}
