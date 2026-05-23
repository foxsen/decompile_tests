#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 998244353

string S;
map<string, int> memo;
int f(string S) {
  if (memo.find(S) != memo.end()) return memo[S];
  int s = ((S[0]-'0')+1)*f(S.substr(1));
  for (int k=1; 2*k<=S.length(); k++) {
    string p(k, '1');
    rep(i, k) if (S[i] == '0') p[i] = '0';
    for (int t=k; t+k<=S.length(); t+=k) {
      rep(i, k) if (S[t+i] == '0') p[i] = '0';
      s = (s + 1LL*f(p)*f(S.substr(t+k))) % MOD;
    }
  }
  return memo[S] = s;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  memo[""] = 1;
  cin >> S;
  cout << f(S) << "\n";
  return 0;
}
