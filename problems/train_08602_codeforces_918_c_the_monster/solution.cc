#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string a;
  cin >> a;
  long long answer = 0;
  for (int i = 0; i < a.size(); i++) {
    long long open = 0;
    long long q = 0;
    for (int j = i; j < a.size(); j++) {
      if (a[j] == '(') {
        open += 1;
      } else if (a[j] == ')') {
        open -= 1;
      } else {
        q += 1;
      }
      if (open < 0) break;
      if (q > open) swap(q, open);
      answer += (open == q);
    }
  }
  cout << answer << endl;
  return 0;
}
