#include <bits/stdc++.h>
using namespace std;typedef long long ll;const int N=5000005;const int M=1000000007;int seed, base, t[N], a[N], b[N];ll s[2];
int rnd() {int ret = seed; seed = (1ll * seed * base + 233) % 1000000007;return ret;}
int main() {int n, m; scanf("%d%d", &n, &m);for (int i=1, p0=1, p, k; i<=m; i++) {scanf("%d%d%d%d", &p, &k, &seed, &base);for (;p0<=p; p0++) {t[p0]=rnd()%2;a[p0]=rnd()%k+1;}}
	for (int i=1; i<=n; i++) s[t[i]]+=a[i];int st = -1;
	if (s[t[1]]>s[t[1]^1]) {a[1]--;b[1]++;for (int i=1; i<=n; i++) if (t[i]!=t[1]) { st=i; break; }} else st=1;
	if (st>-1) {long long cnt=0;for (int i=st,j=1; s[t[st]]; j++, i=i%n+1) {
			if (t[i]==t[st]) { cnt+=a[i]; b[i]+=a[i]; a[i]=0; } else {int z=min((ll)a[i], cnt);a[i]-=z;b[i]+=z;s[t[st]]-=z;cnt-=z;}	}}	
	ll A=1; for (int i=1; i<=n; i++) A=((b[i]^(1ll*i*i))+1)%M*1ll*A%M; printf("%lld\n", A);return 0;}