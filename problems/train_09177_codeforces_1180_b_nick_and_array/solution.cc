#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n];
  long long cntp = 0, cntz = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long i = 0; i < n; i++) {
    if (arr[i] >= 0) {
      arr[i] = -1 * arr[i] - 1;
    }
  }
  long long max = -1, index;
  if (n % 2 != 0) {
    for (long long i = 0; i < n; i++) {
      if (abs(arr[i]) > max) {
        max = abs(arr[i]);
        index = i;
      }
    }
    arr[index] = -1 * arr[index] - 1;
  }
  for (long long i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
