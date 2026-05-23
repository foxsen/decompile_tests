#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n - 2; i++) {
    count += (i + 2) * (i + 3);
  }
  cout << count;
  return 0;
}
