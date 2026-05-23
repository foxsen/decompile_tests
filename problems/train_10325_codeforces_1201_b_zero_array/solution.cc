#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
map<int, int> m;
bool cmp(int a, int b) { return a > b; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long sum = 0;
  int n;
  cin >> n;
  int maxm = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    maxm = max(maxm, a[i]);
  }
  if (sum % 2 == 0 && (sum - maxm) >= maxm) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
