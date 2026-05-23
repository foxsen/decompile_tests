#include <bits/stdc++.h>
using namespace std;
struct kor {
  int x, d;
};
int main(int argc, char *argv[]) {
  int n;
  int ind = 0;
  cin >> n;
  kor a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].d;
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((a[i].x == (a[j].x + a[j].d)) && (a[j].x == (a[i].x + a[i].d))) {
        cout << "YES";
        ind = 1;
        j = n;
        i = n;
      }
    }
  }
  if (ind == 0) {
    cout << "NO";
  }
  return EXIT_SUCCESS;
}
