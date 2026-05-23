#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int sum = N * (N + 1) / 2;
  for (int i = 2; i * i <= sum; i++)
    if (sum % i == 0) {
      cout << "Yes\n";
      cout << "1 " << i << '\n';
      cout << N - 1 << ' ';
      for (int j = 1; j <= N; j++)
        if (j != i) cout << j << ' ';
      return 0;
    }
  cout << "No";
}
