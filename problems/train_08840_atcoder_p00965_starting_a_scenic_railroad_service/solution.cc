/*  -*- coding: utf-8 -*-
 *
 * 1386.cc: Starting a Scenic Railroad Service
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
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

const int MAX_N = 200000;
const int MAX_M = 100000;
const int INF = 1 << 30;

/* typedef */

/* global variables */

int as[MAX_N], bs[MAX_N];
int csums[MAX_M + 1], asums[MAX_M + 1], bsums[MAX_M + 1];

/* subroutines */

inline void setmax(int &a, int b) { if (a < b) a = b; }

/* main */

int main() {
  int n;
  scanf("%d", &n);

  int m = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", as + i, bs + i);
    csums[as[i]]++, csums[bs[i]]--;
    asums[as[i]]++;
    bsums[bs[i]]++;
    setmax(m, bs[i]);
  }

  for (int i = 0; i < m; i++) {
    csums[i + 1] += csums[i];
    asums[i + 1] += asums[i];
    bsums[i + 1] += bsums[i];
  }

  int maxp1 = 0;
  for (int i = 0; i < n; i++) setmax(maxp1, asums[bs[i] - 1] - bsums[as[i]]);

  int maxp2 = 0;
  for (int i = 1; i < m; i++) setmax(maxp2, csums[i]);

  printf("%d %d\n", maxp1, maxp2);
  //for (int i = 0; i <= m; i++) printf("%d ", csums[i]); putchar('\n');
  //for (int i = 0; i <= m; i++) printf("%d ", asums[i]); putchar('\n');
  //for (int i = 0; i <= m; i++) printf("%d ", bsums[i]); putchar('\n');
  return 0;
}

