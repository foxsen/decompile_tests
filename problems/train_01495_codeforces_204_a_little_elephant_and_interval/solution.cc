#include <bits/stdc++.h>
using namespace std;
vector<long long> numbers;
long long get(string A) {
  string B;
  long long c = 0;
  B.push_back('1');
  while (B.size() < A.size()) {
    while (B[0] <= '9') {
      if (B.size() > 1)
        c += (numbers[B.size() - 2]);
      else
        c++;
      B[0]++;
    }
    B.push_back('1');
    B[0] = '1';
  }
  while (B[0] < A[0]) {
    if (B.size() > 1)
      c += (numbers[B.size() - 2]);
    else
      c++;
    B[0]++;
  }
  if (A[0] <= A[A.size() - 1]) {
    long long v = 0;
    if (A.size() > 2) {
      for (int i = 1; i < A.size() - 1; i++) {
        v *= 10;
        v += (A[i] - '0');
      }
      v++;
    }
    if (A.size() <= 2) {
      if (A[0] <= A[A.size() - 1]) v++;
    }
    return c + v;
  }
  if (A[0] > A[A.size() - 1]) {
    bool J = true;
    for (int i = 1; i < A.size() - 1; i++) {
      if (A[i] != '0') J = false;
    }
    if (!J) {
      for (int i = 1; i < A.size() - 1; i++) {
        c += ((A[i] - '0') * numbers[A.size() - i - 2]);
      }
      return c;
    } else
      return c;
  }
}
bool works(string A) {
  if (A[0] == A[A.size() - 1]) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long l, r;
  numbers.resize(20, 1);
  for (int i = 1; i < 20; i++) numbers[i] = 10 * numbers[i - 1];
  string A, B;
  cin >> A >> B;
  long long a = get(A);
  long long b = get(B);
  if (works(A))
    cout << b - a + 1 << "\n";
  else
    cout << b - a << "\n";
  return 0;
}
