#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> mems;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mems.push_back(a);
  }
  sort(mems.begin(), mems.end());
  vector<int> need(40);
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    need[a]++;
  }
  int out = 0;
  for (int i = 0; i < 32; i++) {
    int now = need[i];
    for (auto& it : mems) {
      if ((it & 1) && now) {
        now--;
        it -= 1;
        out++;
      }
    }
    for (auto& it : mems) {
      auto toSub = min(it, now);
      now -= toSub;
      it -= toSub;
      out += toSub;
      it /= 2;
    }
  }
  cout << out << endl;
  return 0;
}
