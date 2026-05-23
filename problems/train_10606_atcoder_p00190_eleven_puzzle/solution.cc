#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
using namespace std;
 
#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)
#define PB(a) push_back(a)
#define MP(i,s) make_pair(i,s)
 
typedef long long ll;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

const int field[5][5] = {
	{0, 0, 1, 0, 0}, 
	{0, 1, 1, 1, 0},
	{1, 1, 1, 1, 1},
	{0, 1, 1, 1, 0},
	{0, 0, 1, 0, 0}, 
};

const int ans[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 0},
	{4, 5, 6, 7, 8},
	{0, 9, 10, 11, 0},
	{0, 0, 0, 0, 0}
};

const int px[13] = {2, 1, 2, 3, 0, 1, 2, 3, 4, 1, 2, 3, 2};
const int py[13] = {0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4};

int P[5][5];
map<ll,int> used;
map<ll,int> H;

ll hash_val() {
	ll h = 0;
	rep(i,13) {
		h *= 13;
		h += P[py[i]][px[i]];
	}
	return h;
}

void make_ans(int m, int d) {
	ll h = hash_val();
	map<ll,int>::iterator it = H.find(h);
	
	if(it == H.end()) {
		H.insert(MP(h,m));
	} else if((*it).second > m) {
		(*it).second = m;
	} else {
		return;
	}

	if(m == d) return;


	rep(i,13) {
		int x = px[i];
		int y = py[i];
		if(P[y][x] == 0) {
			rep(k,4) {
				int xx = x + dx[k];
				int yy = y + dy[k];
				if(xx>=0 && yy>=0 && xx<5 && yy<5 && field[yy][xx] == 1 && P[yy][xx] != 0) {
					swap(P[y][x], P[yy][xx]);
					make_ans(m+1, d);
					swap(P[y][x], P[yy][xx]);
				}
			}
		}
	}
}

int dfs(int m, int d) {
	map<ll,int>::iterator it;
	ll h = hash_val();

	it = H.find(h);
	if(it != H.end()) return m + (*it).second;

	if(m == d) return -1;
	
	it = used.find(h);
	if(it == used.end()) {
		used.insert(MP(h,m));
	} else if((*it).second > m) {
		(*it).second = m;
	} else {
		return -1;
	}

	rep(i,13) {
		int x = px[i];
		int y = py[i];
		if(P[y][x] == 0) {
			rep(k,4) {
				int xx = x + dx[k];
				int yy = y + dy[k];
				if(xx>=0 && yy>=0 && xx<5 && yy<5 && field[yy][xx] == 1 && P[yy][xx] != 0) {
					swap(P[y][x], P[yy][xx]);
					int a = dfs(m+1, d);
					if(a >= 0) return a;
					swap(P[y][x], P[yy][xx]);
				}
			}
		}
	}
	return -1;
}

void solve() {
	repa(d,0,10) {
		used.clear();
		int a = dfs(0, d);
		if(a >= 0) {
			printf("%d\n", a);
			return;
		}
	}
	printf("NA\n");
}

int main() {
	memcpy(P, ans, sizeof(P));
	make_ans(0, 10);
	for(;;) {
		rep(i,13) {
			scanf("%d", &P[py[i]][px[i]]);
			if(P[py[i]][px[i]] < 0) return 0;
		}
		solve();
	}
}