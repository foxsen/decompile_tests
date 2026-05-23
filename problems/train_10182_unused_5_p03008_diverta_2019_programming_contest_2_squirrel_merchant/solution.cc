#include <iostream>
using namespace std;

const int N = 5005;

int dp1[N];
long long dp2[N * N];
int a[5];
int b[5];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 3; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 3; i++) {
		cin >> b[i];
	}
	a[0] = b[0] = 1;
	for (int i = 0; i <= 3; i++) {
		for (int j = a[i]; j < N; j++) {
			dp1[j] = max(dp1[j], dp1[j - a[i]] + b[i]);
		}
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = b[i]; j < N * N; j++) {
			dp2[j] = max(dp2[j], dp2[j - b[i]] + a[i]);
		}
	}
	cout << dp2[dp1[n]];
	return 0;
}
