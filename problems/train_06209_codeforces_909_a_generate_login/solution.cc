#include <bits/stdc++.h>
using namespace std;
struct debugger {
  static void call(string::iterator it, string::iterator ed) {}
  template <typename T, typename... aT>
  static void call(string::iterator it, string::iterator ed, T a, aT... rest) {
    string b;
    for (; *it != ','; ++it)
      if (*it != ' ') b += *it;
    cout << b << "=" << a << " ";
    call(++it, ed, rest...);
  }
};
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  string f, l, login = "zzzzzzzzzzzzzzzzzzzzz";
  cin >> f >> l;
  for (int i = (int)(0); i < (int)(f.size()); ++i) {
    for (int j = (int)(0); j < (int)(l.size()); ++j) {
      login = min(login, f.substr(0, i + 1) + l.substr(0, j + 1));
    }
  }
  cout << login << endl;
  return 0;
}
