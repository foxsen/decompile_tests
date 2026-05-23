#include <bits/stdc++.h>
const int MAXN = 300005;
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;

int n;
lint a[MAXN], s[MAXN], d1[MAXN], d2[MAXN];
lint rep[MAXN];

struct cht{
	vector<pi> v;
	void clear(){ v.clear(); }
	bool bad(pi x, pi y, pi z){
		return (x.second - y.second) * (z.first - y.first) >= (y.second - z.second) * (y.first - x.first);
	}
	void add(int x, lint y){
		while(v.size() >= 2 && bad(v[v.size()-2], v.back(), pi(x, y))) v.pop_back();
		v.emplace_back(x, y);
	}
	lint query(int x){
		int s = 0, e = v.size() - 1;
		while(s != e){
			int m = (s+e)/2;
			if(v[m].first * x + v[m].second < v[m+1].first * x + v[m+1].second) s = m + 1;
			else e = m;
		}
		return v[s].first * x + v[s].second;
	}
}cht;

void solve(int l, int r){
	if(r - l <= 1) return;
	int m = (l + r) / 2;
	solve(l, m); 
	solve(m + 1, r);
	lint cur = -1e18;
	for(int j=m+1; j<=r; j++){
		cht.add(2 * j - 1, d2[j] - s[j-1] + 1ll * j * (j - 1));
	}
	for(int i=l; i<m; i++){
		cur = max(cur, d1[i] + s[i] + 1ll * i * i + cht.query(-i));
		rep[i+1] = max(rep[i+1], cur);
	}
	cht.clear();
	for(int i=l; i<=m; i++){
		cht.add(2 * i + 1, d1[i] + s[i] + 1ll * i * (i + 1));
	}
	cur = -1e18;
	for(int j=r; j>m+1; j--){
		cur = max(cur, d2[j] - s[j-1] + 1ll * j * j + cht.query(-j));
		rep[j-1] = max(rep[j-1], cur);
	}
	cht.clear();
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
		s[i] = s[i-1] + 2 * a[i];
	}
	for(int i=1; i<=n; i++){
		int j = i - 1;
		cht.add(2 * j - 1, d1[j] + s[j] + 1ll * j * (j - 1));
		d1[i] = max(d1[i-1], cht.query(-i) + 1ll * i * i - s[i]);
	}
	cht.clear();
	for(int i=n; i; i--){
		int j = i + 1;
		cht.add(-2 * j - 1, d2[j] + 1ll * j * (j + 1) - s[j-1]);
		d2[i] = max(d2[i+1], cht.query(i) + 1ll * i * i + s[i-1]);
	}
	cht.clear();
	fill(rep, rep + n + 1, -1e18);
	solve(0, n + 1);
	int q; scanf("%d",&q);
	while(q--){
		int x, v; scanf("%d %d",&x,&v);
		lint dap = max(rep[x] - 2 * (v - a[x]) , d1[x-1] + d2[x+1]);
		printf("%lld\n", dap / 2);
	}
}
