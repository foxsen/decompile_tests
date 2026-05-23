#include <bits/stdc++.h>
using namespace std;
set<long long int> ans;
long long int foo(long long int n, long long int k) {
  long long int num = n / k;
  long long int ret = (num * (num - 1)) / 2;
  ret *= k;
  ret += num;
  return ret;
}
int main() {
  long long int n;
  scanf("%lld", &n);
  vector<long long int> factors;
  for (long long int i = 1; i * i <= n; i++)
    if (n % i == 0) {
      factors.push_back(i);
      factors.push_back(n / i);
    }
  for (int i = 0; i < factors.size(); i++) ans.insert(foo(n, factors[i]));
  for (auto it = (ans).begin(); it != (ans).end(); it++) printf("%lld ", *it);
  printf("\n");
  return 0;
}
