#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long int lxt() {
  long long int aaa;
  scanf("%lld", &aaa);
  return aaa;
}
inline double dxt() {
  double aaa;
  scanf("%lf", &aaa);
  return aaa;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
long long int ar[600010];
long long int sum[600010];
long long int cum[600010];
long long int tree[600010];
void update(int pos, int limit, long long int val) {
  while (pos <= limit) {
    tree[pos] += val;
    pos += pos & (-pos);
  }
}
long long int query(int pos) {
  long long int s = 0;
  while (pos > 0) {
    s += tree[pos];
    pos -= pos & (-pos);
  }
  return s;
}
bool go(long long int mid, long long int k, int n, int r) {
  int i = 1;
  memset(cum, 0, sizeof(cum));
  while (i <= n) {
    cum[i] += cum[i - 1];
    if (sum[i] + cum[i] < mid) {
      long long int extra = mid - (sum[i] + cum[i]);
      cum[i] += extra;
      cum[min(i + 2 * r + 1, n + 1)] -= extra;
      k -= extra;
      if (k < 0) return false;
    }
    i++;
  }
  return k >= 0;
}
int main() {
  int n = nxt();
  int r = nxt();
  long long int k = lxt();
  for (int i = 1; i <= n; i++) {
    ar[i] = lxt();
  }
  for (int i = 1; i <= n; i++) {
    int le = i - r;
    int ri = i + r;
    le = max(le, 1);
    ri = min(ri, n);
    sum[le] += ar[i];
    sum[ri + 1] -= ar[i];
  }
  for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
  long long int b = 0;
  long long int e = (long long int)LLONG_MAX;
  while (b <= e) {
    long long int mid = (b + e) / 2;
    if (go(mid, k, n, r))
      b = mid + 1;
    else
      e = mid - 1;
  }
  cout << b - 1 << endl;
  return 0;
}
