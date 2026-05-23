#include <bits/stdc++.h>
using namespace std;
int def = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s[500];
  for (int i = 0; i < n; i++) cin >> s[i];
  int three = 0, even = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      int num = s[i][j] - '0';
      three += num;
      if (num % 2 == 0) even += 1;
      if (num == 0) zero += 1;
    }
    if ((three % 3 == 0) && (even > 1 && zero >= 1))
      cout << "red" << endl;
    else
      cout << "cyan" << endl;
    three = 0;
    even = 0;
    zero = 0;
  }
  return 0;
}
