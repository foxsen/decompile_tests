#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = 0, pre = 198, da = 1988, dad = 1988, size = 0, pow = 1;
    for (int i = 4; i < s.size(); i++) {
      n = n * 10 + (s[i] - '0');
    }
    size = s.size() - 4;
    for (int i = 0; i < size; i++) {
      pow *= 10;
      while (dad <= da) {
        dad = pre * pow + n % pow;
        pre++;
      }
      da = dad;
      pre--;
      pre /= 10;
    }
    cout << da << endl;
  }
  return 0;
}
