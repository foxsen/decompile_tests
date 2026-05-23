#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int cnt[1000000];
int main() {
	int n; scanf("%d", &n);
	rep(i, n) {
		int a, b; scanf("%d%d", &a, &b);
		cnt[a + b]++;
	}
	rep(i, 1000000 - 1) {
		cnt[i + 1] += cnt[i] / 2;
		if (cnt[i] & 1)printf("%d 0\n", i);
	}
}