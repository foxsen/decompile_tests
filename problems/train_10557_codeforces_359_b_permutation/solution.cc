#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, A[100001], sum = 0, index = 1;
  cin >> n >> k;
  for (int i = 1; i <= 2 * n; i++) A[i] = i;
  while (sum != 2 * k) {
    swap(A[index], A[index + 1]);
    sum += 2;
    index += 2;
  }
  for (int i = 1; i <= 2 * n; i++) cout << A[i] << " ";
  cout << endl;
  return 0;
}
