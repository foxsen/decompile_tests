#include <bits/stdc++.h>
using namespace std;
int n;
int num[4000];
double memo[9000010];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  int cant = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (num[i] > num[j]) cant++;
    }
  }
  memo[0] = 0.0;
  memo[1] = 1.0;
  for (int i = 2; i <= cant; i++) {
    memo[i] = 4 + memo[i - 2];
  }
  printf("%.6lf\n", memo[cant]);
  return 0;
}
