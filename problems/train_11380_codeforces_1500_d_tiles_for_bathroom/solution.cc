/*Lucky_Glass*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int rin(int &r) {
	int b = 1, c = getchar(); r = 0;
	while( c < '0' || '9' < c ) b = c == '-' ? -1 : b, c = getchar();
	while( '0' <= c && c <= '9' ) r = (r * 10) + (c ^ '0'), c = getchar();
	return r *= b;
}
const int N = 1510, Q = 13;
typedef pair<int, int> pii;
#define con(type) const type &

int n, vq, na, nb, tmp_i;
bool vis[N * N];
int num[N][N], aid[N], ans[N];

struct Data {
	pii ary[Q]; int siz;
	inline pii operator [] (con(int) i) const {return ary[i];}
	inline pii& operator [] (con(int) i) {return ary[i];}
	friend Data operator + (con(Data) a, con(Data) b) {
		Data c; c.siz = 0;
		int p = 0, q = 0, &w = c.siz;
		while( p < a.siz && q < b.siz && w <= vq ) {
			if( a[p].second < b[q].second ) {
				if( !vis[a[p].first] ) {
					vis[a[p].first] = true;
					c[w++] = a[p];
				} p++;
			}
			else {
				if( !vis[b[q].first] ) {
					vis[b[q].first] = true;
					c[w++] = b[q];
				} q++;
			}
		}
		while( p < a.siz && w <= vq ) {
			if( !vis[a[p].first] ) {
				vis[a[p].first] = true;
				c[w++] = a[p];
			} p++;
		}
		while( q < b.siz && w <= vq ) {
			if( !vis[b[q].first] ) {
				vis[b[q].first] = true;
				c[w++] = b[q];
			} q++;
		}
		for(int i = 0; i < w; i++) vis[c[i].first] = false;
		return c;
	}
} col[N][N], ta[N], tb[N];

void inaToggle() {
	if( nb ) return;
	while( na ) {
		tb[nb + 1] = tb[nb] + col[tmp_i][aid[na]];
		na--, nb++;
	}
}
void inaPush(con(int) j) {
	ta[na + 1] = ta[na] + col[tmp_i][j], aid[na + 1] = j;
	na++;
	inaToggle();
}
void inaPop() {
	nb--;
	inaToggle();
}
int main() {
//	freopen("input.in", "r", stdin);
	rin(n), rin(vq);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			rin(num[i][j]);
	for(int i = n; i; i--)
		for(int j = 1; j <= n; j++) {
			col[i][j][0] = make_pair(num[i][j], i);
			col[i][j].siz = 1;
			col[i][j] = col[i][j] + col[i + 1][j];
		}
	for(int i = 1; i <= n; i++) {
		na = nb = 0, tmp_i = i;
		for(int j = 1, k = 0; j <= n; j++) {
			while( k < n ) {
				Data it = ta[na] + tb[nb] + col[i][k + 1];
				int dep = (it.siz == vq + 1 ? it[vq].second - 1 : n) - i + 1;
				if( dep < k + 1 - j + 1 ) break;
				inaPush(++k);
			}
			Data it = ta[na] + tb[nb];
			int dep = (it.siz == vq + 1 ? it[vq].second - 1 : n) - i + 1;
			ans[min(dep, k - j + 1)]++;
			inaPop();
		}
	}
	for(int i = n; i; i--) ans[i] += ans[i + 1];
	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}
