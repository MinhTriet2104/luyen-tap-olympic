#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Thung {
	int b;
	int c;
};

int main() {
	ifstream docFile;
	ofstream ghiFile;

	docFile.open("WATER.INP");

	// Doc so luong thung
	int nN = 0;
	docFile >> nN;

	vector<Thung> thung(nN);
	int tongB = 0;
	int tongC = 0;

	// Doc file dong thoi tinh tong suc chua va nuoc dang chua
	for (int i = 0; i < nN; i++) {
		docFile >> thung[i].b;
		tongB += thung[i].b;
		docFile >> thung[i].c;
		tongC += thung[i].c;
	}
	docFile.close();

	// Sap xep giam dan theo suc chua
	for (int i = 0; i < nN - 1; i++) {
		for (int j = i + 1; j < nN; j++) {
			if (thung[j].c > thung[i].c) {
				swap(thung[i], thung[j]);
			}
		}
	}

	int nuocThieu = tongC - tongB; // Lay ra so nuoc thieu
	int count = 0;
	int i = 0;
	while(nuocThieu > 0) {
		nuocThieu -= thung[i].c; // Tru cho so nuoc chua nhieu nhat
		count++;
		i++; // Mot lan tru se la 1 thung phai dem di
	}

	ghiFile.open("WATER.OUT");
	ghiFile << count;
	ghiFile.close();

	system("pause");
	return 0;
}