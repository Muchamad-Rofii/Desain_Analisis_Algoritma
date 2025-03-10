#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
	int i, j, tmp;
	for (i=0; i<n; i++){
		for (j=0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1]){
				tmp = arr [j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main (){
	int array [100], n, i, j;
	cout<<"masukan banyak elemen: ";
	cin>>n;
	cout<<"masukan nilai: \n";
	
	for (i = 0; i<n; i++){
		cin>>array[i];
	}
	
	bubblesort(array, n);
	cout<<"hasil pengurutan dengan algoritma bubblesort:\n";
	
	for (i=0; i<n; i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}
