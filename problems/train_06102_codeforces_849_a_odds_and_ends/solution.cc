#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[0] % 2 == 0) {
      cout << "No\n";
      return 0;
    }
  }
  if (n % 2 != 0 && arr[0] % 2 != 0 && arr[n - 1] % 2 != 0)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
