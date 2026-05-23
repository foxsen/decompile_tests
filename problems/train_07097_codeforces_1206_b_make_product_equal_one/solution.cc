#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  long long ans = 0, c = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (h < 0) {
      ans += (-h - 1);
      c++;
    } else if (h > 0) {
      ans += h - 1;
    } else {
      c2++;
    }
  }
  if (c % 2) {
    if (c2 > 0)
      ans += c2;
    else
      ans += 2;
  } else {
    ans += c2;
  }
  cout << ans << endl;
  return 0;
}
