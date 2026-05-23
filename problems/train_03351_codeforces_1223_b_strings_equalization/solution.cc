#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 11;
const double PI = acos(-1);
void faltu() { cerr << endl; }
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s, u;
  bool c;
  int t;
  cin >> t;
  while (t--) {
    cin >> s >> u;
    c = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s.find(u[i]) != -1) {
        c = 1;
        break;
      }
    }
    if (c == 0)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
