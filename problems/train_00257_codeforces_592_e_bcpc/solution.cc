#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-8;
const int maxn = 4e5 + 5;
const int maxm = 4e4 + 5;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int _inf = -1e9 + 7;
inline int scan() {
  int m = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') m = m * 10 + c - '0', c = getchar();
  return m;
}
int N, C, D;
struct node {
  long long a, b;
  node() {}
  node(long long a, long long b) : a(a), b(b) {}
  bool operator<(const node& t) const { return a * t.b < b * t.a; }
  bool operator==(const node& t) const { return a * t.b == b * t.a; }
  node inv() { return node(-(this->a), -(this->b)); }
} lk[4][maxn];
int lkcnt[4];
int lkcnt_[4];
int work(int i, int j) {
  if (i == 0 && j == 1) {
    return lkcnt[0] - lkcnt_[0];
  }
  if (i == 0 && j == 2) {
    return lkcnt[0] - lkcnt_[1];
  }
  if (i == 1 && j == 2) {
    return lkcnt[1] - lkcnt_[2];
  }
  if (i == 3 && j == 1) return lkcnt[3] - lkcnt_[3];
  return lkcnt[i];
}
int main() {
  cin >> N >> C >> D;
  for (int i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    a -= C;
    b -= D;
    if (a >= 0 && b >= 0) {
      lk[0][lkcnt[0]++] = node(a, b);
      if (a == 0) lkcnt_[0]++;
      if (b == 0) lkcnt_[1]++;
    } else if (a < 0 && b >= 0) {
      lk[1][lkcnt[1]++] = node(a, b);
      if (b == 0) lkcnt_[2]++;
    } else if (a < 0 && b < 0) {
      lk[2][lkcnt[2]++] = node(a, b);
    } else {
      lk[3][lkcnt[3]++] = node(a, b);
      if (a == 0) lkcnt_[3]++;
    }
  }
  sort(lk[0], lk[0] + lkcnt[0]);
  sort(lk[1], lk[1] + lkcnt[1]);
  sort(lk[2], lk[2] + lkcnt[2]);
  sort(lk[3], lk[3] + lkcnt[3]);
  long long sum = 0;
  for (int i = 0; i < 4; i++) {
    int i2 = (i + 2) % 4;
    int i1 = (i + 1) % 4;
    for (int j = 0; j < lkcnt[i]; j++) {
      int l = lower_bound(lk[i2], lk[i2] + lkcnt[i2], lk[i][j].inv()) - lk[i2];
      int r = upper_bound(lk[i2], lk[i2] + lkcnt[i2], lk[i][j].inv()) - lk[i2];
      if (r < lkcnt[i2] && lk[i][j].inv() == lk[i2][r]) r++;
      sum += 1ll * l * (lkcnt[i2] - r);
      int x = lk[i][j].a;
      int y = lk[i][j].b;
      sum += 1ll * l * lkcnt[i1];
      if (i == 0 && y == 0) {
        sum -= 1ll * l * lkcnt_[2];
      }
      if (i == 0 && x == 0) {
        sum -= 1ll * (lkcnt[2] - r) * lkcnt_[3];
      }
      if (i == 3 && x == 0) {
        sum -= 1ll * l * lkcnt_[0];
      }
      if (i == 1 && y == 0) {
        sum -= 1ll * (lkcnt[3] - r) * lkcnt_[1];
      }
    }
  }
  cout << sum << endl;
  return 0;
}
