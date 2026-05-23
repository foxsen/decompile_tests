#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long d = k / n + bool(k % n);
  cout << d << endl;
}
