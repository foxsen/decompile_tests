#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} debug1;
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  bool first = true;
  os << "[";
  for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
const int NN = 112;
int ans[NN];
void solve() {
  int n;
  long long int m;
  cin >> n >> m;
  long long cnt = n - 2;
  int st = 0, en = n - 1;
  for (int i = 1; st <= en; ++i) {
    long long ob = 1LL << cnt;
    if (m > ob) {
      ans[en--] = i;
      m -= ob;
    } else
      ans[st++] = i;
    cnt--;
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  solve();
  return 0;
}
