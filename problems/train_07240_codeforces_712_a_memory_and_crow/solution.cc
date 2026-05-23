#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int nums[n];
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    nums[i] = b;
  }
  for (int i = 0; i < n - 1; i++) {
    cout << nums[i] + nums[i + 1] << " ";
  }
  cout << nums[n - 1];
}
