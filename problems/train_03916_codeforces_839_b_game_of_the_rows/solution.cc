#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int OO = 0x3f3f3f3f;
const double EPS = 1e-6;
const long long MOD = 998244353;
const int off = 3 * 1e9;
int n, k, sum, arr[MAX];
int32_t main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> arr[i];
  int four = n, two = 2 * n;
  for (int i = 0; i < k; i++) {
    while (arr[i] >= 4 and four > 0) arr[i] -= 4, four--;
  }
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    while (arr[i] >= 2 and four > 0) arr[i] -= 2, four--, cnt++;
  }
  for (int i = 0; i < k; i++) {
    while (arr[i] >= 2 and two > 0) arr[i] -= 2, two--;
  }
  for (int i = 0; i < k; i++) {
    while (arr[i] >= 1 and two > 0) arr[i]--, two--;
  }
  four *= 2;
  four += cnt;
  for (int i = 0; i < k; i++) {
    while (arr[i] >= 1 and four > 0) arr[i]--, four--;
  }
  for (int i = 0; i < k; i++)
    if (arr[i] > 0) return puts("NO"), 0;
  puts("YES");
  return 0;
}
