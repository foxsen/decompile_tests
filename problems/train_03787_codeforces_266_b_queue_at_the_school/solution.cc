#include <bits/stdc++.h>
using namespace std;
vector<char> vecs;
int a, b;
void show() {
  for (int i = 0; i < a; i++) {
    cout << vecs[i];
    if (i == vecs.size() - 1) cout << endl;
  }
}
int main() {
  while (cin >> a >> b) {
    vecs.clear();
    for (int i = 0; i < a; i++) {
      char t;
      cin >> t;
      vecs.push_back(t);
    }
    int tmp = 1;
    int khers = b;
    while (b--) {
      for (int i = vecs.size() - 1; i > 0; i--) {
        if (vecs[i] == 'G' && vecs[i - 1] == 'B') {
          vecs[i] = 'B';
          vecs[i - 1] = 'G';
          i--;
        }
      }
    }
    show();
  }
  return 0;
}
