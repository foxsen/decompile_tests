#include <bits/stdc++.h>
using namespace std;
int t, n, m, cnt[105];
string s[105], s2, s3, ms[105];
bool u[105], pos[105][105];
bool k;
map<string, int> mx;
vector<string> v;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    getline(cin, s2);
    mx.clear();
    v.clear();
    for (int l = 0; l < n; ++l) {
      cin >> s[l];
      mx[s[l]] = l;
    }
    cin >> m;
    getline(cin, s2);
    k = 0;
    memset(pos, 0, sizeof pos);
    memset(cnt, 0, sizeof cnt);
    bool F = 0;
    for (int l = 0; l < m; ++l) {
      memset(u, 0, sizeof u);
      getline(cin, s2);
      s3 = "";
      ms[l] = s2;
      for (int l2 = 0; l2 < s2.size(); ++l2) {
        if (s2[l2] >= '0' && s2[l2] <= '9' || s2[l2] >= 'A' && s2[l2] <= 'Z' ||
            s2[l2] >= 'a' && s2[l2] <= 'z')
          s3 += s2[l2];
        else if (s3 != "") {
          if (mx.count(s3)) u[mx[s3]] = 1;
          s3 = "";
          if (s2[0] != '?') {
            for (int l3 = 0; l3 < n; ++l3) u[l3] = !u[l3];
            l2 = s2.size();
          }
        }
      }
      if (mx.count(s3)) u[mx[s3]] = 1;
      k = 1;
      for (int l2 = 0; l2 < n; ++l2) {
        if (!u[l2] && (l == 0 || cnt[l - 1] > 1 || !pos[l - 1][l2])) {
          pos[l][l2] = 1;
          cnt[l]++;
          k = 0;
        }
      }
      F = (F || k);
    }
    if (F) {
      cout << "Impossible" << endl;
      continue;
    }
    for (int l = m - 1; l >= 0; --l) {
      ms[l].erase(0, ms[l].find(':'));
      for (int l2 = 0; l2 < n && v.size() < m - l; ++l2)
        if (pos[l][l2]) {
          if (l > 0) pos[l - 1][l2] = 0;
          v.push_back(s[l2] + ms[l]);
        }
    }
    for (int l = v.size() - 1; l >= 0; --l) cout << v[l] << endl;
  }
  return 0;
}
