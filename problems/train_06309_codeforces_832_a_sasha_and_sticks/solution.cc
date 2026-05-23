#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int rem = n / m;
  if (rem % 2 == 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
