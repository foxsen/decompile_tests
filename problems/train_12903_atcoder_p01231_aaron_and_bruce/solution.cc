#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_M = 50;
const int MAX_K = 300;
const int INF = 1 << 30;

/* typedef */

typedef vector<int> vi;

/* global variables */

int n, m;
vi nbrs[MAX_M];
int cache[MAX_M][MAX_M][MAX_K];

/* subroutines */

int rec(int k, int a, int b) {
  if (k >= MAX_K) return INF;
  if (a == b) return (cache[a][b][k] = k);
  if (cache[a][b][k] >= 0) return cache[a][b][k];

  int ans;
  
  // Aaron
  if (! (k & 1)) {
    ans = 0;
    vi& nbra = nbrs[a];
    for (vi::iterator vit = nbra.begin(); vit != nbra.end(); vit++) {
      int c = rec(k + 1, *vit, b);
      if (ans < c) ans = c;
    }
  }
  // Bruce
  else {
    ans = INF;
    vi& nbrb = nbrs[b];
    for (vi::iterator vit = nbrb.begin(); vit != nbrb.end(); vit++) {
      int c = rec(k + 1, a, *vit);
      if (ans > c) ans = c;
    }
  }

  return (cache[a][b][k] = ans);
}

/* main */

int main() {
  cin >> n;
  while (n--) {
    cin >> m;

    for (int i = 0; i < m; i++) {
      nbrs[i].clear();
      for (int j = 0; j < m; j++) {
	int on;
	cin >> on;
	if (on || i == j) nbrs[i].push_back(j);
      }
    }

    int ai, bi;
    cin >> ai >> bi;
    
    memset(cache, -1, sizeof(cache));

    int ans = rec(0, ai, bi);
    if (ans >= INF) cout << "infinity" << endl;
    else cout << (ans / 2) << endl;
  }

  return 0;
}