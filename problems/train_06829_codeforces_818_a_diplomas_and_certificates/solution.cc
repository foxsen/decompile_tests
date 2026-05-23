#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, a;
  cin >> n >> k;
  a = (n / 2) / (k + 1);
  cout << a << " " << a * k << " " << n - (k + 1) * a;
}
