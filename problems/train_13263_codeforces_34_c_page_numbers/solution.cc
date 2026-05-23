#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  set<int> s;
  string t, k;
  cin >> t;
  int jj;
  for (int i = 0; i < t.length(); i++) {
    if (t[i] != ',') {
      k += t[i];
    } else {
      jj = stoi(k);
      s.insert(jj);
      k.clear();
    }
  }
  jj = stoi(k);
  s.insert(jj);
  vector<int> v(s.begin(), s.end());
  int l = 0, sz = v.size();
  for (int i = 1; i < sz; i++) {
    if (v[i] - v[l] != i - l) {
      if (i - l == 1)
        cout << v[l] << ",";
      else
        cout << v[l] << "-" << v[i - 1] << ",";
      l = i;
    }
  }
  if (l == sz - 1)
    cout << v[sz - 1];
  else
    cout << v[l] << "-" << v[sz - 1];
  return 0;
}
