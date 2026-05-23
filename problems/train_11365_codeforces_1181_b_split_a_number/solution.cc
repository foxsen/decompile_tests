#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
const long long MOD = 1e9 + 7, N = 1e5 + 5, inf = 1e18;
string hope(string a, string b) {
  int al = ((int)(a).size()), bl = ((int)(b).size()), car = 0;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if (bl < al) {
    for (int i = 0; i < al - bl; i++) b += '0';
  } else {
    for (int i = 0; i < bl - al; i++) a += '0';
  }
  string ans = "";
  for (int i = 0; i < max(al, bl); i++) {
    int val = (a[i] - '0') + (b[i] - '0') + car;
    ans += char(val % 10 + '0');
    car = val / 10;
  }
  if (car != 0) ans += char(car + '0');
  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string c1 = "", c2 = "";
    if (n % 2 == 0) {
      int ind = -1;
      for (int i = n / 2; i < n; i++) {
        if (s[i] != '0') {
          ind = i;
          break;
        }
      }
      if (ind != -1) {
        string a = "", b = "";
        for (int i = 0; i < ind; i++) {
          a += s[i];
        }
        for (int i = ind; i < n; i++) {
          b += s[i];
        }
        c1 = hope(a, b);
      }
      ind = -1;
      for (int i = n / 2 - 1; i > -1; i--) {
        if (s[i] != '0') {
          ind = i;
          break;
        }
      }
      if (ind != -1) {
        string a = "", b = "";
        for (int i = 0; i < ind; i++) {
          a += s[i];
        }
        for (int i = ind; i < n; i++) {
          b += s[i];
        }
        c2 = hope(a, b);
      }
    } else {
      int ind = -1;
      for (int i = n / 2 + 1; i < n; i++) {
        if (s[i] != '0') {
          ind = i;
          break;
        }
      }
      if (ind != -1) {
        string a = "", b = "";
        for (int i = 0; i < ind; i++) {
          a += s[i];
        }
        for (int i = ind; i < n; i++) {
          b += s[i];
        }
        c1 = hope(a, b);
      }
      ind = -1;
      for (int i = n / 2; i > -1; i--) {
        if (s[i] != '0') {
          ind = i;
          break;
        }
      }
      if (ind != -1) {
        string a = "", b = "";
        for (int i = 0; i < ind; i++) {
          a += s[i];
        }
        for (int i = ind; i < n; i++) {
          b += s[i];
        }
        c2 = hope(a, b);
      }
    }
    if (((int)(c1).size()) == 0)
      cout << c2;
    else if (((int)(c2).size()) == 0)
      cout << c1;
    else if (((int)(c1).size()) < ((int)(c2).size()))
      cout << c1;
    else if (((int)(c1).size()) > ((int)(c2).size()))
      cout << c2;
    else {
      for (int i = 0; i < ((int)(c1).size()); i++) {
        if (c1[i] < c2[i]) {
          cout << c1;
          break;
        } else if (c2[i] < c1[i]) {
          cout << c2;
          break;
        }
      }
    }
    cout << "\n";
    ;
  }
}
