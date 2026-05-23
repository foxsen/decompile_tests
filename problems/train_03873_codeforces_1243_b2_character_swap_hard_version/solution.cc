#include <bits/stdc++.h>
using namespace std;
int alp[30];
inline void intn() {
  for (int i = 0; i < 30; i++) alp[i] = 0;
}
int main() {
  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    intn();
    vector<pair<int, int> > ops;
    for (int i = 0; i < n; i++) {
      alp[s[i] - 'a']++;
      alp[t[i] - 'a']++;
    }
    bool F = 0;
    for (int i = 0; i < 26; i++)
      if (alp[i] & 1) {
        F = 1;
        break;
      }
    if (F) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i]) continue;
      bool flag = 0;
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
          cnt++;
          flag = 1;
          swap(s[j], t[i]);
          ops.push_back(make_pair(j + 1, i + 1));
          break;
        }
      }
      if (flag) continue;
      for (int j = i + 1; j < n; j++) {
        if (t[i] == t[j]) {
          cnt++;
          flag = 1;
          swap(t[j], s[i]);
          ops.push_back(make_pair(i + 1, j + 1));
          break;
        }
      }
      if (flag) continue;
      for (int j = i + 1; j < n; j++) {
        if (s[i] == t[j]) {
          cnt += 2;
          flag = 1;
          swap(t[j], s[j]);
          swap(s[j], t[i]);
          ops.push_back(make_pair(j + 1, j + 1));
          ops.push_back(make_pair(j + 1, i + 1));
          break;
        }
      }
      if (flag) continue;
      for (int j = i + 1; j < n; j++) {
        if (t[i] == s[j]) {
          cnt += 2;
          flag = 1;
          swap(s[j], t[j]);
          swap(t[j], s[i]);
          ops.push_back(make_pair(j + 1, j + 1));
          ops.push_back(make_pair(i + 1, j + 1));
          break;
        }
      }
    }
    cout << "YES" << endl;
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
      cout << ops[i].first << " " << ops[i].second << endl;
    }
  }
}
