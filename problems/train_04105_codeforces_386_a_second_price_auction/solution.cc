#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int a = 0;
  int index = 1;
  for (int i = 0; i < n; i++) {
    if (a < arr[i]) {
      a = arr[i];
      index = i + 1;
    }
  }
  int b = 0;
  for (int i = 0; i < n; i++) {
    if (b < arr[i] && arr[i] != a) {
      b = arr[i];
    }
  }
  cout << index << endl << b;
}
