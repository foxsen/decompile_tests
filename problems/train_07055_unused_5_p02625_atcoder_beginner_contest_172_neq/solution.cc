#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
typedef long long LL;

LL mod = 1e9 + 7, ans, fac[N], inv[N], s;
int n, m;

LL Ksm(LL a, LL b) {
	LL res = 1;
	while(b) {
		if(b&1) res = res*a%mod;
		b = b>>1;
		a = a*a%mod;
	}
	return res;
}

LL Comb(int n, int k) {
	return fac[n]*inv[n - k]%mod*inv[k]%mod;
}

int f(int i) {
	return (i%2 == 1) ? 1: -1;
} 

int main() {
	cin>>n>>m;
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= m; i++)
		fac[i] = fac[i - 1]*i%mod, inv[i] = Ksm(fac[i], mod - 2);
	ans = fac[m]*inv[m - n]%mod;
	for(int i = 1; i <= n; i++)
		s = (s + f(i)*Comb(n, i)%mod*fac[m - i]%mod*inv[m - n]%mod)%mod;
	ans = ans*(ans - s)%mod;
	cout<<(ans + mod)%mod<<endl;

	return 0;
}