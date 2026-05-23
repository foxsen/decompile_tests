#include <bits/stdc++.h>
using namespace std;
const long long N = 100001;
vector<long long> v;
int main() {
  v.push_back(1);
  for (long long i = 1; i < 31; i++) {
    v.push_back(v[i - 1] * 2);
  }
  long long n;
  cin >> n;
  long long pos = upper_bound(v.begin(), v.end(), n) - v.begin();
  cout << pos << endl;
  return 0;
}
