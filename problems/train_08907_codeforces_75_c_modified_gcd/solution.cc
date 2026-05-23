#include <bits/stdc++.h>
using namespace std;
vector<int> cd;
int getRes(int lb, int rb) {
  int low = 0, high = cd.size() - 1;
  int res = -1;
  while (low <= high) {
    int mid = (low + high) >> 1;
    int t = cd[mid];
    if (t <= rb && t >= lb) {
      low = mid + 1;
      res = max(t, res);
    } else if (t < lb) {
      low = mid + 1;
    } else
      high = mid - 1;
  }
  return res;
}
int main() {
  int a, b;
  int n;
  cin >> a >> b;
  if (a > b) swap(a, b);
  for (int i = 1; i * i <= b; i++)
    if (b % i == 0) {
      if (a % i == 0) cd.push_back(i);
      int t = b / i;
      if (a % t == 0) cd.push_back(t);
    }
  cin >> n;
  sort(cd.begin(), cd.end());
  while (n--) {
    int l, r;
    scanf("%d%d", &l, &r);
    cout << getRes(l, r) << endl;
  }
  return 0;
}
