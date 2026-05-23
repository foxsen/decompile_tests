#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string s1, s2;
  cin >> s1 >> s2;
  long long i, n = s1.size(), k1 = 0, k2 = 0, flag = 0, cnt = 0;
  for (i = 0; i < n; i++) {
    if (s1[i] == '4' && s2[i] == '7')
      k1++;
    else if (s1[i] == '7' && s2[i] == '4')
      k2++;
  }
  if (k1 >= k2) {
    cnt = k2 + (k1 - k2);
  } else {
    cnt = k1 + (k2 - k1);
  }
  cout << cnt;
  return 0;
}
