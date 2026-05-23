#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int elements;
    cin >> elements;
    if (elements % 2 != 0) {
      count++;
    }
  }
  string res = (count == 0) ? "Second" : "First";
  cout << res;
  return 0;
}
