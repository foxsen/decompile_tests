/*
 * 2576.cc: Doctor Course Is Recommended
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

const int MAX_DN = 13;
const int MAX_X = 20;
const int MAX_Y = 10;

/* typedef */

/* global variables */

int p1s[MAX_X], p2s[MAX_Y];
int sum1s[MAX_X + 1], sum2s[MAX_Y + 1];

/* subroutines */

/* main */

int main() {
  int dn, x, y;
  cin >> dn;

  cin >> x;
  int p1n = 0;
  for (int i = 0; i < x; i++) {
    string s;
    int pi;
    cin >> s >> pi;
    if (s == "D") p1s[p1n++] = pi;
  }
  sort(p1s, p1s + p1n, greater<int>());

  cin >> y;
  int p2n = 0;
  for (int i = 0; i < y; i++) {
    string s;
    int pi;
    cin >> s >> pi;
    if (s == "DD") p2s[p2n++] = pi;
  }
  sort(p2s, p2s + p2n, greater<int>());
  //printf("p1n=%d, p2n=%d\n", p1n, p2n);

  sum1s[0] = sum2s[0] = 0;
  for (int i = 0; i < p1n; i++) sum1s[i + 1] = sum1s[i] + p1s[i];
  for (int i = 0; i < p2n; i++) sum2s[i + 1] = sum2s[i] + p2s[i];
  
  int maxsum = 0;

  for (int i = 0; i <= p2n && i * 2 <= dn; i++) {
    int j = min(p1n, dn - i * 2);
    int sum = sum1s[j] + sum2s[i];
    if (maxsum < sum) maxsum = sum;
  }

  printf("%d\n", maxsum);
  return 0;
}