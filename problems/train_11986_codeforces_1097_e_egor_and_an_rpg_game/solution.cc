#include <bits/stdc++.h>
using namespace std;
int lim = 1e6;
int inf = 1e8;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
vector<vector<int> > part;
vector<int> lis(vector<int>& v) {
  int n = v.size();
  vector<int> ansv;
  vector<int> dp(n + 1, inf);
  dp[0] = -inf;
  vector<int> dpind(n + 1, -1);
  vector<int> p(n, -1);
  for (int i = 0; i < n; i++) {
    int j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
    if (v[i] < dp[j] and v[i] > dp[j - 1]) {
      dp[j] = v[i];
      dpind[j] = i;
      p[i] = dpind[j - 1];
    }
  }
  int cur = 0;
  for (int i = 0; i <= n; i++) {
    if (dp[i] < inf) {
      cur = dpind[i];
    }
  }
  while (cur != -1) {
    ansv.push_back(cur);
    cur = p[cur];
  }
  int k = ansv.size();
  vector<int> tmp(k);
  for (int i = 0; i < k; i++) {
    tmp[i] = ansv[k - i - 1];
  }
  ansv = tmp;
  return ansv;
}
void solve(vector<int>& v) {
  int n = v.size();
  vector<int> indices = lis(v);
  long long is = indices.size();
  is = is * (is + 1) / 2;
  if (is > n) {
    vector<bool> taken(n, 0);
    for (int i = 0; i < indices.size(); i++) {
      taken[indices[i]] = 1;
    }
    vector<int> tmp;
    vector<int> act;
    for (int i = 0; i < n; i++) {
      if (!taken[i])
        tmp.push_back(v[i]);
      else
        act.push_back(v[i]);
    }
    part.push_back(act);
    solve(tmp);
  } else {
    map<int, int> tops;
    vector<vector<int> > tmpparts;
    for (int i = 0; i < n; i++) {
      auto it = tops.lower_bound(v[i]);
      if (it == tops.end()) {
        tmpparts.push_back(vector<int>(1, v[i]));
        tops[v[i]] = tmpparts.size() - 1;
      } else {
        tmpparts[it->second].push_back(v[i]);
        tops[v[i]] = it->second;
        tops.erase(it->first);
      }
    }
    for (int i = 0; i < tmpparts.size(); i++) {
      part.push_back(tmpparts[i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    part.clear();
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    solve(v);
    cout << part.size() << '\n';
    for (int i = 0; i < part.size(); i++) {
      if (part[i].size() > 1) {
        cout << part[i].size() << " ";
        for (int j = 0; j < part[i].size(); j++) {
          cout << part[i][j] << " ";
        }
        cout << '\n';
      } else {
        cout << 1 << " " << part[i][0] << '\n';
      }
    }
  }
}
