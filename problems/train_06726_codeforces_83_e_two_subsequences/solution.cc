#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, dps[MAXN], dpd[MAXN], ps[MAXN];
int mxs[(1 << 20)][21];
bool se[(1 << 20)][21];
string w[MAXN];
void setmxs(int ii, int sz, int val) {
  if (!se[ii][sz])
    mxs[ii][sz] = val, se[ii][sz] = 1;
  else
    mxs[ii][sz] = min(mxs[ii][sz], val);
}
int getmxs(int ii, int sz) {
  if (se[ii][sz]) return mxs[ii][sz];
  return -1e9;
}
int getdif(string &a, string &b) {
  for (int s = 0; s < a.size(); s++) {
    int ts = s;
    bool ok = 1;
    for (int j = 0; j < b.size() && ts < a.size(); j++, ts++)
      if (a[ts] != b[j]) {
        ok = false;
        break;
      }
    if (ok) return s;
  }
  return a.size();
}
void addtomx(int ind, int val) {
  ind--;
  setmxs(0, 0, val);
  for (int i = 0; i < w[ind].size(); i++) {
    int res = 0, sz = 0;
    for (int j = i; j < w[ind].size(); j++) {
      sz++, res *= 2;
      if (w[ind][j] == '1') res += 1;
    }
    setmxs(res, sz, val);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    if (i > 0) ps[i] = ps[i - 1] + getdif(w[i - 1], w[i]);
  }
  dpd[0] = w[0].size();
  dpd[1] = w[1].size() * 2;
  for (int i = 2; i < n; i++) {
    dpd[i] = dpd[i - 1] + getdif(w[i - 2], w[i]);
    dpd[i] = min(dpd[i], ps[i - 1] + (int)w[0].size() + (int)w[i].size());
    if (i > 2) {
      addtomx(i - 2, dpd[i - 2] - ps[i - 2]);
      for (int j = -1; j < (int)w[i].size(); j++) {
        int sz = 0, res = 0;
        for (int k = 0; k <= j; k++) {
          sz++, res *= 2;
          if (w[i][k] == '1') res += 1;
        }
        int t = getmxs(res, sz);
        if (t != -1e9)
          dpd[i] = min(dpd[i], t + ((int)w[i].size() - j - 1) -
                                   getdif(w[i - 1], w[i]) + ps[i]);
      }
    }
  }
  dps[0] = w[0].size();
  for (int i = 1; i < n; i++)
    dps[i] = min(dpd[i - 1], dps[i - 1]) + getdif(w[i - 1], w[i]);
  cout << min(dpd[n - 1], dps[n - 1]);
}
