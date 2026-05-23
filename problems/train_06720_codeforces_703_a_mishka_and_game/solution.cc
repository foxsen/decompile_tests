#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  int cnt1 = 0, cnt2 = 0;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a < b)
      cnt2++;
    else if (a > b)
      cnt1++;
  }
  if (cnt1 > cnt2)
    cout << "Mishka";
  else if (cnt2 > cnt1)
    cout << "Chris";
  else
    cout << "Friendship is magic!^^";
  return 0;
}
