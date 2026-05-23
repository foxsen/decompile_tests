#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
map<long long, int> num;
int main() {
  long long n;
  long long a, b;
  cin >> n >> a >> b;
  int x, vx, vy;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &x, &vx, &vy);
    ans += num[a * vx - vy] - mp[make_pair(vx, vy)];
    num[a * vx - vy + 1 - 1]++;
    mp[make_pair(vx, vy)]++;
  }
  cout << 2 * ans;
  return 0;
}
