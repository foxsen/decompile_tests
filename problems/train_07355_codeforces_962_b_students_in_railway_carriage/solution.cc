#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, coders, sportsmen;
  string str;
  cin >> n >> coders >> sportsmen;
  cin >> str;
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (coders < sportsmen) swap(coders, sportsmen);
    while (str[i] == '.' && i < n) {
      if (coders > 0) total++;
      coders--;
      swap(coders, sportsmen);
      i++;
    }
  }
  cout << total;
}
