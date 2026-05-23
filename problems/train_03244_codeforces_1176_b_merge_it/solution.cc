#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, t, a;
  cin >> t;
  while (t--) {
    cin >> n;
    int arr[3] = {0};
    for (int i = 0; i < n; i++) {
      cin >> a;
      arr[a % 3]++;
    }
    if (arr[1] == 0) {
      cout << arr[0] + arr[2] / 3;
    } else if (arr[2] == 0) {
      cout << arr[0] + arr[1] / 3;
    } else {
      if (arr[2] >= arr[1]) {
        arr[2] -= arr[1];
        arr[2] /= 3;
        cout << arr[0] + arr[1] + arr[2];
      } else {
        arr[1] -= arr[2];
        arr[1] /= 3;
        cout << arr[0] + arr[1] + arr[2];
      }
    }
    cout << endl;
  }
  return 0;
}
