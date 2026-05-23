#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
using namespace std;
bool cmp(int a, int b) { return a >= b; }
int main() {
  int k, cnt = 0, sum = 0, idx = 0;
  cin >> k;
  vector<int> a(12);
  for (int i = (int)(0); i < (int)(12); ++i) cin >> a[i];
  sort(a.begin(), a.end(), cmp);
  while (sum < k && idx < 12) {
    sum += a[idx];
    idx++;
    cnt++;
  }
  if (sum >= k)
    cout << cnt << endl;
  else
    cout << "-1\n";
  return 0;
}
