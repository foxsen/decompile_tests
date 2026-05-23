#include "bits/stdc++.h"
using namespace std;

int main() {
	int R0, W0, C, R;
	while (cin >> R0 >> W0 >> C >> R) {
		if (R0 == 0 && W0 == 0 && C == 0 && R == 0) return 0;
		int LOSS = W0 * C - R0;
		if (LOSS <= 0) cout << 0 << endl;
		else if (LOSS % R == 0) cout << LOSS / R << endl;
		else cout << LOSS / R + 1 << endl;
	}
}
