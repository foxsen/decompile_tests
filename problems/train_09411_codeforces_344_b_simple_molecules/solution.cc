#include <bits/stdc++.h>
using namespace std;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
string makeintString(int x) {
  stringstream ss;
  ss << x;
  string str = ss.str();
  return str;
}
string makellString(long long x) {
  stringstream ss;
  ss << x;
  string str = ss.str();
  return str;
}
char cpp(char c) { return static_cast<char>(c + 1); }
struct func {
  bool operator()(pair<int, int> const &a, pair<int, int> const &b) {
    if (a.first == b.first) return (a.second < b.second);
    return (a.first < b.first);
  }
};
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 2 == 1)
      cout << "Impossible" << '\n';
    else {
      long long x, y, z;
      x = (a - c + b) / 2;
      y = (c + b - a) / 2;
      z = (c - b + a) / 2;
      if (x >= 0 && y >= 0 && z >= 0)
        cout << x << " " << y << " " << z << '\n';
      else
        cout << "Impossible" << '\n';
    }
  }
  return 0;
}
