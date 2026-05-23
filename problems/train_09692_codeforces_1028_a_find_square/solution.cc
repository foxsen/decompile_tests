#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = (1e-9);
void carrotiq() {}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main(int argc, char const *argv[]) {
  fast();
  carrotiq();
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > v;
  char ch;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> ch;
      if (ch == 'B') v.push_back({i, j});
    }
  }
  int mid = (v.size()) / 2;
  cout << v[mid].first + 1 << " " << v[mid].second + 1;
}
