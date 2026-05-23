#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
char str[maxn];
int ar[10];
int br[10];
int aar[10];
int bbr[10];
int main() {
  cin >> str;
  int cnt = 0;
  vector<int> s, t;
  int pp;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    aar[str[i] - '0']++;
    bbr[str[i] - '0']++;
  }
  for (int i = 0; i < 10; i++) {
    int j = 10 - i;
    if (aar[i] > 0 && bbr[j] > 0) {
      for (int i = 0; i < 10; i++) ar[i] = aar[i], br[i] = bbr[i];
      vector<int> ans, ans1;
      ans.push_back(i);
      ans1.push_back(j);
      ar[i]--;
      br[j]--;
      for (int i = 0; i < 10;) {
        if (ar[i] > 0 && br[9 - i] > 0) {
          ans.push_back(i);
          ans1.push_back(9 - i);
          ar[i]--;
          br[9 - i]--;
        } else {
          i++;
        }
      }
      int cc = min(ar[0], br[0]);
      ar[0] -= cc;
      br[0] -= cc;
      if (cc + ans.size() > cnt) {
        cnt = cc + ans.size();
        for (int i = 0; i < 10; i++) {
          while (ar[i] > 0) ans.push_back(i), ar[i]--;
        }
        for (int i = 0; i < 10; i++) {
          while (br[i] > 0) ans1.push_back(i), br[i]--;
        }
        pp = cc;
        s = ans;
        t = ans1;
      }
    }
  }
  if (s.size() == 0) {
    pp = aar[0];
    aar[0] = bbr[0] = 0;
    for (int i = 0; i < 10; i++) {
      while (aar[i] > 0) s.push_back(i), aar[i]--;
      while (bbr[i] > 0) t.push_back(i), bbr[i]--;
    }
  }
  for (int i = s.size() - 1; i >= 0; i--) cout << s[i];
  for (int i = 0; i < pp; i++) cout << 0;
  cout << endl;
  for (int i = t.size() - 1; i >= 0; i--) cout << t[i];
  for (int i = 0; i < pp; i++) cout << 0;
  cout << endl;
  return 0;
}
