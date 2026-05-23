#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int l1 = s1.length();
  int l2 = s2.length();
  int c = 0;
  int hash[100000 + 5];
  if (l1 == l2) {
    int i;
    int k = 0;
    for (i = 0; i < l1; i++) {
      if (s1[i] != s2[i]) {
        c++;
        hash[k++] = i;
      }
    }
    if (c == 2) {
      char temp = s1[hash[0]];
      s1[hash[0]] = s1[hash[1]];
      s1[hash[1]] = temp;
      int t = s1.compare(s2);
      if (t == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      return 0;
    } else
      cout << "NO" << endl;
    return 0;
  } else
    cout << "NO" << endl;
  return 0;
}
