#include <bits/stdc++.h>
using namespace std;
void cp() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  cp();
  {
    string s, t;
    cin >> s >> t;
    if (s.length() == t.length() + 1) {
      long long m = 0;
      long long in = -1;
      char f;
      long long j = 0;
      for (long long i = 0; i < s.length(); i += 1) {
        if (s[i] != t[j]) {
          f = s.at(i);
          in = i;
          m++;
          j--;
        }
        j++;
      }
      vector<long long> ans;
      if (m == 1) {
        while (in > -1) {
          if (s[in] == f) {
            in--;
          } else {
            break;
          }
        }
        in++;
        while (in < s.length()) {
          if (s[in] == f) {
            ans.push_back(in + 1);
            in++;
          } else {
            break;
          }
        }
        cout << ans.size();
        cout << endl;
        ;
        for (long long i = 0; i < ans.size(); i += 1) cout << ans[i] << " ";
      } else {
        cout << "0\n";
      }
    } else {
      cout << "0\n";
    }
  }
  return 0;
}
