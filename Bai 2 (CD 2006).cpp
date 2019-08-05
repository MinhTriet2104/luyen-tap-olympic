#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Tinh tong cot doc
int sumRow(vector<vector<int>> arr, int y, int x) {
	int sum = 0;
	for (int i = 0; i <= y; i++) {
		sum += arr[i][x];
	}	
	return sum;
}

int main() {
	ifstream docFile;
	int x, y = 0;
	
	// Doc gia tri cot doc va ngang
	docFile.open("IIMAGE.INP");
	docFile >> y; // Doc
	docFile >> x; // Ngang

	ofstream ghiFile;
	ghiFile.open("IIMAGE.OUT");

	vector<vector<int>> image(y, vector<int>(x));

	int prev; // luu ket qua truoc do

	for (int i = 0; i < y; i++) {
		prev = 0; // Tro ve 0 sau moi dong ket thuc
		for (int j = 0; j < x; j++) {
			docFile >> image[i][j];
			if (j == 0) {
				ghiFile << sumRow(image, i, j) + prev;
				prev = sumRow(image, i, j);
			} else {
				ghiFile << sumRow(image, i, j) + prev;
				prev = sumRow(image, i, j) + prev;
			}
			if (j != x - 1) {
				ghiFile << " "; // Neu khong phai so cuoi cung thi cach ra
			}
		}
		if (i != y - 1) ghiFile << endl; // Neu dong cuoi thi khong xuong dong
	}

	docFile.close();
	ghiFile.close();

	system("pause");
	return 0;
}