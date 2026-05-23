#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int o[15];
int mixn = 9999;
vector<int> V, V2;
void dfs(int goal, int times) {
  if (times >= mixn) return;
  if (goal == n) {
    if (o[n] < 0) {
      V2 = V;
      mixn = times;
    }
    return;
  }
  for (int i = 0;
       i <= max(o[goal - 1] / b + 1, max(o[goal] / a + 1, o[goal + 1] / b + 1));
       ++i) {
    if (o[goal - 1] < i * b) {
      o[goal - 1] -= i * b;
      o[goal] -= i * a;
      o[goal + 1] -= i * b;
      for (int j = 0; j < i; j++) V.push_back(goal);
      dfs(goal + 1, times + i);
      for (int j = 0; j < i; j++) V.pop_back();
      o[goal - 1] += i * b;
      o[goal] += i * a;
      o[goal + 1] += i * b;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  V2.clear();
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    cin >> o[i];
  }
  dfs(2, 0);
  cout << mixn << endl;
  int len = V2.size();
  for (int i = 0; i < len - 1; ++i) cout << V2[i] << " ";
  cout << V2[len - 1] << endl;
  return 0;
}
