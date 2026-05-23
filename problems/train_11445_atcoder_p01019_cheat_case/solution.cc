#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

const char *chars[13][5] = {
	{
		"###",
		"#.#",
		"#.#",
		"#.#",
		"###"
	},
	{
		"..#",
		"..#",
		"..#",
		"..#",
		"..#"
	},
	{
		"###",
		"..#",
		"###",
		"#..",
		"###"
	},
	{
		"###",
		"..#",
		"###",
		"..#",
		"###"
	},
	{
		"#.#",
		"#.#",
		"###",
		"..#",
		"..#"
	},
	{
		"###",
		"#..",
		"###",
		"..#",
		"###"
	},
	{
		"###",
		"#..",
		"###",
		"#.#",
		"###"
	},
	{
		"###",
		"..#",
		"..#",
		"..#",
		"..#"
	},
	{
		"###",
		"#.#",
		"###",
		"#.#",
		"###"
	},
	{
		"###",
		"#.#",
		"###",
		"..#",
		"###"
	},
	{
		"...",
		".#.",
		"###",
		".#.",
		"..."
	},
	{
		"...",
		"...",
		"###",
		"...",
		"..."
	},
	{
		"...",
		"...",
		".#.",
		"...",
		"..."
	},
};

bool b[201][201];
bool vis[201][201];
vpii shapes[13];
vpii shape;

void dfs(int i, int j) {
	if(vis[i][j]) return;
	shape.pb(mp(i,j));
	vis[i][j] = true;
	static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
	rep(d, 4) {
		int yy = i + dy[d], xx = j + dx[d];
		if(yy<0||yy>=201||xx<0||xx>=201) continue;
		if(!b[yy][xx]) continue;
		dfs(yy, xx);
	}
}

char s[40001];

typedef const char *Pos;

inline void expect(char c, Pos &p) {
	assert(*p == c);
	++ p;
}

int equation(Pos &p);
int factor(Pos &p);
int term(Pos &p);

int equation(Pos &p) {
	int r = factor(p);
	while(*p == '+' || *p == '-') {
		bool minus = *p == '-';
		++ p;
		int u = factor(p);
		if(!minus) r += u; else r -= u;
	}
	return r;
}

int factor(Pos &p) {
	int r = term(p);
	while(*p == '*') {
		++ p;
		int u = term(p);
		r *= u;
	}
	return r;
}

int term(Pos &p) {
	int r = 0;
	while(isdigit(*p)) {
		r = r * 10 + (*p - '0');
		++ p;
	}
	return r;
}


int main() {
	rep(c, 13) {
		mset(b, 0);
		rep(i, 5) rep(j, 3) b[i][j] = chars[c][i][j] == '#';
		mset(vis, 0);
		rep(i, 5) rep(j, 3) if(b[i][j]) {
			shape.clear();
			dfs(i, j);
			each(k, shape) k->first -= i, k->second -= j;
			sort(all(shape));
			shapes[c] = shape;
//			cerr << c << ": ";
//		each(k, shape) cerr << k->first << ", " << k->second << "; "; cerr << endl;
			goto outer;
		}
		outer:;
	}
	mset(b, 0);
	int N;
	scanf("%d", &N);
	rep(i, N) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		rer(y, y1, y2) rer(x, x1, x2)
			b[y][x] = true;
	}
	mset(vis, 0);
	vector<pair<int,int> > cs;
	rep(i, 201) rep(j, 201) if(!vis[i][j] && b[i][j]) {
		shape.clear();
		dfs(i, j);
		int minx = INF;
		each(k, shape) amin(minx, k->second);
		each(k, shape) k->first -= i, k->second -= j;
		sort(all(shape));
		int cc = -1;
//		each(k, shape) cerr << k->first << ", " << k->second << "; "; cerr << endl;
		rep(c, 13) if(shapes[c] == shape) cc = c;
		if(cc == -1) cerr << "Error: " << i << ", " << j << endl;
		cs.pb(mp(minx, cc));
	}
	sort(all(cs));
	each(i, cs)
		s[i - cs.begin()] = "0123456789+-*"[i->second];
	s[cs.size()] = 0;
	Pos p = s;
	int ans = equation(p);
	printf("%d\n", ans);
	return 0;
}
