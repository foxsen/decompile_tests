#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long maxx = 0, c = 0;
  long long a[n];
  long long count = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == a[i + 1]) {
      count++;
    } else if (a[i] != a[i + 1]) {
      if (count > 0) {
        if (maxx == 0) {
          maxx = a[i];
          c = count;
        } else if (maxx < a[i]) {
          maxx = a[i];
          c = count;
        } else if (maxx == a[i]) {
          if (c < count) {
            c = count;
          }
        }
      }
      count = 1;
    }
  }
  cout << c << '\n';
  return 0;
}
