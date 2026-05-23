#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  set<int> st;
  vector<int> v;
  for (int i = 0; i < n; i++) v.push_back(i);
  int lead = 0;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    n = v.size();
    x %= n;
    int tmp = (lead + x) % n;
    cout << v[tmp] + 1 << ' ';
    lead = tmp;
    v.erase(v.begin() + tmp);
  }
  return 0;
}
