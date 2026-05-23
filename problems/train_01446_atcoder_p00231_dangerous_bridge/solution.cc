#include<bits/stdc++.h>
#define rep(i,n)for(ll i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll m[100], a[100], b[100];
int main() {
	ll n;
	while (scanf("%lld", &n), n) {
		vector<ll>v;
		rep(i, n) {
			scanf("%lld%lld%lld", &m[i], &a[i], &b[i]);
			v.push_back(a[i]);
		}
		for (ll i : v) {
			ll cnt = 0;
			rep(j, n) {
				if (a[j] <= i&&i < b[j])cnt += m[j];
			}
			if (cnt > 150) {
				puts("NG");
				goto p;
			}
		}
		puts("OK");
	p:;
	}
}