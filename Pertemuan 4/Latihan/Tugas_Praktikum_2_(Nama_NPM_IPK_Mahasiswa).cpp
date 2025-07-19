#include <iostream>
using namespace std;

class Mahasiswa{
	private:
		string nama;
		string npm;
		double ipk;

public:
	Mahasiswa(string n, string id, double i){
		nama = n;
		npm = id;
		ipk = i;
	}
	
	void tampilkanData(){
		cout<<"nama: "<<nama<<"\nNPM: "<<npm<<"\nIPK: "<<ipk<<"\n\n";
	}
	
	~Mahasiswa(){
		cout<<"Data Mahasiswa "<<nama<<"telah dihapus.\n";
	}
};

int main(){
	int jumlah;
	
	cout<<"Masukan Jumlah Mahasiswa: ";
	cin>>jumlah;
	cin.ignore();

	Mahasiswa* daftarMahasiswa[jumlah];

	for(int i=0; i<jumlah; i++){
		string nama, npm;
		double ipk;
		
		cout<<"\nMasukan data Mahasiswa ke-"<<(i+1)<<":\n";
		cout<<"Nama: ";
		getline(cin, nama);
		cout<<"NPM: ";
		getline(cin, npm);
		cout<<"ipk: ";
		cin>>ipk;
		
		daftarMahasiswa[i] = new Mahasiswa(nama, npm, ipk);
	}
	
	cout<<"\nDaftar Mahasiswa: \n";
	for (int i = 0; i < jumlah; i++){
		daftarMahasiswa[i]->tampilkanData();
	}
	
	for(int i=0; i<jumlah; i++){
		delete daftarMahasiswa[i];
	}
	return 0;
}
