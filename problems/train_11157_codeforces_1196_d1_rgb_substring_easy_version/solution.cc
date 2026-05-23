#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int N = 2 * 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s, s1, s2, s3;
  int n, i, k, q, cost = 0, c1, c2, c3;
  for (i = 0; i < 200001 / 3; i++) {
    s1 += "RGB";
    s2 += "GBR";
    s3 += "BRG";
  }
  cin >> q;
  while (q--) {
    cin >> n >> k;
    cin >> s;
    c1 = c2 = c3 = cost = 0;
    for (i = 0; i < k; i++) {
      c1 += (s[i] != s1[i]);
      c2 += (s[i] != s2[i]);
      c3 += (s[i] != s3[i]);
    }
    cost = min(c1, min(c2, c3));
    for (i = k; i < n; i++) {
      if (s[i] != s1[i]) c1++;
      if (s[i - k] != s1[i - k]) c1--;
      if (s[i] != s2[i]) c2++;
      if (s[i - k] != s2[i - k]) c2--;
      if (s[i] != s3[i]) c3++;
      if (s[i - k] != s3[i - k]) c3--;
      cost = min(cost, min(c1, min(c3, c2)));
    }
    cout << cost << endl;
  }
  return 0;
}
