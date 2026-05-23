#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, time = 0, element;
  cin >> n >> k >> x;
  for (int i = 0; i < (n - k); i++) {
    cin >> element;
    time += element;
  }
  for (int i = 0; i < k; i++) {
    cin >> element;
  }
  time = time + (x * k);
  cout << time << endl;
}
