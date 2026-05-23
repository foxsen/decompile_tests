#include <iostream>

using namespace std;

int main() {
	string str,p;
	cin >> str >> p;
	int size1 = str.size();
	int size2 = p.size();
	
	for (int i=0; i<size1; i++) {
		int j;
		for (j=i; j<i+size2; j++) {
			if (str[j] != p[j-i]) {
				break;
			}
		}
		if (j == i+size2) {
			cout << i << endl;
		}
	}
	return 0;
}
