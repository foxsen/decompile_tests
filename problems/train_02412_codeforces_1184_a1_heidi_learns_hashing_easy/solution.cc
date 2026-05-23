#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int r;
  cin >> r;
  if (r % 2 == 0) {
    cout << "NO";
    return 0;
  }
  if (r < 4) {
    cout << "NO";
    return 0;
  }
  r--;
  r /= 2;
  cout << "1 " << r - 1;
  return 0;
}
