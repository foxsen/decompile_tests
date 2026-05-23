#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], n, dui, tot;
void over() {
  cout << "cslnb";
  exit(0);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] == 0 && a[i] == 0) over();
    if (a[i - 1] == a[i]) dui++;
    if (a[i - 1] == a[i] && i > 2 && a[i - 2] + 1 >= a[i]) over();
  }
  if (dui > 1) over();
  for (int i = 1; i <= n; i++) tot += a[i], tot -= (i - 1);
  if (tot % 2 == 0) over();
  cout << "sjfnb";
}
