#include <bits/stdc++.h>
using namespace std;
void SWAP(int* a, int* b) {
  int swap = *a;
  *a = *b;
  *b = swap;
}
int main() {
  int i, k;
  int t, n, a, b, c;
  string str;
  cin >> t;
  while (t--) {
    int A = 0, B = 0, C = 0;
    cin >> n;
    cin >> a >> b >> c;
    cin >> str;
    for (i = 0; i < n; i++) {
      if (str[i] == 'R')
        A++;
      else if (str[i] == 'P')
        B++;
      else
        C++;
    }
    if (min(A, b) + min(B, c) + min(C, a) < (n + 1) / 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES" << endl;
    int j = 0;
    vector<char> ans(n, '@');
    for (i = 0; i < n; i++) {
      if (str[i] == 'R' && b > 0) {
        ans[i] = 'P';
        b--;
        j++;
      }
      if (str[i] == 'P' && c > 0) {
        ans[i] = 'S';
        c--;
        j++;
      }
      if (str[i] == 'S' && a > 0) {
        ans[i] = 'R';
        a--;
        j++;
      }
    }
    for (i = 0; i < n; i++) {
      if (ans[i] == '@') {
        if (b) {
          ans[i] = 'P';
          b--;
        } else if (a) {
          ans[i] = 'R';
          a--;
        } else {
          ans[i] = 'S';
          c--;
        }
      }
    }
    for (i = 0; i < n; i++) cout << ans[i];
    cout << endl;
  }
}
