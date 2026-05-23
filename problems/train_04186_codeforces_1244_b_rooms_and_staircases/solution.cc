#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e2 + 4;
const long long INF = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    string str;
    long long n;
    cin >> n >> str;
    long long l = INF, r = -1;
    for (long long j = 0; j < str.length(); j++) {
      if (str[j] == '1') {
        l = min(l, j + 1);
        r = max(r, j + 1);
      }
    }
    if (l == INF && r == -1)
      cout << n << endl;
    else
      cout << max({l * 2, (n - r + 1) * 2, r * 2, (n - l + 1) * 2}) << endl;
  }
  return 0;
}
