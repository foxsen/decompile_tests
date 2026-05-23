#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int l = 1, r = n;
  while (l < n && a[l] < a[l + 1]) l++;
  while (r > 1 && a[r] < a[r - 1]) r--;
  r = n - r + 1;
  if (l & 1 || r & 1)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}
