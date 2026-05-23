#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
vector<int> op;
vector<vector<int>> v;
vector<bool> val;
int mp[1000001][2];
vector<int> saved;
vector<int> cur;
vector<pair<int, int>> curc;
vector<int> parent;
int fans = -1;
static string s;
int solve(int k) {
  cur.push_back(k);
  if (v[k].size() == 0) return saved[k] = val[k];
  if (v[k].size() == 1) return saved[k] = !solve(v[k][0]);
  if (op[k] == 1) return saved[k] = (solve(v[k][0]) & solve(v[k][1]));
  if (op[k] == 2) return saved[k] = (solve(v[k][0]) | solve(v[k][1]));
  if (op[k] == 3) return saved[k] = (solve(v[k][0]) ^ solve(v[k][1]));
  return 0;
}
void solve2(int k, int num) {
  if (k == 0) {
    fans = num;
    return;
  }
  if (mp[k][num] != -1) {
    fans = mp[k][num];
    return;
  }
  int p = parent[k];
  if (v[p].size() == 1) {
    curc.push_back({p, 1 - num});
    solve2(p, 1 - num);
    return;
  }
  int num1 = v[p][0], num2 = v[p][1];
  bool ar1, ar2;
  if (num1 == k)
    ar1 = num, ar2 = saved[v[p][1]];
  else
    ar2 = num, ar1 = saved[v[p][0]];
  if (op[p] == 1) {
    curc.push_back({p, ar1 & ar2});
    solve2(p, ar1 & ar2);
  }
  if (op[p] == 2) {
    curc.push_back({p, ar1 | ar2});
    solve2(p, ar1 | ar2);
  }
  if (op[p] == 3) {
    curc.push_back({p, ar1 ^ ar2});
    solve2(p, ar1 ^ ar2);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  memset(mp, -1, sizeof(mp));
  op.resize(n);
  val.resize(n);
  parent.resize(n);
  v.assign(n, {});
  saved.resize(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == "IN") {
      op[i] = 0;
      int num;
      cin >> num;
      val[i] = num;
    } else if (s == "NOT") {
      int num;
      cin >> num;
      op[i] = 0;
      num--;
      v[i].push_back(num);
      parent[num] = i;
    } else {
      if (s == "AND") op[i] = 1;
      if (s == "OR") op[i] = 2;
      if (s == "XOR") op[i] = 3;
      int num1, num2;
      cin >> num1 >> num2;
      num1--;
      num2--;
      v[i].push_back(num1);
      v[i].push_back(num2);
      parent[num1] = i;
      parent[num2] = i;
    }
  }
  bool ans = solve(0);
  for (int i = 0; i < n; i++) {
    mp[i][saved[i]] = ans;
  }
  parent[0] = -1;
  for (int i = 0; i < n; i++) {
    if (v[i].size() == 0) {
      solve2(i, 1 - val[i]);
      if ((int)curc.size()) {
        for (auto xx : curc) mp[xx.first][xx.second] = fans;
      }
      curc.clear();
      cout << fans;
    }
  }
  cout << endl;
}
