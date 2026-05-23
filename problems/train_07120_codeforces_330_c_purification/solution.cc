#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
bool dfs(const vector<vector<bool> >& a, vector<pair<int, int> >& res) {
  for (int i = 0; i < a.size(); ++i) {
    bool foo = true;
    for (int j = 0; j < a.size(); ++j) {
      if (!a[i][j]) {
        foo = false;
        res.push_back(make_pair(i, j));
        break;
      }
    }
    if (foo) {
      return false;
    }
  }
  return true;
}
int main() {
  int N;
  cin >> N;
  vector<vector<bool> > a(N, vector<bool>(N, false));
  getchar();
  for (int i = 0; i < N; ++i) {
    char ch = getchar();
    for (int j = 0; j < N; j++, ch = getchar()) {
      if (ch == 'E') {
        a[i][j] = 1;
      }
    }
  }
  vector<bool> v(N, false), h(N, false);
  vector<pair<int, int> > res;
  res.reserve(N);
  if (dfs(a, res)) {
    for (int i = 0; i < res.size(); ++i) {
      printf("%d %d\n", res[i].first + 1, res[i].second + 1);
    }
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      bool t = a[i][j];
      a[i][j] = a[j][i];
      a[j][i] = t;
    }
  }
  res.clear();
  if (dfs(a, res)) {
    for (int i = 0; i < res.size(); ++i) {
      printf("%d %d\n", res[i].second + 1, res[i].first + 1);
    }
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
