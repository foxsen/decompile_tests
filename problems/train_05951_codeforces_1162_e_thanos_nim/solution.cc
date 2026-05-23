#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn];
int n;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n / 2 + 1; i++) {
    if (a[i] != a[i - 1]) {
      cout << "Alice" << endl;
      return 0;
    }
  }
  cout << "Bob" << endl;
  return 0;
}
