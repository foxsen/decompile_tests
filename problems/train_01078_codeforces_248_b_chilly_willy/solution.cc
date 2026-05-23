#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> vmod, ans;
int main() {
  int i, j, k, l;
  vmod.push_back(0);
  vmod.push_back(0);
  vmod.push_back(0);
  vmod.push_back(100);
  i = 4;
  while (i < N) {
    vmod.push_back((vmod[i - 1] * 10) % 210);
    i++;
  }
  int n, x;
  cin >> n;
  if (!vmod[n])
    cout << -1 << endl;
  else {
    ans.push_back(1);
    for (i = 1; i < n; i++) ans.push_back(0);
    x = 210 - vmod[i];
    j = n - 1;
    while (x) {
      ans[j] = ans[j] + x % 10;
      x = x / 10;
      j--;
    }
    for (j = 0; j < ans.size(); j++) cout << ans[j];
  }
  return 0;
}
