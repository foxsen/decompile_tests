#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define int long long

using namespace std;

class Solver {
};

signed main() {
	int q;
	cin >> q;

	vector<string> qs(q);
	for (int i = 0; i < q; i++) {
		cin >> qs[i];
	}

	vector<int> smalls({ 5000000,2500000,1250000,625000,312500,156250,78125 });
	for (int i = 0; i < q; i++) {
		bool minus = false;
		int checker = 1 << 24;
		int m = 0;
		int small = 0;
		int smallCnt = 0;
		for (int j = 0; j < qs[i].size(); j++) {
			int val;
			if ('a' <= qs[i][j] && qs[i][j] <= 'f') {
				val = 10 + (int)(qs[i][j] - 'a');
			}
			else val = qs[i][j] - '0';

			int div = 1 << 3;
			for (int k = 0; k < 4; k++) {
				if ((val & div) > 0) {
					if (j == 0 && k == 0) {
						minus = true;
					}
					else {
						if (checker > 0) {
							m += checker;
						}
						else {
							small += smalls[smallCnt];
						}
					}
				}
				if (checker == 0)smallCnt++;
				checker /= 2;
				div = div / 2;
			}
		}
		if (minus)cout << '-';
		string small_str = "";
		for (int j = 0; j < 7; j++) {
			int num = small % 10;
			if (num > 0 || small_str.size() > 0)small_str += (char)(num + '0');
			small /= 10;
		}
		if (small_str.size() == 0)small_str += '0';
		reverse(small_str.begin(), small_str.end());
		cout << m << '.' << small_str << endl;
	}
}
