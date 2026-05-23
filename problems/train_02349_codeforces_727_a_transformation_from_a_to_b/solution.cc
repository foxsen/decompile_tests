#include <bits/stdc++.h>
using namespace std;
int p[10003] = {}, arr[10003] = {};
void prime() {
  p[0] = p[1] = 1;
  for (int i = 2; i < 10000; i++) {
    if (p[i] == 0) {
      for (int j = i * i; j < 10000; j += i) {
        if (p[j] == 0) p[j] = 1;
      }
    }
  }
  int m = 0;
  for (int i = 2; i < 10000; i++) {
    arr[i] = arr[i - 1];
    if (p[i] == 0) arr[i] += i;
  }
  for (int i = 0; i < 100; i++) cout << i << ":" << arr[i] << endl;
}
int recurse(long long int a, long long int b, vector<long long int> v) {
  if (a >= b) {
    if (a == b) {
      cout << "YES" << endl;
      int s = v.size();
      cout << s << endl;
      vector<long long int>::iterator it;
      for (it = v.begin(); it != v.end(); it++) cout << *it << " ";
      return 1;
    }
    return 0;
  }
  vector<long long int> t;
  t = v;
  t.push_back(a * 2);
  if (recurse(a * 2, b, t)) return 1;
  t = v;
  t.push_back(a * 10 + 1);
  if (recurse(a * 10 + 1, b, t)) return 1;
  return 0;
}
int main() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> v;
  v.push_back(n);
  int f = recurse(n, m, v);
  if (!f) cout << "NO";
}
