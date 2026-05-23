#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
const int N = 35010;
inline int Abs(int x) { return x > 0 ? x : -x; }
int a[N], L[N], R[N], n;
multiset<int> A, B;
int tgA, tgB;
int lp, rp, lq, rq;
long long solve() {
  long long ans = 0;
  A.clear(), B.clear(), tgA = tgB = 0;
  lp = rp = lq = rq = 0;
  A.insert(0), B.insert(0);
  for (int i = 1; i <= n; ++i) {
    {
      lp -= R[i] - a[i], lq -= R[i] - a[i], tgA -= R[i] - a[i];
      rp -= R[i] - a[i], rq -= R[i] - a[i], tgB -= R[i] - a[i];
    }
    { rp += R[i] - L[i], rq += R[i] - L[i], tgB += R[i] - L[i]; }
    {
      if (lp <= 0 && 0 <= rp) {
        A.insert(0 - tgA);
        B.insert(0 - tgB);
        lp = rp = 0;
      } else if (0 < lp) {
        ans += Abs(lp);
        B.insert(lp - tgB), rp = lp;
        if (lp != lq) {
          A.erase(A.find(lp - tgA));
          int nxt = A.size() ? (*A.rbegin() + tgA) : lq;
          lp = max(0, nxt);
          if (lp == lq) A.insert(lp - tgA);
          if (0 > lq) A.insert(0 - tgA), A.insert(0 - tgA);
        }
      } else {
        ans += Abs(rp);
        A.insert(rp - tgA), lp = rp;
        if (rp != rq) {
          B.erase(B.find(rp - tgB));
          int nxt = B.size() ? (*B.begin() + tgB) : rq;
          rp = min(0, nxt);
          if (rp == rq) B.insert(rp - tgB);
          if (0 < rq) B.insert(0 - tgB), B.insert(0 - tgB);
        }
      }
    }
  }
  if (0 < lq || 0 > rq) return 1e18;
  if (0 < lp) {
    A.insert(lq - tgA);
    long long k = 0;
    for (auto it2 = A.rbegin(), it = it2++; it2 != A.rend(); it = it2++) {
      k++;
      ans += ((*it + tgA) - max(*it2 + tgA, 0)) * k;
      if (0 >= *it2 + tgA) break;
    }
  }
  if (0 > rp) {
    B.insert(rq - tgB);
    long long k = 0;
    for (auto it2 = B.begin(), it = it2++; it2 != B.end(); it = it2++) {
      k++;
      ans += (min(*it2 + tgB, 0) - (*it + tgB)) * k;
      if (0 <= *it2 + tgB) break;
    }
  }
  return ans;
}
long long get(int x) {
  a[1] += x, a[n] -= x;
  long long tmp = solve() + Abs(x);
  a[1] -= x, a[n] += x;
  return tmp;
}
int main() {
  rd(n);
  int s = 0;
  for (int i = 1; i <= n; ++i) rd(a[i]), rd(L[i]), rd(R[i]), s += a[i];
  long long ans = 1e18;
  int L = -s, R = s;
  while (R - L + 1 > 4) {
    int m1 = L + R >> 1, m2 = m1 + 1;
    long long v1 = get(m1), v2 = get(m2);
    if (v1 < v2)
      R = m2;
    else
      L = m1;
  }
  for (int i = L; i <= R; ++i) ans = min(ans, get(i));
  printf("%lld", ans);
  return 0;
}
