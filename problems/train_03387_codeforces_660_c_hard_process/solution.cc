#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000000000;
set<string> ans;
set<pair<char, string>> rep;
int main() {
  int n, k;
  cin >> n >> k;
  ;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  ;
  int numZero = 0;
  int max = 0;
  int start = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (i) numZero -= arr[i - 1] == 0 ? 1 : 0;
    while (numZero < k && j < n) {
      if (arr[j] == 0) numZero++;
      j++;
    }
    while (arr[j] == 1 && j < n) j++;
    if (j - i > max) {
      max = j - i;
      start = i;
    }
  }
  cout << max << endl;
  ;
  for (int i = start; i < start + max; i++) arr[i] = 1;
  for (int i = 0; i < n - 1; i++) cout << arr[i] << " ";
  cout << arr[n - 1] << endl;
  ;
}
