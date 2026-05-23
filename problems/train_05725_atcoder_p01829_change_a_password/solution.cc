/*  -*- coding: utf-8 -*-
 *
 * 2728.cc: Change a Password
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

const int MAX_N = 10;

/* typedef */

typedef long long ll;
typedef vector<int> vi;
typedef queue<int> qi;
typedef pair<int,int> pii;
typedef set<ll> sl;

/* global variables */

int ds[MAX_N];

/* subroutines */

/* main */

int main() {
  string s;
  cin >> s;
  int n = s.size();

  ll a = atoll(s.c_str());
  //printf("%0*lld\n", n, a);

  for (int i = 0; i < MAX_N; i++) ds[i] = i;

  sl bs;
  do {
    ll b = 0;
    for (int i = 0; i < n; i++) b = b * 10 + ds[i];
    bs.insert(b);
  } while (next_permutation(ds, ds + MAX_N));
  //printf("%lu\n", bs.size());

  ll tens = 1;
  for (int i = 0; i < n; i++) tens *= 10;

  ll maxdf = -1, maxb = -1;
  for (sl::iterator sit = bs.begin(); sit != bs.end(); sit++) {
    const ll &b = *sit;
    ll ab = abs(a - b);
    ll df = min(ab, tens - ab);
    if (maxdf < df) maxdf = df, maxb = b;
  }

  printf("%0*lld\n", n, maxb);
  return 0;
}