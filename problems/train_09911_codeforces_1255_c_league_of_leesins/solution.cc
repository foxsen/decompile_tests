#include <bits/stdc++.h>
using namespace std;
int fr[100005], n, b;
int sol[100005], use[100005];
vector<int> g[100005];
vector<int> nr[100005];
queue<int> q;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n - 2; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    nr[i].push_back(x);
    nr[i].push_back(y);
    nr[i].push_back(z);
    fr[y]++;
    fr[z]++;
    fr[x]++;
    g[x].push_back(i);
    g[y].push_back(i);
    g[z].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    if (fr[i] == 1) {
      sol[1] = i;
      for (auto it : nr[g[i][0]])
        if (fr[it] == 2) {
          sol[2] = it;
          break;
        }
      break;
    }
  use[sol[1]] = 1;
  use[sol[2]] = 1;
  for (int i = 3; i <= n; i++) {
    for (auto it : g[sol[i - 2]]) {
      for (auto j : nr[it])
        if (!use[j]) {
          sol[i] = j;
          use[j] = 1;
          break;
        }
    }
  }
  for (int i = 1; i <= n; i++) cout << sol[i] << ' ';
  return 0;
}
