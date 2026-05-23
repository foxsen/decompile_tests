#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, m, n, cnt, ans, x, y;
long long arr[10000];
string s;
int main() {
  cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] - 49 == 0)
      cnt += arr[0];
    else if (s[i] - 49 == 1)
      cnt += arr[1];
    else if (s[i] - 49 == 2)
      cnt += arr[2];
    else if (s[i] - 49 == 3)
      cnt += arr[3];
  }
  cout << cnt;
}
