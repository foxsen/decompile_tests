#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, sum, n;
  cin >> t;
  while (t--) {
    sum = 0;
    cin >> n;
    string s, s1;
    cin >> s >> s1;
    for (int i = 0; i < s.length(); i++) {
      if (s[i + 1] == '1' && s1[i + 1] == '1') {
        cout << "NO" << endl;
        break;
      } else {
        sum++;
      }
    }
    if (sum >= n - 2) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
