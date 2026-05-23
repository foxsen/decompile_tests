#include <bits/stdc++.h>
using namespace std;
struct IOReader {
  template <typename T>
  inline IOReader& operator>>(T& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = (a << 3) + (a << 1) + (ch ^ '0');
      ch = getchar();
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(string& a) {
    a.clear();
    char ch = getchar();
    while (isspace(ch) && ch != EOF) ch = getchar();
    while (!isspace(ch) && ch != EOF) a += ch, ch = getchar();
    return *this;
  }
  inline IOReader& operator>>(char* a) {
    scanf(" %s", a);
    return *this;
  }
  inline IOReader& operator>>(char& a) {
    a = getchar();
    while (isspace(a)) a = getchar();
    return *this;
  }
  inline IOReader& operator>>(float& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      float p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(double& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      double p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
  inline IOReader& operator>>(long double& a) {
    a = 0;
    bool flg = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '.') {
      if (ch == '-') flg ^= 1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      a = a * 10 + (ch ^ '0');
      ch = getchar();
    }
    if (ch == '.') {
      ch = getchar();
      long double p = 0.1;
      while (ch >= '0' && ch <= '9') {
        a += p * (ch ^ '0');
        ch = getchar();
        p *= 0.1;
      }
    }
    if (flg) a = -a;
    return *this;
  }
} iocin;
int readInt() {
  int a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned int readUInt() {
  unsigned int a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
long long readLL() {
  long long a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned long long readULL() {
  unsigned long long a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
short readShort() {
  short a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
unsigned short readUShort() {
  unsigned short a = 0;
  bool flg = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = (a << 3) + (a << 1) + (ch ^ '0');
    ch = getchar();
  }
  if (flg) a = -a;
  return a;
}
float readFL() {
  float a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    float p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
double readDB() {
  double a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    double p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
long double readLDB() {
  long double a = 0;
  bool flg = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '.') {
    if (ch == '-') flg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + (ch ^ '0');
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    long double p = 0.1;
    while (ch >= '0' && ch <= '9') {
      a += p * (ch ^ '0');
      ch = getchar();
      p *= 0.1;
    }
  }
  if (flg) a = -a;
  return a;
}
inline void yOn(bool x) { printf("%s", (x) ? "Yes" : "No"); }
inline void yOn(bool x, char* str) { printf("%s%s", (x) ? "Yes" : "No", str); }
inline void yOn(bool x, const char* str) {
  printf("%s%s", (x) ? "Yes" : "No", str);
}
inline void yOn(bool x, string str) {
  printf("%s%s", (x) ? "Yes" : "No", str.c_str());
}
inline void YON(bool x) { printf("%s", (x) ? "YES" : "NO"); }
inline void YON(bool x, char* str) { printf("%s%s", (x) ? "YES" : "NO", str); }
inline void YON(bool x, const char* str) {
  printf("%s%s", (x) ? "YES" : "NO", str);
}
inline void YON(bool x, string str) {
  printf("%s%s", (x) ? "YES" : "NO", str.c_str());
}
const int N = 305;
const int M = N * N;
int n, m;
int len;
pair<pair<int, int>, int> x[M];
int y[N][N];
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.first.first == b.first.first ? a.first.second < b.first.second
                                        : a.first.first < b.first.first;
}
bool Cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.first.second < b.first.second;
}
struct BIT {
  int sz;
  int t[N];
  void init() {
    sz = m + 1;
    for (int i = (0); i <= (sz); ++i) t[i] = 0;
  }
  int lowbit(int x) { return x & (-x); }
  void upd(int x, int v) {
    while (x <= sz) t[x] += v, x += lowbit(x);
  }
  int qry(int x) {
    int ret = 0;
    while (x) ret += t[x], x -= lowbit(x);
    return ret;
  }
} tr[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long ans = 0;
    iocin >> n >> m;
    len = n * m;
    for (int i = (1); i <= (n); ++i) {
      tr[i].init();
    }
    for (int i = (1); i <= (len); ++i) {
      cin >> x[i].first.first;
      x[i].first.second = i;
    }
    sort(x + 1, x + len + 1, cmp);
    for (int i = (1); i <= (len); ++i) x[i].second = i;
    sort(x + 1, x + len + 1, Cmp);
    for (int i = (1); i <= (len); ++i) {
      int X = (x[i].second - 1) / m + 1, Y = (x[i].second - 1) % m + 1;
      y[X][Y] = x[i].first.first;
      ans += tr[X].qry(Y);
      tr[X].upd(Y, 1);
    }
    for (int i = (1); i <= (len); ++i) {
      int X = (x[i].second - 1) / m + 1, Y = (x[i].second - 1) % m + 1;
      tr[X].upd(Y, -1);
    }
    for (int i = (1); i <= (n); ++i) {
      int nw = 0, len = 0;
      y[i][m + 1] = -1;
      for (int j = (1); j <= (m + 1); ++j)
        if (y[i][j] != nw) {
          ans -= 1ll * len * (len - 1) / 2;
          len = 1, nw = y[i][j];
        } else
          ++len;
    }
    cout << ans << endl;
  }
  return 0;
}
