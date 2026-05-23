//D
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;

int main(){
	LL N;
	int ans = 0;
	scanf("%lld", &N);
	int q = sqrt(N);
	for (int i = 2; i <= q; i++) {
		int cnt = 0;
		while (N % i == 0) N /= i, cnt++;
		if (cnt > 0) {
			int tmp = 1;
			while (cnt >= tmp) {
				ans++;
				cnt -= tmp;
				if (cnt <= tmp) break;
				tmp++;
			}
		}
	}
	if (N > 1) ans++;
	printf("%d\n", ans);
}