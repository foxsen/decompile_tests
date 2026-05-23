#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double pi = acos(-1.0);
const int inf = (int)1e9;
const double eps = 1e-6;
const int ss = (int)1e6 + 3;
const int base = inf;
bool pred(const pair<int, int>& i, const pair<int, int>& j) {
  if (i.first == j.first) {
    return i.second > j.second;
  } else {
    return i.first > j.first;
  }
}
bool pred1(const string& i, const string& j) { return i.size() > j.size(); }
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort((a).begin(), (a).end());
  if (a[n - 1] == 1) {
    if (n == 1) {
      cout << "2";
      return 0;
    } else {
      a[n - 2] = 2;
    }
  }
  cout << "1 ";
  for (int i = 1; i < n; ++i) {
    printf("%d ", a[i - 1]);
  }
  return 0;
}
