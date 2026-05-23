#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long int rand(long long int x, long long int y) {
  ++y;
  return (rng() % (y - x)) + x;
}
string to_string(char c) {
  string second(1, c);
  return second;
}
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void degug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void degug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  degug_out(T...);
}
inline long long int gcd(long long int a, long long int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int n, m;
bool grid[52][52], grid2[52][52];
bool doesnt(long long int x, long long int y) {
  if (x + 1 > n || y + 1 > m) return 0;
  return (grid[x][y] && grid[x + 1][y] && grid[x][y + 1] && grid[x + 1][y + 1]);
}
vector<pair<long long int, long long int> > moves;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long int i = (1); i <= (long long int)(n); ++i)
    for (long long int j = (1); j <= (long long int)(m); ++j) cin >> grid[i][j];
  for (long long int i = (1); i <= (long long int)(n); ++i)
    for (long long int j = (1); j <= (long long int)(m); ++j)
      if (doesnt(i, j)) {
        grid2[i][j] = grid2[i + 1][j] = grid2[i][j + 1] = grid2[i + 1][j + 1] =
            1;
        moves.emplace_back(i, j);
      }
  for (long long int i = (1); i <= (long long int)(n); ++i)
    for (long long int j = (1); j <= (long long int)(m); ++j)
      if (grid[i][j] ^ grid2[i][j]) {
        cout << "-1\n";
        return 0;
      }
  cout << moves.size() << '\n';
  for (auto i : moves) cout << i.first << ' ' << i.second << '\n';
}
