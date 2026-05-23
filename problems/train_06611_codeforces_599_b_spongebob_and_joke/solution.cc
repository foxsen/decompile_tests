#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> b, sol;
  map<int, vector<int> > f;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    f[a].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> a;
    b.push_back(a);
  }
  int flag = 1;
  for (int i = 0; i < b.size(); i++) {
    if (f[b[i]].size() == 0) {
      cout << "Impossible" << '\n';
      return 0;
    } else {
      if (f[b[i]].size() > 1)
        flag = 0;
      else
        sol.push_back(f[b[i]][0] + 1);
    }
  }
  if (flag) {
    cout << "Possible" << '\n';
    for (int i = 0; i < sol.size(); i++) cout << sol[i] << " ";
    cout << '\n';
  } else
    cout << "Ambiguity" << '\n';
  return 0;
}
