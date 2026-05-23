#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int k;
  cin >> k;
  int n = 1 << k;
  vector<vector<long long>> a(n, vector<long long>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  int t;
  cin >> t;
  vector<pair<int, int>> F(t);
  for (int i = 0; i < t; i++) cin >> F[i].first >> F[i].second;
  vector<pair<int, int>> V;
  auto key = F[0];
  for (auto it : F) {
    V.push_back(make_pair(it.first - key.first, it.second - key.second));
  }
  for (int iteration = 0; iteration < k; iteration++) {
    vector<vector<long long>> new_grid(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        for (auto it : V)
          new_grid[i][j] ^= a[(i + n - it.first) % n][(j + n - it.second) % n];
      }
    a = new_grid;
    for (int i = 0; i < t; i++) {
      V[i].first = (V[i].first * 2) % n;
      V[i].second = (V[i].second * 2) % n;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j]) cnt++;
  cout << cnt;
}
