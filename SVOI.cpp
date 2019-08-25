#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

struct SVON {
	int a, b, c, d;
};

int main() {
	ifstream docFile;

	docFile.open("SVOI.INP");
	int n, T, P;
	docFile >> n >> T >> P;

	vector<SVON> arr(n);
	for (int i = 0; i < n; i++) {
		docFile >> arr[i].a;
		docFile >> arr[i].b;
		docFile >> arr[i].c;
		docFile >> arr[i].d;
	}

	int count = 0;
	int i = 0;
	while (i != n) {
		if (arr[i].a <= T && arr[i].b <= P) {
			T += arr[i].c;
			P += arr[i].d;
			arr[i] = arr[n - 1];
			arr.pop_back();
			count++;
			i = 0;
			n--;
		}
		else {
			i++;
		}
	}

	ofstream ghiFile;
	ghiFile.open("SVOI.OUT");
	ghiFile << count;

	return 0;
}