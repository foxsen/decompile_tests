#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double PI = acos((long double)-1.0);
const int INF = 1 << 30;
const long long LINF = 1ll << 61;
const int BUFFER_SZ = 1 << 20;
const int MOD = 1000 * 1000 * 1000 + 7;
char BUFFER[BUFFER_SZ];
int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
double gd() {
  double x;
  scanf("%lf", &x);
  return x;
}
long long gll() {
  long long x;
  cin >> x;
  return x;
}
vector<int> gvi(int n) {
  vector<int> a;
  while (n-- > 0) a.push_back(gi());
  return a;
}
string gs() {
  scanf("%s", BUFFER);
  return string(BUFFER);
}
template <class T>
void print(vector<T> &x, string format) {
  format += "%c";
  for (int i = 0; i < x.size(); ++i)
    printf(format.c_str(), x[i], i + 1 == x.size() ? '\n' : ' ');
}
int dp[64][64];
int N;
int rulesIn[64];
int rulesOut1[64];
int rulesOut2[64];
string A, B;
int dp1[64][64];
int dp2[64][64];
int go(string &s, int (&dp)[64][64], int a, int b) {
  int &r = dp[a][b];
  if (r != -1) return r;
  if (a == b) return r = 1 << (s[a] - 'a');
  r = 0;
  for (int i = a; i < b; ++i) {
    for (int k = 0; k < N; ++k) {
      if ((go(s, dp, a, i) >> rulesOut1[k] & 1) &&
          (go(s, dp, i + 1, b) >> rulesOut2[k] & 1)) {
        r |= 1 << rulesIn[k];
      }
    }
  }
  return r;
}
int rec(int a, int b) {
  int &r = dp[a][b];
  if (r != -1) return r;
  r = INF;
  if (a == A.size() && b == B.size()) return r = 0;
  if (a == A.size() || b == B.size()) return INF;
  for (int ai = 1; a + ai <= A.size(); ++ai) {
    for (int bi = 1; b + bi <= B.size(); ++bi) {
      if (go(A, dp1, a, a + ai - 1) & go(B, dp2, b, b + bi - 1)) {
        r = min(r, 1 + rec(a + ai, b + bi));
      }
    }
  }
  return r;
}
void solve() {
  A = gs();
  B = gs();
  N = gi();
  for (int i = 0; i < N; ++i) {
    string s = gs();
    rulesIn[i] = s[0] - 'a';
    rulesOut1[i] = s[3] - 'a';
    rulesOut2[i] = s[4] - 'a';
  }
  memset((dp), (-1), sizeof(dp));
  memset((dp1), (-1), sizeof(dp1));
  memset((dp2), (-1), sizeof(dp2));
  int res = rec(0, 0);
  if (res == INF) res = -1;
  cout << res << endl;
}
int main() {
  solve();
  return 0;
}
