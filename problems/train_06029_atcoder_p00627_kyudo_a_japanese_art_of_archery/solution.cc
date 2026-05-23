#include<iostream>

using namespace std;

int main() {
	int n;
	while (cin >> n,n) {
	int SUM = 0;
		for (int i = 1; i <= n / 4; i++) {
			int a;
			cin >> a;
			SUM += a;
		}
		cout << SUM << endl;
	}
	return 0;
}