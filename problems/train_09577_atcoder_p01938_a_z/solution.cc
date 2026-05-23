#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int d = 0;
	string S;
	cin >> S;
	if (S[0] == 'A') { d++; }
	for (int i = 1; i < S.size(); i++) {
		if (S[i] <= S[i - 1]) {
			d++;
		}
	}
	cout << d << endl;
	return 0;
}