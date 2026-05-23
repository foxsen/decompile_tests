#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define mp make_pair
#define fi first
#define se second
const int MAXN = 200000;
typedef pair<int, int> pii;
typedef long long ll;
priority_queue<pii, vector<pii>, greater<pii> >que;
int lst[MAXN + 5], nxt[MAXN + 5], N, L;
void link(int x, int y) {lst[y] = x, nxt[x] = y;}
bool check(int x, int y) {return nxt[x] == y;}
ll lf[MAXN + 5], rf[MAXN + 5], f1[MAXN + 5], f2[MAXN + 5];
vector<int>v1, v2;
ll solve(int x) {
	ll ret = 0, tmp = 0;
	int lt = v2.size(), lb = lst[v2[0]], rb = nxt[v2[lt-1]];
	for(int i=0;i<lt;i++) {
		if( i - L + 1 >= 0 ) tmp += lf[v2[i-L+1]];
		ret += tmp * rf[v2[i]];
	}
	for(int i=0;i<lt;i++)
		f1[v2[i]] = lf[v2[i]], f2[v2[i]] = rf[v2[i]], lf[v2[i]] = rf[v2[i]] = 0;
	int c = lt / L;
	if( c ) {
		for(int i=L-1;i<lt;i++) {
			int t = (i + 1)/L - 1;
			rf[v2[t]] += f2[v2[i]];
		}
		for(int i=lt-L;i>=0;i--) {
			int t = c - (lt - i)/L;
			lf[v2[t]] += f1[v2[i]];
		}
		for(int i=1;i<c;i++)
			link(v2[i-1], v2[i]);
		link(lb, v2[0]), link(v2[c-1], rb);
		for(int i=0;i<c;i++)
			que.push(mp(x + 1, v2[i]));
		tmp = 0;
		for(int i=0;i<c;i++) {
			if( i - L + 1 >= 0 ) tmp += lf[v2[i-L+1]];
			ret -= tmp * rf[v2[i]];
		}
	}
	else nxt[lb] = N + 1, lst[rb] = 0;
	v2.clear();
	return ret;
}
int main() {
	scanf("%d%d", &N, &L);
	for(int i=1;i<=N;i++) {
		int x; scanf("%d", &x);
		que.push(mp(x, i)), link(i, i + 1);
		lf[i] = rf[i] = 1;
	}
	ll ans = 0; link(0, 1);
	while( !que.empty() ) {
		int x = que.top().fi; v1.clear();
		while( !que.empty() && que.top().fi == x )
			v1.push_back(que.top().se), que.pop();
		v2.clear(); v2.push_back(v1[0]);
		for(int i=1;i<v1.size();i++) {
			if( !check(v1[i-1], v1[i]) )
				ans += solve(x);
			v2.push_back(v1[i]);
		}
		ans += solve(x);
	}
	printf("%lld\n", ans + N);
}