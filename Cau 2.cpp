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
    
	int min = INT_MAX;
	int firstInt = 0;
	int secondInt = 0;
	for (int i = 0; i < nN - 1; i++) {
		for (int j = i + 1; j < nN; j++) {
			int dis = abs(arr[i] - arr[j]);
			if (dis < min) {
				firstInt = arr[i];
				secondInt = arr[j];
				min = dis;
			}
		}
	}

	cout << firstInt << " " << secondInt << endl;

    system("pause");
    return 0;
}