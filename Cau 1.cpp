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

int main() {
    int nN;    
    cin >> nN;
    
    vector<int> arr(nN);
    nhapMang(arr);
    
	int max = 0;
	for (int i = 0; i < nN; i++) {
		bool check = arr[i] % 2 != 0 && arr[i] > max;
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