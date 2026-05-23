#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 1e6 + 10;
map<int, int> mpc, mpk;
bool p[N];
vector<pair<int, int> > fact[N];
int main() {
  for (int i = 2; i < N; i++) {
    if (!p[i]) {
      fact[i].push_back({i, 1});
      for (int j = i + i; j < N; j += i) {
        p[j] = true;
        int k = j, cnt = 0;
        while (k % i == 0) {
          k /= i;
          cnt++;
        }
        fact[j].push_back({i, cnt});
      }
    }
  }
  int n, k;
  scanf("%d %d", &n, &k);
  for (auto it : fact[k]) mpk[it.first] = it.second;
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    for (auto it : fact[c]) {
      mpc[it.first] = max(mpc[it.first], it.second);
    }
  }
  for (auto it = mpk.begin(); it != mpk.end(); it++) {
    if (it->second > mpc[it->first]) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
