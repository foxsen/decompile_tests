#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, k = 0, l;
    cin >> n;
    vector<long long int> numbers(n), freq(32, 0);
    for (i = 0; i < n; i++) {
      cin >> numbers.at(i);
      for (j = 1; j < 32; j++) {
        if (pow(2, j) > numbers.at(i)) break;
      }
      freq.at(j - 1)++;
    }
    for (i = 0; i < 32; i++) k += freq.at(i) * (freq.at(i) - 1) / 2;
    cout << k << endl;
  }
  return 0;
}
