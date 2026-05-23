#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  char name[1010][50];
  int num[1010];
  int mx = 0;
  map<string, int> m1, m2;
  for (int i = 0; i < test; i++) {
    cin >> name[i] >> num[i];
    m1[name[i]] += num[i];
  }
  for (int i = 0; i < test; i++) {
    mx = max(mx, m1[name[i]]);
  }
  int j;
  for (j = 0; j < test; j++) {
    m2[name[j]] += num[j];
    if (m1[name[j]] == mx && m2[name[j]] >= mx) {
      break;
    }
  }
  cout << name[j] << endl;
}
