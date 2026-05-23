#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int Mod = 1e9 + 7;
map<long long, int> Left[26], Right[26];
int n, k, a[30];
long long sum, fact[20];
void cal(int pos, int crk, long long crSum, int last) {
  if (pos == last) {
    if (last != n)
      Left[crk][crSum]++;
    else
      Right[crk][crSum]++;
    return;
  }
  if (crk < k && a[pos] < 19) cal(pos + 1, crk + 1, crSum + fact[a[pos]], last);
  cal(pos + 1, crk, crSum + a[pos], last);
  cal(pos + 1, crk, crSum, last);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> sum;
  for (int i = 0; i < n; ++i) cin >> a[i];
  fact[0] = 1;
  for (long long i = 1; i < 20; ++i) fact[i] = i * fact[i - 1];
  cal(0, 0, 0, n / 2);
  cal(n / 2, 0, 0, n);
  long long ans = 0;
  for (int i = 0; i <= k; ++i) Left[i][0] = Right[i][0] = 1;
  for (int i = 0; i <= k; ++i) {
    for (auto j : Left[i]) {
      if (j.first == sum) {
        ans += j.second;
        continue;
      }
      if (j.first == 0) continue;
      for (int x = 0; x + i <= k; ++x) {
        if (Right[x].count(sum - j.first))
          ans += (j.second * Right[x][sum - j.first]);
      }
    }
  }
  for (int i = 0; i <= k; ++i) {
    for (auto j : Right[i]) {
      if (j.first == sum) ans += j.second;
    }
  }
  cout << ans;
}
