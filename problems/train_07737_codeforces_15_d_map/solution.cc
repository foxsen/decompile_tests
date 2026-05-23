#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T& x) {
  return x * x;
}
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-11;
const int z = 1 << 10;
int x, y, n, m;
int a[1024][1024];
signed long long s[1024][1024];
signed long long e[1024 * 1024];
int p[1024 * 1024][2];
int ind[1024 * 1024];
int t[1 << 11][1 << 11];
bool u[1 << 10][1 << 10];
int ans;
signed long long ansp[1024000][4];
char anss[20400800];
int tminy(int x, int yl, int yr) {
  yl += z;
  yr += z;
  int ans = 0x3f3f3f3f;
  while (yl < yr - 3) {
    ans = min(ans, t[x][yl]);
    ans = min(ans, t[x][yr]);
    yl = (yl + 1) >> 1;
    yr = (yr - 1) >> 1;
  }
  for (int i = (yl); i <= (int)(yr); i++) {
    ans = min(ans, t[x][i]);
  }
  return ans;
}
int tmin(int xl, int xr, int yl, int yr) {
  xl += z;
  xr += z;
  int ans = 0x3f3f3f3f;
  while (xl <= xr) {
    if (xl & 1) ans = min(ans, tminy(xl, yl, yr));
    if (!(xr & 1)) ans = min(ans, tminy(xr, yl, yr));
    xl = (xl + 1) >> 1;
    xr = (xr - 1) >> 1;
  }
  return ans;
}
bool cmp(int p1, int p2) { return e[p1] < e[p2]; }
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  memset(t, 0x3f, sizeof(t));
  scanf("%d%d%d%d", &n, &m, &x, &y);
  bool sw = false;
  memset((a), 0, sizeof(a));
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      scanf("%d", &a[i + 1][j + 1]);
    }
  }
  if (x < y) {
    sw = true;
    swap(x, y);
    swap(n, m);
    int t = max(n, m);
    for (int i = 0; i < (int)(t + 1); i++) {
      for (int j = 0; j < (int)(i); j++) {
        swap(a[i][j], a[j][i]);
      }
    }
  }
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) {
      t[z + i + 1][z + j + 1] = a[i + 1][j + 1];
    }
  }
  for (int i = (z * 2 - 1); i >= (int)(z); i--) {
    for (int j = (z - 1); j >= (int)(1); j--) {
      t[i][j] = min(t[i][j * 2], t[i][j * 2 + 1]);
    }
  }
  for (int i = (z - 1); i >= (int)(1); i--) {
    for (int j = (z * 2 - 1); j >= (int)(1); j--) {
      t[i][j] = min(t[i * 2][j], t[i * 2 + 1][j]);
    }
  }
  memset((s), 0, sizeof(s));
  for (int i = (1); i <= (int)(n); i++) {
    for (int j = (1); j <= (int)(m); j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  }
  int k = 0;
  if (sw) {
    for (int j = (1); j <= (int)(m - y + 1); j++) {
      for (int i = (1); i <= (int)(n - x + 1); i++) {
        p[k][0] = i;
        p[k][1] = j;
        ind[k] = k;
        e[k] = s[i + x - 1][j + y - 1] - s[i - 1][j + y - 1] -
               s[i + x - 1][j - 1] + s[i - 1][j - 1] -
               (signed long long)x * y * tmin(i, i + x - 1, j, j + y - 1);
        k++;
      }
    }
  } else {
    for (int i = (1); i <= (int)(n - x + 1); i++) {
      for (int j = (1); j <= (int)(m - y + 1); j++) {
        p[k][0] = i;
        p[k][1] = j;
        ind[k] = k;
        e[k] = s[i + x - 1][j + y - 1] - s[i - 1][j + y - 1] -
               s[i + x - 1][j - 1] + s[i - 1][j - 1] -
               (signed long long)x * y * tmin(i, i + x - 1, j, j + y - 1);
        k++;
      }
    }
  }
  memset((u), 0, sizeof(u));
  stable_sort(ind, ind + k, cmp);
  for (int l1 = 0; l1 < (int)(k); l1++) {
    int l = ind[l1];
    int i = p[l][0];
    int j = p[l][1];
    if (!u[i][j] && !u[i + x - 1][j] && !u[i][j + y - 1] &&
        !u[i + x - 1][j + y - 1]) {
      for (int i1 = 0; i1 < (int)(x); i1++) {
        for (int j1 = 0; j1 < (int)(y); j1++) {
          u[i + i1][j + j1] = true;
        }
      }
      ansp[ans][0] = i;
      ansp[ans][1] = j;
      ansp[ans][2] = e[l];
      ans++;
    }
  }
  int l = 0;
  printf("%d\n", ans);
  char t[20];
  for (int i = 0; i < (int)(ans); i++) {
    if (sw) swap(ansp[i][0], ansp[i][1]);
    int ll = 0;
    int x = ansp[i][0];
    do {
      t[ll++] = x % 10 + '0';
      x /= 10;
    } while (x);
    for (int j = (ll)-1; j >= 0; j--) {
      anss[l++] = t[j];
    }
    anss[l++] = ' ';
    ll = 0;
    x = ansp[i][1];
    do {
      t[ll++] = x % 10 + '0';
      x /= 10;
    } while (x);
    for (int j = (ll)-1; j >= 0; j--) {
      anss[l++] = t[j];
    }
    anss[l++] = ' ';
    ll = 0;
    signed long long y = ansp[i][2];
    do {
      t[ll++] = y % 10 + '0';
      y /= 10;
    } while (y);
    for (int j = (ll)-1; j >= 0; j--) {
      anss[l++] = t[j];
    }
    anss[l++] = '\n';
  }
  anss[l - 1] = '\0';
  puts(anss);
  return 0;
}
