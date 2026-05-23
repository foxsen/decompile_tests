#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
map<long long int, long long int> m1;
set<long long int> st;
long long int fep(long long int x, long long int y, long long int mod) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, i, m, j, k, x, y, a, b, p, sm = 0;
  string s;
  cin >> n >> p >> k;
  for (i = 0; i < n; i++) {
    cin >> x;
    a = (x * x) % p;
    a = (a * a) % p;
    a -= (k * x) % p;
    a = (a + p) % p;
    st.insert(a);
    m1[a]++;
  }
  set<long long int>::iterator it;
  for (it = st.begin(); it != st.end(); it++) {
    x = m1[*it];
    sm += (x * (x - 1)) / 2;
  }
  cout << sm;
  return 0;
}
