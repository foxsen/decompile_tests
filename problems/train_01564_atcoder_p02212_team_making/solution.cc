#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << min(min(abs(A + B - C - D), abs(A + C - B - D)), abs(A + D - B - C)) << endl;
}
