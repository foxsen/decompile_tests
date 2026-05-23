#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline T max1(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T max1(T a, T b, T c) {
  return max1(max1(a, b), c);
}
template <class T>
inline T max1(T a, T b, T c, T d) {
  return max1(max1(a, b, c), d);
}
template <class T>
inline T max1(T a, T b, T c, T d, T e) {
  return max1(max1(a, b, c, d), e);
}
template <class T>
inline T min1(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T min1(T a, T b, T c) {
  return min1(min1(a, b), c);
}
template <class T>
inline T min1(T a, T b, T c, T d) {
  return min1(min1(a, b, c), d);
}
template <class T>
inline T min1(T a, T b, T c, T d, T e) {
  return min1(min1(a, b, c, d), e);
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / abs1(a) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
const int mod = 1000000007;
const int maxn = 100100;
int n, arr[maxn], nxt[maxn], wh[maxn], rn;
vector<int> lian;
int nlian, n1huan, maxhuan, n2huan;
bool f[maxn];
long long fac[20];
long long sum[1 << 13], cnt[maxn];
vector<long long> ge[maxn], invge[maxn];
long long ans, tempans;
int op[maxn], lop, tempcnt[maxn];
inline long long justdoit(int n) {
  if (n == 2) return 1;
  if (n & 1) return n;
  return n;
}
void dfs(int mask, long long rrans = 1) {
  if (mask == (1 << nlian) - 1) {
    int maxop = maxhuan;
    for (int i = 0; i < lop; i++) {
      maxop = max(op[i], maxop);
    }
    if (maxop <= 2)
      ans += rrans;
    else {
      long long rans = tempans;
      for (int i = 0; i < lop; i++) {
        rans *= invge[op[i]][cnt[op[i]]] *
                ge[op[i]][cnt[op[i]] + tempcnt[op[i]]] % mod;
        rans %= mod;
      }
      ans += rans * rrans % mod;
    }
    ans %= mod;
    return;
  }
  int rmask = 1 << nlian;
  rmask -= mask + 1;
  for (int j = rmask; j >= 1 << (bitmaxl(rmask) - 1); j = (j - 1) & rmask) {
    long long tans = rrans * fac[bitnum(j) - 1] % mod;
    tempcnt[sum[j]]++;
    if (tempcnt[sum[j]] == 1) op[lop++] = sum[j];
    dfs(mask + j, tans);
    tempcnt[sum[j]]--;
    if (tempcnt[sum[j]] == 0) lop--;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &rn);
  memset(wh, -1, sizeof(wh));
  fac[0] = 1;
  for (int i = 1; i < 20; i++) fac[i] = fac[i - 1] * i % mod;
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    arr[i]--;
    if (arr[i] >= 0) wh[arr[i]] = i;
  }
  for (int i = 0; i < n; i++)
    if (wh[i] == -1) {
      int cnt = 0;
      f[i] = 1;
      for (int j = i; j != -1; j = arr[j], cnt++, f[j] = 1)
        ;
      lian.push_back(cnt);
      nlian++;
    }
  for (int i = 0; i < n; i++)
    if (f[i] == 0) {
      int rcnt = 0;
      for (int j = i; !f[j]; f[j] = 1, j = arr[j], rcnt++)
        ;
      maxhuan = max(maxhuan, rcnt);
      cnt[rcnt]++;
    }
  for (int i = 0; i < 1 << nlian; i++) {
    for (int j = 0; j < nlian; j++)
      if (i & (1 << j)) sum[i] += lian[j];
  }
  for (int i = 1; i <= n; i++) {
    ge[i].reserve(cnt[i] + max(nlian, 10) + 1);
    invge[i].reserve(cnt[i] + max(nlian, 10) + 1);
    ge[i].push_back(1);
    ge[i].push_back(i);
    invge[i].push_back(1);
    invge[i].push_back(pow(i, mod - 2, mod));
    for (int j = 2; j <= cnt[i] + max(nlian, 10); j++) {
      ge[i].push_back(ge[i][j - 2] * (j - 1) % mod * i % mod +
                      ge[i][j - 1] * i % mod);
      ge[i][j] %= mod;
      invge[i].push_back(pow(ge[i][j], mod - 2, mod));
    }
  }
  tempans = 1;
  for (int i = 1; i <= n; i++)
    if (cnt[i]) {
      tempans = tempans * ge[i][cnt[i]] % mod;
    }
  dfs(0, 1);
  cout << ans << endl;
  return 0;
}
