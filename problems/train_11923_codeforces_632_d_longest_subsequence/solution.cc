#include <bits/stdc++.h>
using namespace std;
void make_unique(vector<int> &a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
int Set(int N, int cur) { return N = N | (1 << cur); }
int Reset(int N, int cur) { return N = N & ~(1 << cur); }
bool Check(int N, int cur) { return (bool)(N & (1 << cur)); }
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
long long LCM(long long a, long long b) { return a * b / GCD(a, b); }
long long POW(long long a, long long p) {
  long long res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x);
    x = (x * x);
    p >>= 1;
  }
  return res;
}
int N, M;
int A[1000005];
int cnt[1000005];
int DP[1000005];
void solve() {
  for (int i = 1; i <= M; i++) {
    cnt[i] = DP[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    if (A[i] <= M) cnt[A[i]]++;
  }
  int lcm = 1, mxLen = 0;
  for (int d = 1; d <= M; d++) {
    for (int v = d; v <= M; v += d) {
      DP[v] += cnt[d];
      if (DP[v] > mxLen) {
        lcm = v;
        mxLen = DP[v];
      } else if (DP[v] == mxLen) {
        if (v < lcm) lcm = v;
      }
    }
  }
  printf("%d %d\n", lcm, mxLen);
  bool f = false;
  if (mxLen == 0) return;
  for (int i = 0; i < N; i++) {
    if (lcm % A[i] == 0) {
      if (f == false) {
        f = true;
        printf("%d", i + 1);
      } else {
        printf(" %d", i + 1);
      }
    }
  }
  printf("\n");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  solve();
}
