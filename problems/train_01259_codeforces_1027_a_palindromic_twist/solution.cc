#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int flag = 1, start = 0, end = n - 1;
    while (start <= end) {
      char ssp = s[start] + 1;
      char sep = s[end] + 1;
      char sem = s[end] - 1;
      char ssm = s[start] - 1;
      if ((ssp == sep) || (ssp == sem) || (ssm == sep) || (ssm == sem))
        flag = 1;
      else {
        flag = 0;
        break;
      }
      start++;
      end--;
    }
    if (flag == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
