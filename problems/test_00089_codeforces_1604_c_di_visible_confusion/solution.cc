#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int testcase;
  cin >> testcase;
  while (testcase--) {
    long long int n;
    cin >> n;
    long long int i, j;
    long long int arr[n];
    long long int temp = 0;
    long long int flag = 0;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (i = 0; i < n; i++) {
      flag = 0;
      for (j = i + 2; j >= i + 2 - temp; j--) {
        if (arr[i] % j != 0) {
          temp++;
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        break;
      }
    }
    if (flag == 0) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
  return 0;
}
