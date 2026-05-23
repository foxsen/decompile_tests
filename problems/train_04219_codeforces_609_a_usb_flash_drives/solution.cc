#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return a > b; }
int main() {
  int n, m;
  cin >> n >> m;
  int s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s, s + n, comp);
  for (int i = 0; i < n; i++) {
    m -= s[i];
    if (m <= 0) {
      cout << i + 1 << endl;
      break;
    }
  }
}
