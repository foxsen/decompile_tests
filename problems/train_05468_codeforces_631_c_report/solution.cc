#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T MDINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
template <class T>
bool ISLEFT(T a, T b, T c) {
  if (((a.first - b.first) * (b.second - c.second) -
       (b.first - c.first) * (a.second - b.second)) < 0.0)
    return 1;
  else
    return 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n + 2];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  pair<int, int> ar[m + 2];
  int sz = 0;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    while (sz > 0 && y >= ar[sz].first) {
      sz--;
    }
    ar[++sz] = make_pair(y, x);
  }
  int ans[n + 2];
  if (sz > 0) {
    sort(a + 1, a + ar[1].first + 1);
  }
  int kol = n + 1;
  for (int j = n; j > ar[1].first; j--) {
    ans[j] = a[j];
    kol = j;
  }
  int cnt = 1;
  int st = 1;
  int en = ar[1].first;
  while (cnt < sz) {
    int x = ar[cnt].first - ar[cnt + 1].first;
    if (ar[cnt].second == 1) {
      while (x) {
        ans[--kol] = a[en--];
        x--;
      }
    } else {
      while (x) {
        ans[--kol] = a[st++];
        x--;
      }
    }
    cnt++;
  }
  if (sz != 0) {
    if (ar[sz].second == 1)
      for (int i = en; i >= st; i--) ans[--kol] = a[i];
    else
      for (int i = st; i <= en; i++) ans[--kol] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (i == n)
      printf("%d", ans[i]);
    else
      printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
