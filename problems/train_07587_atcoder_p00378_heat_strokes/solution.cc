#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, X, minx = (1 << 30); cin >> A >> B >> X;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			int S = i * 1000 + j * 500;
			if (S >= X) minx = min(minx, A * i + B * j);
		}
	}
	cout << minx << endl;
	return 0;
}
