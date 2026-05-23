#include <iostream>
using namespace std;

int main() {
	int c1, c2, c3;

	while (cin >> c1) {
		cin >> c2 >> c3;

		int hand = c1 + c2;

		int count = 0;
		for (int i = 1; i <= 10; ++i) {
			if (i == c1 || i == c2 || i == c3) continue;
			if (hand + i <= 20) ++count;
		}

		//cout << 1.0f*count / 7 << endl;
		if (1.0f*count / 7 >= 0.50f) cout << "YES" << endl;
		else cout << "NO" << endl;
	
	}
	return 0;
}