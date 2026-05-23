#include <bits/stdc++.h>
using namespace std;
bool isrange(int second, int first, int n, int m) {
  if (0 <= second && second < n && 0 <= first && first < m) return true;
  return false;
}
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1},
    ddy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, ddx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int MAX = 1e6 + 100;
int n, m;
pair<string, int> s[MAX];
bool comp(pair<string, int>& a, pair<string, int>& b) {
  for (int e = 0; e < m; e++) {
    if (e % 2 == 0) {
      if (a.first[e] != b.first[e]) return a.first[e] < b.first[e];
    } else {
      if (a.first[e] != b.first[e]) return a.first[e] > b.first[e];
    }
  }
  return true;
}
void solve(int tc) {
  cin >> n >> m;
  for (int e = 0; e < n; e++) {
    cin >> s[e].first;
    s[e].second = e + 1;
  }
  sort(s, s + n, comp);
  for (int e = 0; e < n; e++) cout << s[e].second << " ";
}
int main(void) {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  for (int test_number = 1; test_number <= tc; test_number++) {
    solve(test_number);
  }
  return 0;
}
