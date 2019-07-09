// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void nhapMang(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
}

bool checkOdd(int nN) {
	while (nN) {
		int nX = nN % 10;
		if (nX % 2 == 0) {
			return false;
		}
		nN /= 10;
	}
	return true;
}

int main() {
    int nN;    
    cin >> nN;
    
    vector<int> arr(nN);
    nhapMang(arr);
    
	int max = 0;
	int position = 0;
	
	// Tim phan tu le dau tien
	for (int i = 0; i < nN; i++) {
		if (checkOdd(arr[i])) {
			max = arr[i];
			position = i;
		}
	}

	// Tim max
	for (int i = position; i < nN; i++) {
		bool check = checkOdd(arr[i]) && arr[i] > max;
		if (check) max = arr[i];
	}

	if (max) {
		cout << max << endl;
	} else {
		cout << "Mang khong co so le" << endl;
	}

    system("pause");
    return 0;
}