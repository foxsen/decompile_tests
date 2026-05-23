#include <bits/stdc++.h>
using namespace std;
int spf[30000005];
int idx[30000005];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < 30000005; i++) spf[i] = i;
  for (int i = 4; i < 30000005; i += 2) spf[i] = 2;
  for (int i = 3; i * i < 30000005; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < 30000005; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
int gf(int x) {
  int ans = 1;
  int mi = 1e9;
  while (x != 1) {
    ans *= spf[x];
    mi = min(mi, spf[x]);
    x /= spf[x];
  }
  return ans / mi;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  srand(time(NULL));
  sieve();
  int q = 0;
  for (int i = 2; i < 30000005; i++) {
    if (i == spf[i]) {
      q++;
      idx[i] = q;
    } else
      idx[i] = -1;
  }
  int n;
  cin >> n;
  vector<int> b, a;
  map<int, int> mp;
  for (int i = 0; i < 2 * n; i++) {
    int z;
    cin >> z;
    b.push_back(z);
    mp[z]++;
  }
  sort(b.begin(), b.end());
  for (int i = 2 * n - 1; i >= 0; i--) {
    int gc = gf(b[i]);
    if (!mp[b[i]]) continue;
    if (spf[b[i]] == b[i] && idx[b[i]] != -1 && spf[idx[b[i]]] == idx[b[i]] &&
        mp[idx[b[i]]]) {
      a.push_back(idx[b[i]]);
      mp[idx[b[i]]]--;
      mp[b[i]]--;
    } else if (spf[b[i]] != b[i] && mp[gc]) {
      mp[b[i]]--;
      mp[gc]--;
      a.push_back(b[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
}
