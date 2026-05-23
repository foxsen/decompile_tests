#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const long long INF = 1000000007;
template <class T>
void byebye(T _rpl) {
  cout << _rpl << endl;
  exit(0);
}
int nextint() {
  int x;
  scanf("%d", &x);
  return x;
}
long long nextll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
template <class T>
T emax(T& t1, T t2) {
  if (t1 < t2) t1 = t2;
  return t1;
}
template <class T>
T emin(T& t1, T t2) {
  if (t1 > t2) t1 = t2;
  return t1;
}
int read() {
  int f = 1, ret = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + (c - '0');
    c = getchar();
  }
  return ret * f;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x < 10) {
    putchar(x + 48);
    return;
  }
  write(x / 10);
  putchar(x % 10 + 48);
}
int n;
int sum[maxn];
int val[maxn];
int a[maxn];
int query(int x) {
  if (x == 0) return sum[x];
  int ret = 0;
  for (; x; x -= x & (-x)) ret += sum[x];
  return ret;
}
void modify(int x, int val) {
  if (x == 0) {
    sum[x] += val;
    return;
  }
  for (; x <= n; x += x & (-x)) sum[x] += val;
}
long long fastmp(long long b, int x) {
  if (x == 0) return 1ll;
  long long t = fastmp(b, x / 2);
  if (x & 1)
    return 1ll * t * t % INF * b % INF;
  else
    return 1ll * t * t % INF;
}
long long fastp(long long b, int x) {
  if (x == 0) return 1ll;
  long long t = fastp(b, x >> 1);
  if (x & 1)
    return 1ll * t * t * b;
  else
    return 1ll * t * t;
}
int main() {
  int t = read();
  while (t--) {
    int n = read(), p = read();
    long long x = 1;
    int lg = 0;
    if (p != 1)
      while (x < 1e6) lg++, x *= p;
    else
      lg = 1e6;
    vector<pair<int, int> > F, S;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      a[i] = read();
      val[a[i]]++;
      v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int L = v.size();
    int lp = L - 1;
    for (int rr = L - 1; rr >= 0;) {
      int r = v[rr];
      if (val[r] <= 0) {
        --rr;
        continue;
      }
      if (val[r] % 2 == 0) {
        val[r] = 0;
        --rr;
        continue;
      }
      val[r] = 0;
      for (; lp >= 0; --lp)
        if (val[v[lp]] != 0) break;
      if (lp < 0) {
        F.push_back(pair<int, int>(r, 1));
        break;
      }
      long long need = r - v[lp];
      bool flag = true;
      if (need > lg) {
        F.push_back(pair<int, int>(r, 1));
        break;
      }
      need = fastp(p, need);
      int s = lp;
      for (; lp >= 0 && flag; --lp) {
        if (need > 1e6) {
          flag = false;
          break;
        }
        if (need <= val[v[lp]]) {
          val[v[lp]] -= need;
          break;
        }
        need -= val[v[lp]];
        if (lp != 0) {
          if (v[lp] - v[lp - 1] > lg) {
            flag = false;
          } else
            need *= fastp(p, v[lp] - v[lp - 1]);
        }
      }
      if (lp < 0 || !flag) {
        F.push_back(pair<int, int>(r, 1));
        break;
      }
      for (int j = lp + 1; j <= s; ++j) val[v[j]] = 0;
      r = lp;
    }
    for (int i = 0; i < L; ++i)
      if (val[v[i]]) S.push_back(pair<int, int>(v[i], val[v[i]]));
    long long s1 = 0, s2 = 0;
    for (pair<int, int> v1 : F) {
      s1 += fastmp(p, v1.first) * v1.second % INF;
      s1 %= INF;
    }
    for (pair<int, int> v2 : S) {
      s2 += fastmp(p, v2.first) * v2.second % INF;
      s2 %= INF;
    }
    s1 -= s2;
    if (s1 < 0) s1 += INF;
    printf("%d\n", s1);
    for (int i = 0; i < n; ++i) {
      val[a[i]] = 0;
    }
  }
  return 0;
}
