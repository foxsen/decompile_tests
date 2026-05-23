#include <bits/stdc++.h>
using namespace std;
int find(int a, int b, int k) {
  int count = 0;
  while (a > 0) {
    if (a % 2 != b % 2) count++;
    if (count > k) return 0;
    a = a / 2;
    b = b / 2;
  }
  while (b > 0) {
    if (b % 2 != 0) count++;
    if (count > k) return 0;
    b = b / 2;
  }
  return 1;
}
int check(int a, int b, int k) {
  if (a < b) return find(a, b, k);
  return find(b, a, k);
}
int main() {
  int n, m, k, tar;
  cin >> n >> m >> k;
  int arr[m];
  for (int i = 0; i < m; i++) cin >> arr[i];
  cin >> tar;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    sum = sum + check(arr[i], tar, k);
  }
  cout << sum;
  return 0;
}
