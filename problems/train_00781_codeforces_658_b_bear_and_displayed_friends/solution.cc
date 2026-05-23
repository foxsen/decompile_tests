#include <bits/stdc++.h>
using namespace std;
string ITS(long long x) {
  string s = "";
  while (x > 0) {
    s += (char)(x % 10 + '0');
    x /= 10;
  }
  string t = "";
  for (int i = s.size() - 1; i > -1; i--) t += s[i];
  return t;
}
long long inf = 1e9;
long long mod = 1e9 + 7;
const long long M = 2e5;
pair<long long, long long> online[M];
long long t[M];
int main() {
  cin.sync_with_stdio(false);
  long long n, k, q;
  cin >> n >> k >> q;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 0; i < q; i++) {
    long long qt, qid;
    cin >> qt >> qid;
    if (qt == 1) {
      sort(online, online + k);
      if (t[qid] > online[0].first) {
        online[0].first = t[qid];
        online[0].second = qid;
      }
    } else {
      long long i;
      for (i = 0; i < k; i++)
        if (online[i].second == qid) {
          cout << "YES\n";
          break;
        }
      if (i == k) cout << "NO\n";
    }
  }
}
