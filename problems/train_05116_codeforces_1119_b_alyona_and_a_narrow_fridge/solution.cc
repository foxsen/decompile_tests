#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int h;
  cin >> n >> h;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  int count = 0;
  for (int i = 0; i < n; i += 1) {
    long long int sum = 0;
    sort(a, a + i + 1);
    for (int j = i; j >= 0; j -= 2) {
      sum += a[j];
    }
    if (sum <= h)
      count = i + 1;
    else
      break;
  }
  cout << count;
  return 0;
}
