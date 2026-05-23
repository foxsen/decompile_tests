#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

class Solver{};

signed main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)break;

		int sum = 0;
		for (int i = 1; i * i <= n; i++) {
			if (n % i != 0)continue;

			int other = n / i;
			if (i == n)continue;
			sum += i;
			if (other == i || other == n)continue;
			sum += other;
		}

		if (sum < n) {
			cout << "deficient number" << endl;
		}
		else if (sum == n) {
			cout << "perfect number" << endl;
		}
		else {
			cout << "abundant number" << endl;
		}
	}
}
