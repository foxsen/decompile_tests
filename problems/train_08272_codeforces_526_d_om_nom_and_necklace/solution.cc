#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int N, K;
string s;
int ans[1001001];
int z[1001001];
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  cin >> N >> K >> s;
  int L = 0, R = 0;
  for (int i = 1; i < N; i++) {
    if (i > R) {
      L = R = i;
      while (R < N && s[R - L] == s[R]) R++;
      z[i] = R - L;
      R--;
    } else {
      int k = i - L;
      if (z[k] < R - i + 1) {
        z[i] = z[k];
      } else {
        L = i;
        while (R < N && s[R - L] == s[R]) R++;
        z[i] = R - L;
        R--;
      }
    }
  }
  for (int lenAB = 1; lenAB <= N; lenAB++) {
    int all = 1;
    int cur = lenAB;
    for (int(i) = 0, j123 = K - 1; (i) < j123; (i)++) {
      if (cur >= N) {
        all = 0;
        break;
      }
      if (cur + lenAB - 1 < N) {
        all &= (z[cur] >= lenAB);
      } else {
        all &= (z[cur] == N - cur);
      }
      cur += lenAB;
    }
    if (lenAB == 2) {
    }
    if (all) {
      int l = lenAB * K - 1;
      int r = l + min(lenAB, z[K * lenAB]);
      if (l < N) {
        ans[l]++;
        ans[min(N, r) + 1]--;
      }
    }
  }
  for (int(i) = 0, j123 = N; (i) < j123; (i)++)
    if (i >= 1) ans[i] += ans[i - 1];
  for (int(i) = 0, j123 = N; (i) < j123; (i)++) cout << (ans[i] > 0);
  cout << '\n';
}
