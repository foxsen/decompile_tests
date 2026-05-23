#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum1 = 0, sum2 = 0, i = 0;
  cin >> n;
  while (true) {
    i++;
    sum1 += i;
    sum2 += sum1;
    if (sum2 > n) break;
  }
  cout << i - 1;
}
