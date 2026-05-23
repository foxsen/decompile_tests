#include <bits/stdc++.h>
using namespace std;
vector<double> s;
int n;
double cal(int i) {
  double res = 0;
  for (int j = i; j < n; j++) {
    double temp = 1;
    for (int k = i; k < n; k++) {
      if (k == j)
        temp *= s[j];
      else
        temp *= (1 - s[k]);
    }
    res += temp;
  }
  return res;
}
int main() {
  cin >> n;
  double temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    s.push_back(temp);
  }
  sort(s.begin(), s.end());
  double result = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (cal(i) > result) result = cal(i);
  }
  cout.precision(12);
  cout << fixed << result << endl;
}
