#include <bits/stdc++.h>
using namespace std;
long long n, k, i, j, sum, sm[2000000], cnt1, cnt2, ans;
pair<pair<long long, long long>, long long> p[2000000];
string s[2000000], S;
bool cmp(pair<pair<long long, long long>, long long> a,
         pair<pair<long long, long long>, long long> b) {
  if (a.first.second == 0) return 0;
  if (b.first.second == 0) return 1;
  return a.first.first * b.first.second <= b.first.first * a.first.second;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    cnt1 = cnt2 = 0;
    for (j = 0; j < s[i].size(); j++) {
      if (s[i][j] == 's')
        cnt1++;
      else
        cnt2++;
    }
    p[i] = {{cnt1, cnt2}, i};
  }
  stable_sort(p, p + n, cmp);
  for (i = n - 1; i >= 0; i--) S += s[p[i].second];
  for (i = int(S.size()) - 1; i >= 0; i--) {
    if (S[i] == 'h') sum++;
    sm[i] = sum;
  }
  sum = 0;
  for (i = 0; i < S.size(); i++) {
    if (S[i] == 's') ans += sm[i];
  }
  cout << ans;
  return 0;
}
