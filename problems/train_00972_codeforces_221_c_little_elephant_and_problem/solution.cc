#include <bits/stdc++.h>
using namespace std;
void swap(int &x, int &y) {
  int t = x;
  x = y;
  y = t;
}
int main() {
  int n;
  cin >> n;
  int *p = new int[n];
  vector<int> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    k.push_back(p[i]);
  }
  sort(k.begin(), k.end());
  int count = 0;
  for (int i = 0; i < n; i++)
    if (p[i] != k[i]) count++;
  if (count < 3)
    cout << "YES";
  else
    cout << "NO";
  delete[] p;
  return 0;
}
