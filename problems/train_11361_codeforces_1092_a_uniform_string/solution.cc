#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int n, k;
    cin >> n >> k;
    k--;
    int now = 0;
    char f = 'a';
    while (now != n) {
      s += f;
      if (f == 'z' || (f - 'a') == k)
        f = 'a';
      else
        f++;
      now++;
    }
    cout << s << endl;
  }
  return 0;
}
