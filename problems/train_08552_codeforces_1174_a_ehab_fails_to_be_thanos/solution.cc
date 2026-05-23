#include <bits/stdc++.h>
using namespace std;
bool b2(const pair<pair<int, int>, int> &p1,
        const pair<pair<int, int>, int> &p2) {
  return p1.first.first > p2.first.first;
}
bool b1(const pair<pair<int, int>, int> &p1,
        const pair<pair<int, int>, int> &p2) {
  return p1.first.second < p2.first.second;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  n = n * 2;
  long long int sum = 0, sum1 = 0;
  int arr[n];
  for (int i = 0; i <= n - 1; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr + n);
  for (int i = 0; i < n / 2; i++) sum1 += arr[i];
  if (sum1 * 2 == sum)
    cout << "-1" << endl;
  else {
    for (int i = 0; i <= n - 1; i++) cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}
