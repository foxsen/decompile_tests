#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, bn;
  cin >> n >> bn;
  long long int sum = 0;
  while (n--) {
    int a;
    cin >> a;
    sum = (long long int)bn * sum + a;
  }
  long long int sum1 = 0;
  int m, bm;
  cin >> m >> bm;
  while (m--) {
    int a;
    cin >> a;
    sum1 = (long long int)bm * sum1 + a;
  }
  if (sum > sum1)
    cout << '>';
  else if (sum < sum1)
    cout << '<';
  else
    cout << '=';
}
