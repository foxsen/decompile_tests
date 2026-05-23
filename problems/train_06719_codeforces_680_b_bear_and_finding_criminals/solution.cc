#include <bits/stdc++.h>
using namespace std;
unsigned short max(unsigned short a, unsigned short b) { return a > b ? a : b; }
unsigned short min(unsigned short a, unsigned short b) { return a < b ? a : b; }
int main() {
  std::ios::sync_with_stdio(false);
  unsigned short n, a, nCought, crA, upsteps, lwsteps;
  short i, j;
  cin >> n;
  cin >> a;
  unsigned short t[3 * n];
  for (i = 0; i < n; ++i) t[i] = 1;
  for (i; i < 2 * n; ++i) cin >> t[i];
  for (i; i < 3 * n; ++i) t[i] = 1;
  crA = a + n - 1;
  if (t[crA] == 1)
    nCought = 1;
  else
    nCought = 0;
  upsteps = max(n - a, a - 1);
  lwsteps = min(n - a, a - 1);
  for (i = 1; (i < (upsteps + 1)) && (i < n); ++i) {
    if (t[crA - i] && t[crA + i])
      if (i > lwsteps)
        ++nCought;
      else if (i != 0)
        nCought += 2;
  }
  cout << nCought;
  return 0;
}
