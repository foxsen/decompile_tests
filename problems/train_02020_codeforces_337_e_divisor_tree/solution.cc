#include <bits/stdc++.h>
using namespace std;
int n;
long long a[8];
int factors[8];
int primeCnt;
int solve(int cur, vector<long long> &tree, int rootNum, int rootSum) {
  if (cur == n) return n + (rootNum > 1) + rootSum - primeCnt;
  int ret = 1 << 28;
  for (int i = 0; i < (int)(tree.size()); i++) {
    if (tree[i] % a[cur] == 0) {
      tree.push_back(a[cur]);
      tree[i] /= a[cur];
      ret = min(ret, solve(cur + 1, tree, rootNum + (i == 0),
                           rootSum + (i == 0) * factors[cur]));
      tree[i] *= a[cur];
      tree.pop_back();
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  sort(a, a + n, greater<long long>());
  for (int i = 0; i < (int)(n); i++) {
    long long tmp = a[i];
    for (int j = 2; (long long)j * j <= tmp; j++) {
      while (tmp % j == 0) {
        factors[i]++;
        tmp /= j;
      }
    }
    if (tmp > 1) factors[i]++;
    if (tmp == a[i]) primeCnt++;
  }
  vector<long long> tree;
  tree.push_back(0);
  int ret = solve(0, tree, 0, 0);
  cout << ret << endl;
  return 0;
}
