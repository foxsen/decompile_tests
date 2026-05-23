#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  int minf = n - 1, maxf = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s1[i] <= s2[minf]) minf--;
  }
  cout << minf + 1 << endl;
  for (int i = 0; i < n; i++) {
    if (s2[i] > s1[maxf]) maxf++;
  }
  cout << maxf << endl;
  return 0;
}
