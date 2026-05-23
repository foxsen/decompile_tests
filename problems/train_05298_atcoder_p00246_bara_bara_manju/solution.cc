#include <cstdio>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

typedef unsigned long long ull;

map<ull,int> memo;

int dfs2(ull, int, int);

int dfs1(ull s){
	if(s <= 0xff){
		return s / 10;
	}
	if(memo.count(s)){
		return memo[s];
	}
	int k;
	for(k = 8; !(s >> ((k - 1) * 8)); --k);

	int a = dfs2(s - (1ull << ((k - 1) * 8)), 10 - k, k);
	int b = dfs1(s & ((1ull << ((k - 1) * 8)) - 1));
	int res = max(a, b);

	memo[s] = res;
	return res;
}

int dfs2(ull s, int t, int u){
	if(t != 9 && s >> ((t - 1) * 8) & 0xff){
		return dfs1(s - (1ull << ((t - 1) * 8))) + 1;
	}
	if(t == 1){
		return 0;
	}
	if(t == 2){
		if((s & 0xff) >= 2){
			return dfs1(s - 2) + 1;
		}
		return 0;
	}
	if(t == 3){
		if(s & 0xff && s & 0xff00){
			return dfs1(s - 0x101) + 1;
		}
		if((s & 0xff) >= 3){
			return dfs1(s - 3) + 1;
		}
		return 0;
	}
	
	int res = 0;
	for(u = min(t, u); u >= 1; --u){
		if(s >> ((u - 1) * 8) & 0xff){
			int a = dfs2(s - (1ull << ((u - 1) * 8)), t - u, u);
			res = max(res, a);
		}
	}
	return res;
}

int main(){
	int n, x;
	while(scanf("%d", &n), n){
		int cnt[10] = {};
		for(int i = 0; i < n; ++i){
			scanf("%d", &x);
			++cnt[x];
		}
		
		int ans = 0;
		x = min(cnt[1], cnt[9]);
		cnt[1] -= x;
		cnt[9] -= x;
		ans = x;
		
		ull s = 0;
		for(int i = 1; i <= 8; ++i){
			s |= (ull)cnt[i] << ((i - 1) * 8);
		}
		
		memo.clear();
		ans += dfs1(s);
		printf("%d\n", ans);
	}
}