#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
int N, n, SA[3003], lcp[3003], arr[3003], rsa[3003];
long long D[3003][3003], T[3003];
char S[3003];
void SuffixArray() {
  int i, j, k;
  int m = 2;
  vector<int> cnt(max(N, m) + 1, 0), first(N + 1, 0), second(N + 1, 0);
  for (i = 1; i <= N; i++) cnt[first[i] = S[i] - 'a' + 1]++;
  for (i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (i = N; i; i--) SA[cnt[first[i]]--] = i;
  for (int len = 1, p = 1; p < N; len <<= 1, m = p) {
    for (p = 0, i = N - len; ++i <= N;) second[++p] = i;
    for (i = 1; i <= N; i++)
      if (SA[i] > len) second[++p] = SA[i] - len;
    for (i = 0; i <= m; i++) cnt[i] = 0;
    for (i = 1; i <= N; i++) cnt[first[second[i]]]++;
    for (i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (i = N; i; i--) SA[cnt[first[second[i]]]--] = second[i];
    swap(first, second);
    p = 1;
    first[SA[1]] = 1;
    for (i = 1; i < N; i++)
      first[SA[i + 1]] = SA[i] + len <= N && SA[i + 1] + len <= N &&
                                 second[SA[i]] == second[SA[i + 1]] &&
                                 second[SA[i] + len] == second[SA[i + 1] + len]
                             ? p
                             : ++p;
  }
}
void LCP() {
  int i, j, k = 0;
  vector<int> rank(N + 1, 0);
  for (i = 1; i <= N; i++) rank[SA[i]] = i;
  for (i = 1; i <= N; lcp[rank[i++]] = k)
    for (k ? k-- : 0, j = SA[rank[i] - 1]; S[i + k] == S[j + k]; k++)
      ;
}
char bstr[4][5] = {"0011", "0101", "1110", "1111"};
bool bad(int s, int e) {
  int i, j;
  for (j = 0; j < 4; j++) {
    for (i = s; i <= e; i++)
      if (bstr[j][i - s] - '0' != arr[i]) break;
    if (i == e + 1) return 1;
  }
  return 0;
}
int rns[3003];
int fin(int idx) {
  int i, p;
  for (i = 1; i <= n; i++)
    if (SA[i] == idx) break;
  p = i;
  int t = lcp[p];
  for (i = p - 1; i; i--) {
    rns[SA[i]] = t;
    t = min(t, lcp[i]);
  }
  t = lcp[p + 1];
  for (i = p + 1; i <= n; i++) {
    rns[SA[i]] = t;
    t = min(t, lcp[i + 1]);
  }
  int maxi = 0;
  for (i = 1; i < idx; i++) {
    maxi = max(maxi, rns[i]);
  }
  return idx - maxi;
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  N = n;
  for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
  for (i = n; i > 0; i--) S[n + 1 - i] = 'a' + arr[i];
  SuffixArray();
  LCP();
  for (i = 1; i <= n; i++) SA[i] = n + 1 - SA[i];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      for (k = 0; k <= 3 && k < i; k++) {
        if (k == 3 && bad(i - k, i)) continue;
        D[i][j] = (D[i][j] + D[i - k - 1][min(j, i - k - 1)]) % MOD;
        if (i - k <= j) D[i][j]++;
      }
    }
    int t = fin(i);
    T[i] = (T[i - 1] + D[i][t]) % MOD;
    printf("%lld\n", T[i]);
  }
  return 0;
}
