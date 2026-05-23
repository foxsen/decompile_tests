#include <bits/stdc++.h>
using namespace std;
const int MX = 25;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  pair<int, int> a[n];
  for (int i = (0), _b = (n); i < (_b); ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  int ans[n];
  int cur = 0;
  for (int i = (0), _b = (n); i < (_b); ++i) {
    if (cur < a[i].first) cur = a[i].first;
    ans[a[i].second] = cur++;
  }
  for (int i = (0), _b = (n); i < (_b); ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
