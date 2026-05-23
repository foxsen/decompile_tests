#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<vector>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, int> pli;
 
const int MX = 1<<19;
 
ll ans[MX];
vector<pii> T[MX];
 
int cnt[MX];
ll A[MX];
int N;
 
__int128 total;
int rm;
 
int dfs(int x, int p = -1)
{
	cnt[x] = 1;
	for(pii e : T[x]){
		if( e.second == p ) continue;
		int v = dfs(e.second, x);
		if( v*2 == N ){
			rm = e.first;
		}
		else{
			ans[e.first] = (A[x] - A[e.second]) / (2*v-N);
			total -= (__int128) ans[e.first] * (N-v) * v;
		}
		cnt[x] += v;
	}
	return cnt[x];
}
 
int main()
{
	scanf("%d", &N);
	for(int i = 1; i < N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		T[a].emplace_back(i, b);
		T[b].emplace_back(i, a);
	}
	for(int i = 1; i <= N; i++) scanf("%lld", A+i), total += A[i];
	total /= 2;
	dfs(1);
	total /= (N/2);
	total /= (N/2);
	ans[rm] = total;
	for(int i = 1; i < N; i++) printf("%lld\n", ans[i]);
}