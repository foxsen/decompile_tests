#include <bits/stdc++.h>
using namespace std;
class sort_map {
 public:
  int num;
  int val;
};
bool myfunc(int a, int b) { return a > b; }
int main() {
  long long n;
  cin >> n;
  vector<long long> input;
  long long mmax = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    input.push_back(temp);
    sum += temp;
    if (temp > mmax) mmax = temp;
  }
  int e = ceil(sum / (n - 1.0));
  if (e < mmax) e = mmax;
  cout << e;
  return 0;
}
