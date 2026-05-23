#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int main() {
	cin >> s;
	cout << (s.find("AC") == string::npos ? "No" : "Yes") << endl;
	return 0;
}