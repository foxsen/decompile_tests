#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > arr;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    arr.push_back(pair<int, int>(a, b));
  }
  sort(arr.begin(), arr.end());
  int ans = 0;
  for (const auto &i : arr) {
    int b = i.second;
    int a = i.first;
    if (ans <= b) {
      ans = b;
    } else {
      ans = a;
    }
  }
  cout << ans << endl;
  return 0;
}
