#include <bits/stdc++.h>
using namespace std;
int cnt[64] = {0};
map<char, int> M;
int main() {
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      cnt[i & j]++;
    }
  }
  for (int i = 0; i < 10; i++) {
    M[i + '0'] = i;
  }
  for (int i = 10; i <= 35; i++) {
    M[i + 'A' - 10] = i;
  }
  for (int i = 36; i <= 61; i++) {
    M[i + 'a' - 36] = i;
  }
  M['-'] = 62;
  M['_'] = 63;
  string X;
  cin >> X;
  long long int ways = 0;
  for (int i = 0; i < X.length(); i++) {
    if (i == 0)
      ways = cnt[M[X[i]]];
    else {
      ways = ways * cnt[M[X[i]]];
      ways = ways % 1000000007;
    }
  }
  cout << (ways % 1000000007);
  return 0;
}
