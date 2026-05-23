#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 10;
int n;
set<int> S;
int main() {
  int t;
  cin >> t;
  while (t--) {
    S.clear();
    cin >> n;
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) S.insert(i * i);
    for (int i = 1; i * i * i <= n; i++) S.insert(i * i * i);
    cout << S.size() << endl;
  }
  return 0;
}
