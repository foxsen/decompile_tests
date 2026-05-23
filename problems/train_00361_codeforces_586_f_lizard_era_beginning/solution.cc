#include <bits/stdc++.h>
using namespace std;
int first[25], second[25], z[25];
map<pair<int, int>, pair<int, int> > MAP;
string r[3] = {"LM", "LW", "MW"};
int n, lim, cc;
int u = 0, v = 0, c = 0, maxi = -25 * 1e7 - 10;
vector<string> ret, out;
void make(int ind, int t, int go) {
  if (ind == lim && !go) {
    if (!MAP.count(make_pair(v - u, c - u)))
      MAP[make_pair(v - u, c - u)] = make_pair(u, t);
    if (MAP[make_pair(v - u, c - u)].first < u)
      MAP[make_pair(v - u, c - u)] = make_pair(u, t);
    return;
  }
  if (ind == lim && go) {
    if (MAP.count(make_pair(u - v, u - c))) {
      int t = MAP[make_pair(u - v, u - c)].second, i,
          tr = MAP[make_pair(u - v, u - c)].first;
      if (u + tr > maxi) {
        vector<string> temp;
        maxi = u + tr;
        for (i = 0; i < cc; ++i) {
          temp.push_back(r[t % 3]);
          t /= 3;
        }
        reverse(temp.begin(), temp.end());
        out.clear();
        for (i = 0; i < ret.size(); ++i) out.push_back(ret[i]);
        for (i = 0; i < temp.size(); ++i) out.push_back(temp[i]);
      }
    }
    return;
  }
  int i;
  for (i = 0; i < 3; ++i) {
    u += first[ind], v += second[ind], c += z[ind];
    if (i == 0) c -= z[ind];
    if (i == 1) v -= second[ind];
    if (i == 2) u -= first[ind];
    if (go) ret.push_back(r[i]);
    make(ind + 1, t * 3 + i, go);
    u -= first[ind], v -= second[ind], c -= z[ind];
    if (i == 0)
      c += z[ind];
    else if (i == 1)
      v += second[ind];
    else
      u += first[ind];
    if (go) ret.pop_back();
  }
}
int main() {
  int i, j;
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> first[i] >> second[i] >> z[i];
  }
  int s = n - (n / 2);
  lim = n;
  make(s, 0, 0);
  cc = n - s;
  ret.clear();
  lim = s;
  s = 0;
  make(s, 0, 1);
  if (out.size() > 0)
    for (i = 0; i < out.size(); ++i) cout << out[i] << endl;
  else
    cout << "Impossible\n";
}
