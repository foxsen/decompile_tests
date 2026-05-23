#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T _abs(T n) {
  return n < 0 ? -n : n;
}
template <class T>
inline T _gcd(T a, T b) {
  return b == 0 ? a : _gcd(b, a % b);
}
template <class T>
inline T _lcm(T a, T b) {
  return a / _gcd(a, b) * b;
}
int main() {
  int n;
  string in, temp;
  string line;
  while (scanf("%d", &n) == 1) {
    temp = "<3";
    for (int i = 1; i <= n; i++) {
      cin >> in;
      temp += in;
      temp += "<3";
    }
    cin >> line;
    int len = line.size();
    int j = 0;
    for (int i = 0; i < len; i++)
      if (temp[j] == line[i]) j++;
    if (j == temp.size())
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
