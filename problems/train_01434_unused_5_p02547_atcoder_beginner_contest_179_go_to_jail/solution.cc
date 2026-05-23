#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int num = 0;
	bool ans = false;
	for (int i = 0; i < N; i++) {
		int d1, d2;
		cin >> d1 >> d2;
		if (d1 == d2) num++;
		else num = 0;
		if (num == 3) ans = true;
	}
	cout << (ans ? "Yes" : "No") << endl;
}
