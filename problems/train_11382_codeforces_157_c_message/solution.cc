#include <bits/stdc++.h>
using namespace std;
const int INF_MAX = 0x7FFFFFFF;
const int INF_MIN = -(1 << 31);
const double eps = 1e-10;
const double pi = acos(-1.0);
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
int dir_4[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int dir_8[8][2] = {{0, 1},  {-1, 1}, {-1, 0}, {-1, -1},
                   {0, -1}, {1, -1}, {1, 0},  {1, 1}};
string a;
string b;
string temp;
int ans;
int newone;
int al;
int bl;
void initial() {
  ans = 0;
  newone = 0;
  a = "";
  b = "";
  temp = "";
}
void cal() {
  al = a.size();
  bl = b.size();
  ans = b.length();
  for (int i = 0; i < bl; i++) {
    temp += "*";
  }
  a = temp + a + temp;
  al = al + bl + bl;
  for (int i = 0; i < al - bl; i++) {
    newone = 0;
    for (int j = 0; j < bl; j++) {
      if (a[i + j] != b[j]) newone++;
    }
    if (newone < ans) {
      ans = newone;
    }
  }
}
void output() { cout << ans << endl; }
int main() {
  initial();
  cin >> a >> b;
  cal();
  output();
  return 0;
}
