#include <bits/stdc++.h>
const int SIZE = 200005;
struct BIT {
  long long A[SIZE];
  long long sum(int i) {
    i++;
    long long sum = 0;
    while (i > 0) sum += A[i], i -= ((i) & -(i));
    return sum;
  }
  void add(int i, long long k) {
    i++;
    while (i < SIZE) A[i] += k, i += ((i) & -(i));
  }
};
int n, m;
std::vector<std::pair<int, int> > A;
std::vector<int> B, ord;
BIT b1, b2;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m;
  A.resize(n);
  B.resize(n);
  for (int i = 0; i < (n); ++i) std::cin >> A[i].first;
  for (int i = 0; i < (n); ++i) A[i].second = i, B[i] = A[i].first;
  std::sort(A.begin(), A.end());
  ord.resize(n);
  for (int i = 0; i < (n); ++i) ord[A[i].second] = i;
  for (int i = 0; i < (n); ++i) {
    long long can = m - B[i];
    int left = 0;
    int right = n;
    while (left < right) {
      int mid = (left + right) / 2;
      if (b1.sum(mid) > can)
        right = mid;
      else
        left = mid + 1;
    }
    left--;
    std::cout << i - b2.sum(left) << "\n";
    b2.add(ord[i], 1);
    b1.add(ord[i], B[i]);
  }
  return 0;
}
