#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  map<char, long long int> sum, first;
  for (int i = 1; i <= n; i++) {
    string second;
    cin >> second;
    long long int mf = 1;
    for (int j = second.size() - 1; j >= 0; j--) {
      if (j == 0) {
        first[second[0]] = 1;
        sum[second[0]] += mf;
      } else {
        sum[second[j]] += mf;
        mf *= 10;
      }
    }
  }
  vector<pair<long long int, char> > vec;
  for (char c = 'a'; c <= 'z'; c++) {
    if (sum[c]) {
      vec.push_back(make_pair(sum[c], c));
    }
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  long long int ans = 0;
  int f0 = 0;
  int cur = 1;
  for (auto x : vec) {
    char c = x.second;
    if (!first[c] && !f0) {
      ans += 0;
      f0 = 1;
    } else {
      ans += cur * x.first;
      cur++;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  T = 1;
  while (T--) {
    solve();
  }
}
