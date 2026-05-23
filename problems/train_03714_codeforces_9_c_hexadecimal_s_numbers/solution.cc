#include <bits/stdc++.h>
long long mod = 1e9 + 7;
const int MAX = 1e5 + 5;
using namespace std;
long long get_binary(int n) {
  long long binary = 0;
  int remainder, i = 1, step = 1;
  while (n != 0) {
    remainder = n % 2;
    n /= 2;
    binary += remainder * i;
    i *= 10;
  }
  return binary;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long cnt = 0;
  for (int i = 1; i <= (int)pow(2, 10) - 1; i++) {
    int num = i;
    long long bin = get_binary(num);
    if (bin <= n) cnt++;
  }
  cout << cnt;
  return 0;
}
