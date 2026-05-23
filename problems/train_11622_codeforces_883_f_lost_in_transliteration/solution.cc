#include <bits/stdc++.h>
using namespace std;
set<string> SE;
int main() {
  string a[500];
  int N;
  scanf("%d", &N);
  for (int k = 0; k < N; k++) {
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (i >= 1 && s[i] == 'h' && s[i - 1] == 'k')
        s[i - 1] = 'h';
      else if (s[i] == 'u') {
        a[k] += 'o';
        a[k] += 'o';
      } else
        a[k] += s[i];
    }
    SE.insert(a[k]);
  }
  printf("%d\n", SE.size());
  return 0;
}
