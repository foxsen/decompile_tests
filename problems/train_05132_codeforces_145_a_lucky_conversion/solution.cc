#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5, inf = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size(), a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      if (s2[i] == '4')
        a++;
      else
        b++;
    }
  }
  cout << min(a, b) + (b - min(a, b) + a - min(a, b)) << "\n";
  return 0;
}
