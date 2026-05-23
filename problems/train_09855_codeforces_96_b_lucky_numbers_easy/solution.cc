#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
bool super(long long x) {
  int a = 0, b = 0;
  while (x) {
    if (x % 10 == 4)
      a += 1;
    else
      b += 1;
    x /= 10;
  }
  return a == b;
}
int main() {
  int n;
  cin >> n;
  queue<long long> q;
  q.push(4);
  q.push(7);
  while (q.front() < 100000000000) {
    long long x = q.front();
    q.push(x * 10 + 4);
    q.push(x * 10 + 7);
    if (super(x)) v.push_back(x);
    q.pop();
  }
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] >= n) return cout << v[i] << endl, 0;
  }
  return 0;
}
