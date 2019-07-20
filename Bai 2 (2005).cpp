#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream docFile;
	ofstream ghiFile;

	// Doc file
	docFile.open("PIPE.INP");
	
	int x, y, z;
	docFile >> x;
	docFile >> y;
	docFile >> z;
	
	vector<vector<int>> diaDao1(y, vector<int>(x, 5));

	for (int i = 0; i < z; i++) {
		int xZ, yZ, zZ;
		docFile >> xZ;
		docFile >> yZ;
		docFile >> zZ;
		diaDao1[yZ][xZ] = zZ;
	}
	docFile.close();

	// Tao ra mang cho viec qua phai
	vector<vector<int>> diaDao2 = diaDao1;

	// Tinh duong di xuong
	// Duong nao da di qua se duoc danh so 6
	int i = 0;
	int j = 0;
	string dir = "down";
	int count1 = 0;
	while (true) {
		if (i < 0 || i >= y || j < 0 || j >= x) {
			break;
		}
		if (diaDao1[i][j] == 5) {
			diaDao1[i][j] = 6;
			if (dir == "up") {
				i--;
			} else if (dir == "right") {
				j++;
			} else if (dir == "down") {
				i++;
			} else if (dir == "left") {
				j--;
			}
		} else if (diaDao1[i][j] == 1) {
			diaDao1[i][j] = 6;
			if (dir == "up") {
				j++;
				dir = "right";
			} else if (dir == "right") {
				i++;
				dir = "down";
			} else if (dir == "down") {
				j--;
				dir = "left";
			} else if (dir == "left") {
				i--;
				dir = "up";
			}
		} else if (diaDao1[i][j] == 0) {
			diaDao1[i][j] = 6;
			if (dir == "up") {
				j--;
				dir = "left";
			} else if (dir == "right") {
				i--;
				dir = "up";
			} else if (dir == "down") {
				j++;
				dir = "right";
			} else if (dir == "left") {
				i++;
				dir = "down";
			}
		} else {
			break;
		}
		count1++;
	}

	// Tinh duong qua phai
	// Duong nao da di qua se duoc danh so 6
	i = 0;
	j = 0;
	dir = "right";
	int count2 = 0;
	while (true) {
		if (i < 0 || i >= y || j < 0 || j >= x) {
			break;
		}
		if (diaDao2[i][j] == 5) {
			diaDao2[i][j] = 6;
			if (dir == "up") {
				i--;
			} else if (dir == "right") {
				j++;
			} else if (dir == "down") {
				i++;
			} else if (dir == "left") {
				j--;
			}
		} else if (diaDao2[i][j] == 1) {
			diaDao2[i][j] = 6;
			if (dir == "up") {
				j++;
				dir = "right";
			} else if (dir == "right") {
				i++;
				dir = "down";
			} else if (dir == "down") {
				j--;
				dir = "left";
			} else if (dir == "left") {
				i--;
				dir = "up";
			}
		} else if (diaDao2[i][j] == 0) {
			diaDao2[i][j] = 6;
			if (dir == "up") {
				j--;
				dir = "left";
			} else if (dir == "right") {
				i--;
				dir = "up";
			} else if (dir == "down") {
				j++;
				dir = "right";
			} else if (dir == "left") {
				i++;
				dir = "down";
			}
		} else {
			break;
		}
		count2++;
	}

	// Ghi file
	ghiFile.open("PIPE.OUT");

	count1 > count2 ? ghiFile << count2 << " " << count1 : ghiFile << count1 << " " << count2; 
	ghiFile.close();

	system("pause");
	return 0;
}