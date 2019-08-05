#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Check chuoi s1 co phai con s2 hay khong
bool checkChuoiCon(string s1, string s2) {
	int i = 0; // index cua s1
	int j = 0; // index cua s2
	int count = 0; // kiem tra da duyet qua het i

	while (i < s1.size() && j < s2.size()) {
		if (s1[i] == s2[j]) {
			i++;
			j++;
			count++;
		} else {
			j++;
		}
	}

	return count == s1.size(); 
}

int main() {
	ifstream docFile;

	// Doc so luong sieu ma
	docFile.open("HCODE.INP");
	int iN;
	docFile >> iN;

	// Vector chua sieu ma
	vector<string> sieuMa(iN);

	// Doc du lieu vao
	docFile.ignore(1);
	for (int i = 0; i < iN; i++) {
		getline(docFile, sieuMa[i]);
	}
	docFile.close();

	int min = iN; // Chua vi tri nho nhat
	bool check = false; // Kiem tra su ton tai cua chuoi con

	for (int i = 0; i < iN ; i++) {
		for (int j = i + 1; j < iN; j++) {
			// Kiem tra chuoi nao ngan hon
			// Roi kiem tra su ton tai cua chuoi ngan trong chuoi dai theo thu tu tang dan
			if (sieuMa[i].size() > sieuMa[j].size()) {
				if (checkChuoiCon(sieuMa[j], sieuMa[i])) {
					check = true;
					i > j ? min = j : min = i;
					goto ghiFile; // Chi can co 1 chuoi con thi thoat vong lap
				}
			} else {
				if (checkChuoiCon(sieuMa[i], sieuMa[j])) {
					check = true;
					cout << i << " " << j << endl;
					i > j ? min = j : min = i;
					goto ghiFile;
				}
			}
		}
	}

ghiFile:
	ofstream ghiFile;
	ghiFile.open("HCODE.OUT");
	check ? ghiFile << 0 << endl << min + 1 : ghiFile << 1;

	system("pause");
	return 0;
}
