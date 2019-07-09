// Example program
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void nhapMang(vector<long long> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
}

bool checkOdd(long long nN) {
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
    
    vector<long long> arr(nN);
    nhapMang(arr);
    
	long long max = LLONG_MIN;
	cout << "MAX: " << max << endl;
	for (int i = 0; i < nN; i++) {
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