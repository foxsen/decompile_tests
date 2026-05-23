#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1000;
const long long INFINF = 900372036851194844;
const int INF = 1e9 + 7;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
void prtf() {}
template <typename Arg1, typename... Args>
void prtf(const Arg1& arg1, const Args&... args) {
  cout << arg1;
  prtf(args...);
  exit(0);
}
bool used[2000][2000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<pair<long long, long long>> pos;
  for (long long i = 0; i < 3; i++) {
    long long x, y;
    cin >> x >> y;
    pos.push_back({x, y});
  }
  sort(pos.begin(), pos.end());
  for (long long i = min(pos[0].second, min(pos[2].second, pos[1].second));
       i <= max(pos[0].second, max(pos[2].second, pos[1].second)); i++)
    used[pos[1].first][i] = 1;
  for (long long i = pos[0].first; i <= pos[1].first; i++)
    used[i][pos[0].second] = 1;
  for (long long i = pos[1].first; i <= pos[2].first; i++)
    used[i][pos[2].second] = 1;
  vector<pair<long long, long long>> ans;
  for (long long i = 0; i <= 1000; i++)
    for (long long j = 0; j <= 1000; j++)
      if (used[i][j]) ans.push_back({i, j});
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
  return 0;
}
