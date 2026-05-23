#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, max, min;
  char c;
  int a;
  string s;
  while (cin >> n) {
    max = 2000000000;
    min = -2000000000;
    for (int i = 0; i < n; i++) {
      cin >> s;
      cin >> a >> c;
      if (c == 'Y') {
        if (s == ">" && min <= a) min = a + 1;
        if (s == "<" && max >= a) max = a - 1;
        if (s == ">=" && min < a) min = a;
        if (s == "<=" && max > a) max = a;
      }
      if (c == 'N') {
        if (s == ">" && max > a) max = a;
        if (s == "<" && min < a) min = a;
        if (s == ">=" && max >= a) max = a - 1;
        if (s == "<=" && min <= a) min = a + 1;
      }
    }
    if (min > max)
      cout << "Impossible" << endl;
    else
      cout << min << endl;
  }
}
