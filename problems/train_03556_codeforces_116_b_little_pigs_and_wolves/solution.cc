#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main() {
  long long a, b, county = 0;
  cin >> a >> b;
  string k;
  string v[a];
  for (long long i = 0; i < a; i++) {
    cin >> v[i];
  }
  for (long long i = 0; i < a; i++) {
    for (long long j = 0; j < b; j++)
      if (v[i][j] == 'W') {
        if (i > 0 && v[i - 1][j] == 'P') {
          v[i][j] = '.';
          county++;
          v[i - 1][j] = '.';
          continue;
        }
        if (j > 0 && v[i][j - 1] == 'P') {
          county++;
          v[i][j - 1] = '.';
          continue;
        }
        if (j < b - 1 && v[i][j + 1] == 'P') {
          v[i][j + 1] = '.';
          county++;
          continue;
        }
        if (i < a - 1 && v[i + 1][j] == 'P') {
          v[i + 1][j] = '.';
          county++;
          continue;
        }
      }
  }
  cout << county;
  return 0;
}
