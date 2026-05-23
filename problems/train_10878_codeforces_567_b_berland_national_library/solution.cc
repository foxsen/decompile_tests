#include <bits/stdc++.h>
using namespace std;
void solve(long long tz) {
  int n;
  cin >> n;
  int cnt = 0;
  map<pair<int, int>, int> mp;
  vector<pair<char, int>> arr;
  for (int i = 0; i < n; i++) {
    char x;
    int y;
    cin >> x >> y;
    arr.push_back({x, y});
    if (x == '-') {
      auto it = mp.find({'+', y});
      if (it == mp.end()) {
        cnt++;
      }
    }
    mp.insert({{x, y}, 0});
  }
  int curr = cnt;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i].first == '-') {
      curr--;
    } else {
      curr++;
    }
    cnt = max(cnt, curr);
  }
  cout << cnt << endl;
}
int main() {
  long long t;
  t = 1;
  long long z = 0;
  while (t--) {
    z++;
    solve(z);
  }
}
