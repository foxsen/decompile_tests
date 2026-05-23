#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int t, c;
  vector<int> T(N - 1);
  vector<int> C(N - 1);
  cin >> t;
  int a = t;
  for (int i = 0; i < N - 1; i++) {
    int b;
    cin >> b;
    T[i] = abs(b - a);
    a = b;
  }
  cin >> c;
  int w = c;
  for (int i = 0; i < N - 1; i++) {
    int b;
    cin >> b;
    C[i] = abs(w - b);
    w = b;
  }
  if (c != t || a != w) {
    cout << "No";
  } else {
    sort(T.begin(), T.end());
    sort(C.begin(), C.end());
    for (int i = 0; i < N - 1; i++) {
      if (C[i] != T[i]) {
        cout << "No";
        return 0;
      }
    }
    cout << "Yes";
  }
  return 0;
}
