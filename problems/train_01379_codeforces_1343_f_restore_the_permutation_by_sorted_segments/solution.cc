#include <bits/stdc++.h>
using namespace std;
long long int solver(long long int x, vector<set<long long int> > &v,
                     long long int n) {
  long long int idx = -1, i;
  for (i = 0; i < n - 1; i++) {
    if (v[i].find(x) != v[i].end()) v[i].erase(x);
    if ((long long int)v[i].size() == 1) {
      if (idx == -1)
        idx = i;
      else
        return -1;
    }
  }
  return idx;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, k, l;
    cin >> n;
    vector<long long int> v[n - 1];
    for (i = 0; i < n - 1; i++) {
      long long int k;
      cin >> k;
      for (j = 0; j < k; j++) {
        long long int y;
        cin >> y;
        v[i].push_back(y);
      }
    }
    for (i = 1; i <= n; i++) {
      vector<long long int> ans;
      vector<set<long long int> > s(n - 1);
      for (j = 0; j < n - 1; j++) {
        long long int si = v[j].size();
        for (k = 0; k < si; k++) s[j].insert(v[j][k]);
      }
      long long int crr = i;
      for (j = 0; j < n; j++) {
        ans.push_back(crr);
        if (j < n - 1) {
          long long int tt = solver(crr, s, n);
          if (tt == -1) {
            break;
          } else {
            crr = *s[tt].begin();
          }
        }
      }
      if (j != n) continue;
      vector<long long int> used(n - 1, 0);
      for (j = 1; j < n; j++) {
        set<long long int> temp;
        temp.insert(ans[j]);
        for (k = j - 1; k >= 0; k--) {
          temp.insert(ans[k]);
          for (l = 0; l < n - 1; l++) {
            if (used[l] == 0) {
              long long int si_v = v[l].size();
              if (si_v == (j - k + 1)) {
                set<long long int>::iterator it;
                long long int xx = 0;
                for (it = temp.begin(); it != temp.end(); it++, xx++) {
                  if (v[l][xx] != *it) break;
                }
                if (it == temp.end()) {
                  used[l] = 1;
                  break;
                }
              }
            }
          }
          if (l != n - 1) {
            break;
          }
        }
        if (k != -1)
          continue;
        else {
          break;
        }
      }
      if (j != n)
        continue;
      else {
        for (j = 0; j < n; j++) cout << ans[j] << " ";
        cout << "\n";
        break;
      }
    }
  }
}
