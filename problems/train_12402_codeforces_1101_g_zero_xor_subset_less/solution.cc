#include <bits/stdc++.h>
using namespace std;
using namespace std;
int n, x, everything = 0;
vector<int> basis;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  while (n--) {
    cin >> x;
    everything ^= x;
    for (auto& i : basis) x = min(x, x ^ i);
    if (x) basis.push_back(x);
  }
  cout << (everything ? (int)basis.size() : -1);
}
