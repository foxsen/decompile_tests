#include <bits/stdc++.h>
using namespace std;
long long n, d, c;
long a[105];
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] == 2 * d)
      c++;
    else if (a[i] - a[i - 1] > 2 * d)
      c += 2;
  }
  return cout << c + 2, 0;
}
