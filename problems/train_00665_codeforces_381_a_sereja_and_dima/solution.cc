#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0, d = 0, beg = 0, end = 0;
  cin >> n;
  int a[n];
  end = n - 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (a[beg] < a[end]) {
        s += a[end];
        end--;
      } else {
        s += a[beg];
        beg++;
      }
    } else {
      if (a[beg] < a[end]) {
        d += a[end];
        end--;
      } else {
        d += a[beg];
        beg++;
      }
    }
  }
  cout << s << " " << d;
}
