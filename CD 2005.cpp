#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Thung {
	int b;
	int c;
};

void quickSort(vector<Thung> &arr, int l, int r) {
	int mid = (l + r) / 2;
    int i = l;
    int j = r;
        
    while (i <= j) {
        while (arr[i].c > arr[mid].c) i++;
        while (arr[j].c < arr[mid].c) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
        
    if (l < j) quickSort(arr, l, j);
    if (i < r) quickSort(arr, i, r);
}

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

	// Sap xep giam dan theo suc chua bang quick sort
	quickSort(thung, 0, nN - 1);

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