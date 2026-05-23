#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int N;
int mus[3];
int T[200100];
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  cin >> N;
  for (int(i) = 0; (i) < (3); (i)++) cin >> mus[i];
  sort(mus, mus + 3);
  int a = mus[0];
  int b = mus[1];
  int c = mus[2];
  multiset<int, greater<int> > ms;
  for (int(i) = 0; (i) < (N); (i)++) cin >> T[i], ms.insert(T[i]);
  if (a + b + c < *ms.begin()) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 0;
  while (int((ms).size()) > 0 && *ms.begin() > c + b) {
    ms.erase(ms.begin());
    ans++;
  }
  while (int((ms).size()) > 0 && *ms.begin() > c + a) {
    ms.erase(ms.begin());
    if (ms.lower_bound(a) != ms.end()) {
      ms.erase(ms.lower_bound(a));
    }
    ans++;
  }
  while (int((ms).size()) > 0 && *ms.begin() > max(a + b, c)) {
    ms.erase(ms.begin());
    if (ms.lower_bound(b) != ms.end()) {
      ms.erase(ms.lower_bound(b));
    }
    ans++;
  }
  if (a + b > c) {
    while (int((ms).size()) > 0 && *ms.begin() > c) {
      ms.erase(ms.begin());
      if (ms.lower_bound(c) != ms.end()) {
        ms.erase(ms.lower_bound(c));
      }
      ans++;
    }
  }
  while (int((ms).size()) > 0) {
    ans++;
    ms.erase(ms.begin());
    if (ms.lower_bound(b) != ms.end()) {
      ms.erase(ms.lower_bound(b));
      if (ms.lower_bound(a) != ms.end()) {
        ms.erase(ms.lower_bound(a));
      }
    } else {
      if (ms.lower_bound(a + b) != ms.end()) {
        ms.erase(ms.lower_bound(a + b));
      }
    }
  }
  cout << ans << '\n';
}
