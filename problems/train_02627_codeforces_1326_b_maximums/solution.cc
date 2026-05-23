#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int input, a1, temp;
  cin >> n;
  vector<long long int> a;
  vector<long long int> b;
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (i == 0) {
      b.push_back(input);
      a1 = b[i];
      temp = b[i];
      a.push_back(temp);
      cout << a[i] << " ";
    } else {
      b.push_back(input);
      a1 = b[i] + temp;
      a.push_back(a1);
      if (temp < a.back()) temp = a.back();
      cout << a[i] << " ";
    }
  }
  return 0;
}
