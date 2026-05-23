/*  -*- coding: utf-8 -*-
 *
 * 3107.cc: Spot The Difference
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

const int MAX_H = 2000;
const int MAX_W = 2000;

/* typedef */

/* global variables */

char a[MAX_H][MAX_W + 4], b[MAX_H][MAX_W + 4];

/* subroutines */

/* main */

int main() {
  int h, w;
  scanf("%d%d", &h, &w);

  for (int y = 0; y < h; y++) scanf("%s", a[y]);
  for (int y = 0; y < h; y++) scanf("%s", b[y]);

  int c = 0;
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if (a[y][x] != b[y][x]) c++;

  printf("%d\n", c);
  return 0;
}

