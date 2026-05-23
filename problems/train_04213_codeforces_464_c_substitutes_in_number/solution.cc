#include <bits/stdc++.h>
using namespace std;
char t;
int n, mod = 1e9 + 7;
pair<int, int> val[10];
string s;
pair<char, string> que[100005];
pair<int, int> calc(string x) {
  int v = 0, p = 1;
  for (int i = 0; i < x.size(); ++i) {
    int y = x[i] - '0';
    v = (1LL * val[y].second * v + val[y].first) % mod;
    p = (1LL * p * val[y].second) % mod;
  }
  return make_pair(v, p);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> n;
  for (int i = 0; i < n; ++i) {
    cin >> que[i].first >> que[i].second;
    que[i].second = que[i].second.substr(2, que[i].second.size() - 2);
  }
  for (int i = 0; i < 10; ++i) {
    val[i].first = i;
    val[i].second = 10;
  }
  for (int i = n - 1; i >= 0; --i)
    val[que[i].first - '0'] = calc(que[i].second);
  cout << calc(s).first << '\n';
}
