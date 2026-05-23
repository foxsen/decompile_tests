#include <bits/stdc++.h>
const long double eps = 0.00000001;
const long long MOD = 1e9 + 7;
using namespace std;
int main() {
  fflush(stdin);
  cout << fixed, cout.precision(18);
  ios_base::sync_with_stdio(false);
  int i, j, n, m;
  cin >> n;
  set<string> se;
  for (i = 0; i < n; ++i) {
    string second, cur = "";
    cin >> second;
    set<char> ch;
    for (j = 0; j < (int)second.size(); ++j) ch.insert(second[j]);
    for (auto it : ch) cur += it;
    se.insert(cur);
  }
  cout << (int)se.size();
}
