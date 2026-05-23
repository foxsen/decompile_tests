#include <bits/stdc++.h>
using namespace std;
int n, c[200005], p[200005], x, ans[200005], f;
vector<int> v[200005], v1;
void solve(int a, int l) {
  for (int i = 0; i < v[a].size(); i++) {
    if (v[a][i] != l) {
      solve(v[a][i], a);
      p[a] += p[v[a][i]];
    }
  }
  if (p[a] < c[a]) {
    x = 1;
  }
  p[a]++;
}
void find(int a, int l) {
  ans[a] = v1[c[a]];
  v1.erase(v1.begin() + c[a]);
  for (int i = 0; i < v[a].size(); i++) {
    if (v[a][i] != l) {
      find(v[a][i], a);
    }
  }
}
int a;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> c[i];
    if (a != 0) {
      v[i].push_back(a);
      v[a].push_back(i);
    } else
      f = i;
    v1.push_back(i);
  }
  solve(f, 0);
  if (x == 1) {
    cout << "NO" << endl;
    return 0;
  }
  find(f, 0);
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
