#include <iostream>
#include <string>
using namespace std;
struct Node {
	const int MAX_MAHASISWA = 100;
	int NIM;
	string nama;
	string jurusan;
	int tahunMasuk;
	int jumlahMahasiswa = 0;
	Node* next;

};

Node* START = NULL;

void tambahMahasiswa() {
	int nim;
	string nm;
	string jrsn;
	int tm;
	Node* nodeBaru = new Node();
	cout << "Masukan Nim : ";
	cin >> nim;
	cout << "Masukan Nama : ";
	cin >> nm;
	nodeBaru->NIM = nim;
	nodeBaru->nama = nm;
	nodeBaru->jurusan = jrsn;
	nodeBaru->tahunMasuk = tm;

	if (START == NULL || nim <= START->NIM) {
		if (START != NULL && nim == START->NIM)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}

		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (nim >= current->NIM))
	{
		if (nim == current->NIM) {
			cout << "NIM sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}


	nodeBaru->next = current;
	previous->next = nodeBaru;


}

bool searchNode(int nim, Node* current, Node* previous)
{
	previous = START;
	current = START;
	while (current != NULL && nim > current->NIM)
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		return false;
	}
	else if (current->NIM == nim)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool listEmpty() {
	if (START == NULL)
		return true;
	else
		return false;
}

void traverse() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << "NIM: " << currentNode->NIM;
			cout << "Nama: " << currentNode->nama;
			cout << "Jurusan : " << currentNode->jurusan;
			cout << "Tahun Masuk: " << currentNode->tahunMasuk;
			currentNode = currentNode->next;
		}
	}
}

void searchData() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukan NIM: ";
		cin >> nim;
		Node* currentNode = START;
		while (currentNode != NULL) {
			if (currentNode->NIM == nim) {
				cout << "NIM: " << currentNode->NIM;
				cout << "Nama: " << currentNode->nama;
				cout << "Jurusan : " << currentNode->jurusan;
				cout << "Tahun Masuk: " << currentNode->tahunMasuk;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Data tidak ditemukan" << endl;
	}
}

void searchDataTM() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int tm;
		cout << "Masukan Tahun Masuk: ";
		cin >> tm; 
		Node* currentNode = START;
		while (currentNode != NULL) {
			if (currentNode->tahunMasuk == tm) { 
				cout << "NIM: " << currentNode->NIM;
				cout << "Nama: " << currentNode->nama;
				cout << "Jurusan : " << currentNode->jurusan;
				cout << "Tahun Masuk: " << currentNode->tahunMasuk;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Data tidak ditemukan" << endl;
	}
}

int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			tambahMahasiswa();
			cout << "Data Berhasil Ditambahkan" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			traverse();
			break;
		case 3:
			searchData();
			break;
		case 4:
			searchDataTM();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}


// 2. singgle linked list
// 3. stack adalah data yang pertama masuk, terakhir keluarnya (LIFO), dan queue adalah data yang pertama masuk, pertama juga keluarnya (FIFO)
// 4. ketika ingin menggunakan struktur data dengan cara di tumpuk
// 5 a. ada 5
// 5 b. Postorder Traversal adalah membaca anak kiri, kemudian anak kanan, lalu rootnya

