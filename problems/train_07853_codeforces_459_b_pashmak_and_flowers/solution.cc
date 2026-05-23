#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long min = a[0];
  long long max = a[n - 1];
  long long num1 = 0;
  long long num2 = 0;
  for (long long i = 0; a[i] == min; i++) {
    num1++;
  }
  for (long long i = n - 1; a[i] == max; i--) {
    num2++;
  }
  if (min == max) {
    cout << 0 << " " << ((num1) * (num1 - 1)) / 2 << endl;
  } else
    cout << max - min << " " << num1 * num2 << endl;
}
