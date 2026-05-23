#include <bits/stdc++.h>
using namespace std;
int main() {
  int even, odd;
  cin >> even >> odd;
  if (even == 0 && odd == 0) {
    cout << "NO";
    return 0;
  } else {
    if (odd == even || even + 1 == odd || odd + 1 == even) {
      cout << "YES";
    } else
      cout << "NO";
  }
  return 0;
}
