#include <bits/stdc++.h>
using namespace std;
int main() {
  int d = 0, t = 0, c = 0;
  cin >> d >> t;
  int arr[d];
  for (int i = 0; i < d; i++) cin >> arr[i];
  for (int i = 0; i < d; i++) {
    if (arr[i] + t <= 86400) {
      c++;
      t -= (86400 - arr[i]);
      break;
    } else {
      t -= (86400 - arr[i]);
      c++;
    }
  }
  cout << c;
}
