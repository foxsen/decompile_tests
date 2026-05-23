#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
string s;
vector<int> v;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> n >> x >> y;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n and s[j] == s[i]) {
      j++;
    }
    v.emplace_back(s[i] - '0');
    i = j - 1;
  }
  if (v[0] == 1) v.erase(v.begin());
  if (v.size() and v.back() == 1) v.pop_back();
  if (v.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  long long zero = 0, one = 0;
  for (int x : v) {
    if (x == 1)
      one++;
    else
      zero++;
  }
  cout << min(one * x + y, zero * y) << endl;
  return 0;
}
