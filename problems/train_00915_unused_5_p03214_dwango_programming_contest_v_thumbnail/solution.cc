#include <bits/stdc++.h>
using namespace std;

int N, A[1 << 18], S;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i]; S += A[i]; A[i] *= N;
	}
	int maxn = (1 << 30), r = 0;
	for (int i = 1; i <= N; i++) {
		if (maxn > abs(S - A[i])) { maxn = abs(S - A[i]); r = i; }
	}
	cout << r - 1 << endl;
	return 0;
}
