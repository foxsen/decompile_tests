#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string s;
int used[105];
int main() {
  memset(used, 0, sizeof(used));
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'a') s[i] = s[i] - 32;
    }
    v.push_back(s);
  }
  cin >> s;
  string s1 = s;
  string s2 = s;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] >= 'a') s1[i] = s1[i] - 32;
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < n; j++) {
      int tr = 1;
      for (int k = 0; k < v[j].size(); k++) {
        if (v[j][k] != s1[i + k]) tr = 0;
      }
      if (tr == 1) {
        for (int z = i; z <= i + v[j].size() - 1; z++) {
          used[z] = 1;
        }
      }
    }
  }
  string g;
  cin >> g;
  for (int i = 0; i < s.size(); i++) {
    if (used[i]) {
      if (s[i] < 'a') {
        s[i] = g[0] - 32;
      } else
        s[i] = g[0];
      if (s1[i] == g[0] - 32) {
        if (g[0] == 'a') {
          if (s2[i] < 'a')
            s[i] = 'B';
          else
            s[i] = 'b';
        } else {
          if (s2[i] < 'a')
            s[i] = 'A';
          else
            s[i] = 'a';
        }
      }
    }
  }
  cout << s << endl;
  return 0;
}
