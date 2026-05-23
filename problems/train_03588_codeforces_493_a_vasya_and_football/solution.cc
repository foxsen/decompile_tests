#include <bits/stdc++.h>
using namespace std;
int main() {
  string h, a;
  cin >> h >> a;
  int n;
  cin >> n;
  int time[n], pno[n];
  char team[n], card[n];
  int hp[100], ap[100];
  for (int i = 1; i <= 99; i++) {
    hp[i] = 0;
    ap[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> time[i] >> team[i] >> pno[i] >> card[i];
    if (team[i] == 'h') {
      if (hp[pno[i]] == 0 && card[i] == 'y') {
        hp[pno[i]] = 1;
      } else {
        if (hp[pno[i]] != 5) {
          cout << h << " " << pno[i] << " " << time[i] << endl;
          hp[pno[i]] = 5;
        }
      }
    } else {
      if (ap[pno[i]] == 0 && card[i] == 'y') {
        ap[pno[i]] = 1;
      } else {
        if (ap[pno[i]] != 5) {
          cout << a << " " << pno[i] << " " << time[i] << endl;
          ap[pno[i]] = 5;
        }
      }
    }
  }
  return 0;
}
