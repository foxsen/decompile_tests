#include <bits/stdc++.h>
using namespace std;
class TaskB {
 public:
  bool islucky(string s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != '4' && s[i] != '7') return false;
    }
    return true;
  }
  void solve(istream& in, ostream& out) {
    string s, ans;
    in >> s;
    map<string, int> cnt;
    int mx = 0;
    for (int sz = 1; sz <= s.size(); ++sz) {
      for (int i = 0; i <= s.size() - sz; ++i) {
        string sub = s.substr(i, sz);
        if (islucky(sub)) {
          cnt[sub]++;
          if (cnt[sub] > mx) {
            mx = cnt[sub];
            ans = sub;
          } else if (cnt[sub] == mx && sub < ans) {
            ans = sub;
          }
        }
      }
    }
    out << (mx ? ans : "-1");
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  TaskB solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
