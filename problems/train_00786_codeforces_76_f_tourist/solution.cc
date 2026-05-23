#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> A[100100];
long long B[100100];
long long S[4 * 100100];
int dp[100100];
map<long long, long long> X, Y;
int query(int x, int l, int r, int i, int j) {
  if ((j < l) or (r < i)) return -1e9;
  if ((i <= l) and (r <= j)) return S[x];
  int mid = (l + r) / 2;
  int a = query(x * 2, l, mid, i, j), b = query(x * 2 + 1, mid + 1, r, i, j);
  return (((a) > (b)) ? (a) : (b));
}
void update(int x, int l, int r, int p, int v) {
  if (l == r) {
    S[x] = (((S[x]) > (v)) ? (S[x]) : (v));
    return;
  }
  int mid = (l + r) / 2;
  (p <= mid) ? update(x * 2, l, mid, p, v)
             : update(x * 2 + 1, mid + 1, r, p, v);
  S[x] = (((S[x * 2]) > (S[x * 2 + 1])) ? (S[x * 2]) : (S[x * 2 + 1]));
}
int main() {
  int n;
  scanf("%d", &n);
  long long x, t;
  for (int i = (1); i <= (n); i++) {
    scanf("%lld", &A[i].first);
    scanf("%lld", &A[i].second);
  }
  n++;
  A[n].first = 0;
  A[n].second = 0;
  int V;
  scanf("%d", &V);
  for (int i = (1); i <= (n); i++) {
    x = A[i].first;
    t = A[i].second;
    A[i].first = x + t * V;
    A[i].second = t * V - x;
  }
  sort(A + 1, A + n + 1);
  int x0, y0;
  X = *new map<long long, long long>();
  Y = *new map<long long, long long>();
  int idx = 0;
  for (int i = (1); i <= (n); i++) {
    B[i] = A[i].first;
  }
  for (int i = (1); i <= (n); i++) {
    if (X.count(B[i]) == 0) {
      idx++;
      X[B[i]] = idx;
      if (B[i] == 0) x0 = idx;
    }
  }
  idx = 0;
  for (int i = (1); i <= (n); i++) {
    B[i] = A[i].second;
  }
  sort(B + 1, B + n + 1);
  for (int i = (1); i <= (n); i++) {
    if (Y.count(B[i]) == 0) {
      idx++;
      Y[B[i]] = idx;
      if (B[i] == 0) y0 = idx;
    }
  }
  for (int i = (1); i <= (n); i++) {
    A[i] = make_pair(X[A[i].first], Y[A[i].second]);
  }
  for (int i = (1); i < (4 * 100100); i++) S[i] = 0;
  for (int i = (n); i >= (1); i--) {
    dp[i] = 1 + query(1, 1, n, A[i].second, n);
    update(1, 1, n, A[i].second, dp[i]);
  }
  int a1 = 0, a2 = 0;
  for (int i = (1); i <= (n); i++) {
    if ((A[i].first == x0) and (A[i].second == y0)) {
      a1 = dp[i];
      a2 = (((a2) > (dp[i] - 1)) ? (a2) : (dp[i] - 1));
    } else {
      a2 = (((a2) > (dp[i])) ? (a2) : (dp[i]));
    }
  }
  printf("%d", a1 - 1);
  printf("\n");
  printf("%d", a2);
  printf("\n");
}
