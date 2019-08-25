#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool checkXauNgoacDung(string s) {
	vector<char> stack;
	int n = s.size();
	if (s[0] == '}' || s[0] == ')' || s[0] == ']') return 0;
	stack.push_back(s[0]);
	for (int i = 1; i < n; i++) {
		if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
			stack.push_back(s[i]);
		}
		else {
			if (stack.empty()) return 0;
			char back = stack.back();
			stack.pop_back();
			if (s[i] == '}' && back != '{') {
				return 0;
			}
			else if (s[i] == ')' && back != '(') {
				return 0;
			}
			else if (s[i] == ']' && back != '[') {
				return 0;
			}
		}
	}
	return stack.empty();
}

int main() {
	ifstream docFile;
	docFile.open("BRACKETS.INP");
	string s;
	getline(docFile, s);

	int n = s.size();
	ofstream ghiFile;
	ghiFile.open("BRACKETS.OUT");
	for (int i = 0; i < n; i++) {
		string str = s.substr(i) + s.substr(0, i);
		if (checkXauNgoacDung(str)) {
			ghiFile << i + 1;
			return 0;
		}
	}

	ghiFile << -1;
	return 0;
}