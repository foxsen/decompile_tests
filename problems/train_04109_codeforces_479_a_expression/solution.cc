#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int first = a + b * c, second = a * (b + c), third = a * b * c,
      fourth = (a + b) * c, fifth = a + b + c, sixth = (a * b) + c;
  cout << max(max(first, max(second, third)), max(fourth, max(fifth, sixth)))
       << endl;
  return 0;
}
