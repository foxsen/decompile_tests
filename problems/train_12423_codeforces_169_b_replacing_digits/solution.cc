#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a;
  int l = a.length(), i, j;
  vector<string> s;
  cin >> b;
  int p = b.length();
  s.push_back(b);
  vector<int> visit(p, 0);
  sort(s[0].rbegin(), s[0].rend());
  j = 0;
  for (i = 0; i < l; i++) {
    if (((a[i] - 48) < (s[0][j] - 48)) && visit[j] == 0) {
      a[i] = s[0][j];
      j++;
    }
  }
  cout << a;
  return 0;
}
