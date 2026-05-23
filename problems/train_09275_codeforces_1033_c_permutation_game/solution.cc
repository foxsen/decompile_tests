#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
int inverse[N];
vector<int> g[N];
int dp[N];
bool solve(int start) {
  if (dp[start] != -1) return dp[start];
  bool possible = false;
  for (int i = 0; i < g[start].size(); i++) {
    int neighbor = g[start][i];
    possible = possible || !solve(neighbor);
  }
  dp[start] = possible;
  return possible;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) dp[i] = -1;
  for (int i = 0; i < n; i++) {
    inverse[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int start = inverse[i];
    for (int j = start; j < n; j += i) {
      if (a[j] > i && (((j - start) % i) == 0)) {
        g[i].push_back(a[j]);
      }
    }
    for (int j = start; j >= 0; j -= i) {
      if (a[j] > i && (((start - j) % i) == 0)) {
        g[i].push_back(a[j]);
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    solve(i);
  }
  for (int i = 0; i < n; i++) {
    if (dp[a[i]] == false)
      cout << "B";
    else
      cout << "A";
  }
  cout << endl;
}
