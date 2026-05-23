#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  long long ans = 0, ml = 0;
  for (int i = 0; i < S.size(); i += 1) {
    if (S[i] == 'M')
      ml++;
    else
      ans = max(ans + (ml > 0), ml);
  }
  cout << ans << endl;
  return 0;
}
