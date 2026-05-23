#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e9;
bool ch(string x) {
  if (x == "") return false;
  for (int i = 0; i < x.size(); i++) {
    if (x[i] > '9' || x[i] < '0') return false;
  }
  if (x.size() > 1 && x[0] == '0') return false;
  return true;
}
int main() {
  string s;
  cin >> s;
  string a = "", b = "";
  int aa = 0, bb = 0, c = 0;
  int n = (int)s.size();
  s.push_back(' ');
  for (int i = 0; i < n;) {
    string x = "";
    bool ok = true;
    if (s[i] == ',' || s[i] == ';' || i == 0) {
      if (c == 0 && (s[i] == ',' || s[i] == ';')) {
        ok = false;
      }
      if ((s[i] == ',' || s[i] == ';') && ok) i++;
      c++;
      while (s[i] != ',' && s[i] != ';' && i < n && ok) {
        x += s[i];
        i++;
      }
    }
    if (ch(x)) {
      if (aa == 0)
        a += x;
      else
        a += "," + x;
      aa++;
    } else {
      if (bb == 0)
        b += x;
      else
        b += "," + x;
      bb++;
    }
  }
  if (aa == 0)
    cout << "-";
  else
    cout << "\"" << a << "\"";
  cout << endl;
  if (bb == 0)
    cout << "-";
  else
    cout << "\"" << b << "\"";
  cout << endl;
}
