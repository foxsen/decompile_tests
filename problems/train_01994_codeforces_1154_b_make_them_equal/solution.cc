#include <bits/stdc++.h>
using namespace std;
int main() {
  int size;
  cin >> size;
  int i;
  vector<int> arr;
  int new_size = 0;
  for (i = 0; i < size; ++i) {
    int x;
    cin >> x;
    bool has = false;
    for (int j = 0; j < i; ++j) {
      if (x == arr[j]) {
        has = true;
        break;
      }
    }
    if (has) {
      continue;
    }
    arr.push_back(x);
    new_size++;
  }
  sort(arr.begin(), arr.end());
  if (new_size > 3) {
    cout << -1 << '\n';
  } else if (new_size == 3) {
    if ((arr[1] - arr[0]) == (arr[2] - arr[1])) {
      cout << arr[1] - arr[0] << '\n';
    } else {
      cout << -1 << '\n';
    }
  } else if (new_size == 2) {
    if ((arr[1] - arr[0]) % 2 == 0) {
      cout << (arr[1] - arr[0]) / 2 << '\n';
    } else {
      cout << (arr[1] - arr[0]) << '\n';
    }
  } else if (new_size == 1) {
    cout << 0 << '\n';
  }
}
