#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int countZero(string s) {
	return count(s.begin(), s.end(), '0');
}

int countOne(string s) {
	return count(s.begin(), s.end(), '1');
}

int main() {
	ifstream docFile;
	ofstream ghiFile;

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

	for (int i = 0; i < iN; i++) {
		cout << sieuMa[i] << " Zero: " << countZero(sieuMa[i]) << " One: " << countOne(sieuMa[i]) << endl;
	}

	int count = 0;
	int min = iN;
	for (int i = 0; i < iN - 1; i++) {
		for (int j = i + 1; j < iN; j++) {
			if (sieuMa[i].size() > sieuMa[j].size()) {
				if  (countZero(sieuMa[j]) <= countZero(sieuMa[i]) && countOne(sieuMa[j]) <= countOne(sieuMa[i])) {
					count++;
					if (min > i) {
						min = i;
					}
				} else {
					break;
				}
				// countZero(sieuMa[j]) <= countZero(sieuMa[i]) && countOne(sieuMa[j]) <= countOne(sieuMa[i])
			} else {
				if (countZero(sieuMa[i]) <= countZero(sieuMa[j]) && countOne(sieuMa[i]) <= countOne(sieuMa[j])) {
					count++;
					if (min > j) {
						min = j;
					}
				} else {
					break;
				}
			}
		}
	}

	ghiFile.open("HCODE.OUT");
	count == iN ? ghiFile << 1 : ghiFile << 0 << endl << min + 1;

	system("pause");
	return 0;
}
