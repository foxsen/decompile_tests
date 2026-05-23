#include <bits/stdc++.h>
using namespace std;
int gnc(int a, int b);
int compare(const void *a, const void *b);
int main() {
  map<int, int> dp;
  int n;
  cin >> n;
  pair<int, int> *data = new pair<int, int>[n];
  for (int i = 0; i < n; i++) cin >> data[i].first;
  for (int i = 0; i < n; i++) cin >> data[i].second;
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    map<int, int>::iterator it;
    for (it = dp.begin(); it != dp.end(); it++) {
      int nod = gnc((*it).first, data[i].first);
      map<int, int>::iterator it1 = dp.find(nod);
      if (it1 == dp.end()) dp[nod] = (*it).second + data[i].second;
      if (dp[nod] > (*it).second + data[i].second)
        dp[nod] = (*it).second + data[i].second;
    }
  }
  map<int, int>::iterator it = dp.find(1);
  if (it == dp.end()) {
    cout << "-1";
    return 0;
  }
  cout << (*it).second;
  return 0;
}
int gnc(int a, int b) {
  while (a != 0 && b != 0) {
    if (a > b)
      a = a % b;
    else
      b = b % a;
  }
  return a + b;
}
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
