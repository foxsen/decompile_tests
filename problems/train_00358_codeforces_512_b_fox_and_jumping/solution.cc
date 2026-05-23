#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int N = 305;
int c[N], l[N];
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long rrand() {
  long long a = rand();
  long long b = rand();
  return a + (b >> 16);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int best = 0;
  map<int, int> prices;
  for (int i = 0; i < n; ++i) {
    int value = l[i];
    int cost = c[i];
    for (map<int, int>::iterator it = prices.begin(); it != prices.end();
         ++it) {
      int to = gcd(it->first, value);
      if (prices.count(to) == 0 || prices[to] > cost + it->second) {
        prices[to] = cost + it->second;
      }
    }
    if (prices.count(value) == 0 || prices[value] > cost) {
      prices[value] = cost;
    }
  }
  if (prices.count(1) == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << prices[1] << endl;
  return 0;
}
