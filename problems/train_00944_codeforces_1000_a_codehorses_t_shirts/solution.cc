#include <bits/stdc++.h>
using namespace std;
const int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const double PI = acos(-1);
const double EPS = 10e-9;
const int e4 = 1e4 + 5;
const int e5 = 1e5 + 5;
const int e6 = 1e6 + 5;
map<string, int> m;
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    m[str]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (m[str] != 0) {
      m[str]--;
    } else {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
