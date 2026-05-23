#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  int temp;
  for (long long i = 0; i < 2 * n; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  int ans = 0, i = 1;
  vector<int>::iterator it1, it2;
  while (v.size()) {
    i = v[0];
    v[0] = -1;
    it2 = find(v.begin(), v.end(), i);
    ans += it2 - v.begin() - 1;
    v.erase(v.begin());
    it2 = find(v.begin(), v.end(), i);
    v.erase(it2);
    i++;
  }
  cout << ans << endl;
}
