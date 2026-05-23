#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f;
    sum += f;
  }
  int count = 0, demo = sum;
  for (int j = 1; j <= 5; j++) {
    demo++;
    if (demo % (n + 1) != 1) count++;
  }
  cout << count;
  return 0;
}
