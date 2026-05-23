#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[2000] = {};
long long v[100007] = {};
int main() {
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    long long t;
    cin >> t;
    v[t]++;
  }
  for (long long i = 100000; i > 0; --i) {
    if (v[i] % 2 == 1) {
      cout << "Conan" << endl;
      return 0;
    }
  }
  cout << "Agasa" << endl;
}
