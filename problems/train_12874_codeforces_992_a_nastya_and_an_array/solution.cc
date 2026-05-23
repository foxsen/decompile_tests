#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  int i, j, k;
  int n, m;
  cin >> n;
  set<int> s;
  for (i = 0; i < n; i++) {
    cin >> m;
    if (m) s.insert(m);
  }
  cout << s.size() << endl;
}
