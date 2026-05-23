#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline long long inc(int &x) { return ++x; }
inline long long inc(long long &x) { return ++x; }
inline long long inc(int &x, long long y) { return x += y; }
inline long long inc(long long &x, long long y) { return x += y; }
inline double inc(double &x, double y) { return x += y; }
inline long long dec(int &x) { return --x; }
inline long long dec(long long &x) { return --x; }
inline long long dec(int &x, long long y) { return x -= y; }
inline long long dec(long long &x, long long y) { return x -= y; }
inline double dec(double &x, double y) { return x -= y; }
inline long long mul(int &x) { return x = ((long long)x) * x; }
inline long long mul(long long &x) { return x = x * x; }
inline long long mul(int &x, long long y) { return x *= y; }
inline long long mul(long long &x, long long y) { return x *= y; }
inline double mul(double &x, double y) { return x *= y; }
inline long long divi(const int &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(const long long &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(int &x, long long y) { return x /= y; }
inline long long divi(long long &x, long long y) { return x /= y; }
inline double divi(double &x, double y) { return x /= y; }
inline long long mod(int &x, long long y) { return x %= y; }
inline long long mod(long long &x, long long y) { return x %= y; }
struct matrix {
  double a[205][205];
} f[17];
long long n, m, i, j, k, px[205], py[205], x, y;
matrix mul(matrix x, matrix y) {
  int i, j, k;
  matrix ans;
  memset((ans.a), (0), (sizeof((ans.a))));
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++)
      if ((1) <= ((n)))
        for (((j)) = (1); ((j)) <= ((n)); ((j))++)
          if ((1) <= ((n)))
            for (((k)) = (1); ((k)) <= ((n)); ((k))++)
              ans.a[i][j] += x.a[i][k] * y.a[k][j];
  return ans;
}
double cnt[205], g[2][205];
vector<vector<long long> > lne;
void ind() {
  cin >> n;
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) cin >> px[i] >> py[i];
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++)
      if ((1) <= ((i - 1)))
        for (((j)) = (1); ((j)) <= ((i - 1)); ((j))++) {
          long long dx = px[i] - px[j], dy = py[i] - py[j];
          vector<long long> tis;
          if ((1) <= ((n)))
            for (((k)) = (1); ((k)) <= ((n)); ((k))++) {
              if ((px[i] - px[k]) * dy == (py[i] - py[k]) * dx) {
                tis.push_back(k);
              }
            }
          if (tis.size() >= 2) lne.push_back(tis);
        }
  stable_sort(lne.begin(), lne.end());
  lne.resize(unique(lne.begin(), lne.end()) - lne.begin());
  for (__typeof((lne).begin()) it = (lne).begin(); it != (lne).end(); it++) {
    for (__typeof((*it).begin()) it2 = (*it).begin(); it2 != (*it).end(); it2++)
      cnt[*it2] += 1.0;
  }
  for (__typeof((lne).begin()) it = (lne).begin(); it != (lne).end(); it++) {
    for (__typeof((*it).begin()) it2 = (*it).begin(); it2 != (*it).end();
         it2++) {
      for (__typeof((*it).begin()) it3 = (*it).begin(); it3 != (*it).end();
           it3++) {
        f[0].a[*it2][*it3] += 1.0 / cnt[*it2] / it->size();
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  ind();
  if ((1) <= ((15)))
    for (((i)) = (1); ((i)) <= ((15)); ((i))++) f[i] = mul(f[i - 1], f[i - 1]);
  cin >> m;
  while (m--) {
    cin >> y >> x;
    memset((g), (0), (sizeof((g))));
    g[0][y] = 1;
    x--;
    int z = 0;
    if ((0) <= (15))
      for ((i) = (0); (i) <= (15); (i)++) {
        if ((x >> i) & 1) {
          z ^= 1;
          memset((g[z]), (0), (sizeof((g[z]))));
          if ((1) <= ((n)))
            for (((j)) = (1); ((j)) <= ((n)); ((j))++)
              if ((1) <= ((n)))
                for (((k)) = (1); ((k)) <= ((n)); ((k))++)
                  g[z][j] += g[!z][k] * f[i].a[j][k];
        }
      }
    double res = 0;
    for (__typeof((lne).begin()) it = (lne).begin(); it != (lne).end(); it++) {
      double sum = 0;
      for (__typeof((*it).begin()) it2 = (*it).begin(); it2 != (*it).end();
           it2++) {
        sum += g[z][*it2];
      }
      sum /= it->size();
      res = max(res, sum);
    }
    printf("%.50f\n", res);
  }
  return 0;
}
