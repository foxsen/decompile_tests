#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  string s, ans = "";
  long long int c1 = 0, c2 = 0, c3 = 0, fl = 0;
  cin >> s;
  for (long long int i = (0); i < (s.length()); i++) {
    if (s[i] == '(')
      c1++;
    else if (s[i] == ')')
      c2++;
    else
      c3++;
    if (c1 < c2 + c3) fl = 1;
  }
  if (c1 < c2 + c3 || fl)
    return cout << "-1\n", 0;
  else {
    long long int c = 0, b1 = 0, b2 = 0, b3 = 0;
    for (long long int i = (0); i < (s.length()); i++) {
      if (s[i] == '(')
        ans = ans + '(', b1++;
      else if (s[i] == ')')
        ans = ans + ')', b2++;
      else if (s[i] == '#') {
        ans = ans + ')', c++;
        if (c == c3) {
          b2 += c1 - (c2 + c3 - 1);
          for (long long int i = (0); i < (c1 - (c2 + c3 - 1)); i++) ans += ')';
        } else
          b2++;
      }
      if (b1 < b2) {
        fl = 1;
        break;
      }
    }
    if (fl == 1)
      return cout << "-1\n", 0;
    else {
      for (long long int i = (0); i < (c3 - 1); i++) cout << "1\n";
      cout << c1 - (c2 + c3 - 1) << "\n";
    }
  }
  return 0;
}
