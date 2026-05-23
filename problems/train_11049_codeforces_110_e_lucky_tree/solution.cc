#include <bits/stdc++.h>
using namespace std;
int parent[100005];
int coun[100005];
bool isLucky(int a) {
  while (a) {
    int x = a % 10;
    if (x == 4 || x == 7) {
    } else
      return false;
    a = a / 10;
  }
  return true;
}
int findp(int a) {
  if (parent[a] == a) {
    return a;
  }
  parent[a] = findp(parent[a]);
  return parent[a];
}
void uni(int x, int y) {
  int parx = findp(x);
  int pary = findp(y);
  if (parx != pary) {
    parent[parx] = pary;
    coun[pary] += coun[parx];
  }
}
vector<int> vec[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  long long int n, i, j, k, x, y, c = 0, ans = 0, z, z1;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    coun[i] = 1;
    parent[i] = i;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y >> z;
    if (!isLucky(z)) {
      vec[x].push_back(y);
      vec[y].push_back(x);
      uni(x, y);
    }
  }
  for (i = 1; i <= n; i++) {
    int x = findp(i);
    int y = coun[x];
    ans += (n - y) * (n - y - 1);
  }
  cout << ans;
  return 0;
}
