#include <bits/stdc++.h>
using namespace std;
int gcd(int i, int j) {
  if (!j) return i;
  return gcd(j, i % j);
}
long long output(int a, int b, int c) {
  long long out = (long long)a * (long long)b * (long long)c;
  return out;
}
int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  if (n == 1)
    printf("1\n");
  else if (n == 2)
    printf("2\n");
  else {
    if (n % 2)
      cout << output(n, n - 1, n - 2) << endl;
    else {
      int a = n;
      int b = n - 1;
      int c = n - 2;
      int d = n - 3;
      int g1 = gcd(a, c);
      int g2 = gcd(a, d);
      if (g2 > 1)
        cout << output(b, c, d) << endl;
      else
        cout << output(a, b, d) << endl;
    }
  }
  return 0;
}
