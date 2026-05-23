#include <bits/stdc++.h>
using namespace std;
long long sz;
bool valido(const long long &p) { return (p < sz); }
int main() {
  string s, r, b, o;
  cin >> s;
  sz = int(s.size());
  for (long long i = 0; i < sz; i++) {
    if (s[i] == '1')
      r += s[i];
    else
      b += s[i];
  }
  bool a = false;
  for (long long i = 0; i < int(b.size()) && !a; i++) {
    if (b[i] == '2') {
      b.insert(i, r);
      a = true;
    }
  }
  if (!a) b += r;
  if (int(b.size()))
    cout << b << "\n";
  else
    cout << r << "\n";
  return 0;
}
