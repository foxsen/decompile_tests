#include <bits/stdc++.h> 

using namespace std;

#define ll long long

const int N = (int)1e4 + 7;

int a[N], b[N];

int main() {    
	int n; scanf("%d", &n);
	ll sum = 0, sum1 = 0, c = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		sum1 += b[i];
		if (b[i] > a[i]) {
			c += (b[i] - a[i] + 1) / 2;
		}
	}
	if (c <= sum1 - sum) puts("Yes");
	else puts("No");
}