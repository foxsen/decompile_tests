#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	int base = 0;
	int out = 0;
	int score = 0;
	int inning;
	string evt;
	cin >> inning;
	while (inning) {
		cin >> evt;
		if (evt == "HIT") {
			base <<= 1;
			base |= 1;
			if (base > 7) {
				score++;
				base &= 7;
			}
		} else if (evt == "HOMERUN") {
			score++;
			for (int i = 0; i < 4; i++) {
				if ((base >> i) & 1) {
					score++;
				}
			}
			base = 0;
		} else {
			if (++out >= 3) {
				cout << score << endl;
				base = score = out = 0;
				inning--;
			}
		}
	}
	return 0;
}