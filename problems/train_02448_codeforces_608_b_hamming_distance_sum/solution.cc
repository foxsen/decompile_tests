#include <bits/stdc++.h>
using namespace std;
long long b1[200010], b2[200010];
int main(void) {
  string a, b;
  cin >> a >> b;
  memset(b1, 0, sizeof(b1));
  memset(b2, 0, sizeof(b2));
  long long ans = 0;
  for (int i = 0; i < b.length(); i++) {
    b1[i] = b1[i - 1] + (b[i] == '1');
    b2[i] = b2[i - 1] + (b[i] == '0');
  }
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '1')
      ans += (b2[b.length() - a.length() + i] - b2[i - 1]);
    else
      ans += (b1[b.length() - a.length() + i] - b1[i - 1]);
  }
  cout << ans << endl;
}
