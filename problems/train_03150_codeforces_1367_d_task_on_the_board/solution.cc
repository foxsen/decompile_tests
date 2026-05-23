#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    string t;
    cin >> s;
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    map<char, int> mp;
    for (int i = 0; i < m; i++) t.push_back('.');
    set<char> st;
    for (int i = 0; i < s.length(); i++) {
      st.insert(s[i]);
      mp[s[i]]++;
    }
    set<char>::iterator it = st.end();
    --it;
    int p = 0;
    while (1) {
      vector<int> tmp;
      int count = 0;
      for (int i = 0; i < m; i++) {
        if (a[i] == 0 && t[i] == '.') {
          count++;
          tmp.push_back(i);
          p++;
        }
        while (mp[*it] < count) --it;
        for (auto q : tmp) t[q] = *it;
      }
      for (auto y : tmp) {
        for (int j = 0; j < m; j++) {
          if (a[j] != 0 && t[j] == '.') a[j] -= abs(j - y);
        }
      }
      if (p == m) break;
      --it;
    }
    cout << t << endl;
  }
  return 0;
}
