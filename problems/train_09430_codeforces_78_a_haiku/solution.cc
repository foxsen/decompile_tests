#include <bits/stdc++.h>
using namespace std;
int counting(string s) {
  int ans = 0;
  for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it) {
    switch (*it) {
      case 'a':
      case 'i':
      case 'u':
      case 'e':
      case 'o':
        ans++;
        break;
    }
  }
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false);
  string s1, s2, s3;
  getline(cin, s1);
  getline(cin, s2);
  getline(cin, s3);
  int a1 = counting(s1);
  int a2 = counting(s2);
  int a3 = counting(s3);
  if (a1 == 5 && a2 == 7 && a3 == 5) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
