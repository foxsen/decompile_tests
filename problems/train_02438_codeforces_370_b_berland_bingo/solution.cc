#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<bitset<102> > cards;
  vector<int> size;
  for (int i = 0; i < n; i++) {
    int m, x;
    cin >> m;
    size.push_back(m);
    bitset<102> aux;
    for (int j = 0; j < m; j++) {
      cin >> x;
      aux[x] = true;
    }
    cards.push_back(aux);
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    flag = false;
    bitset<102> aux;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      aux = cards[i] & cards[j];
      int lit = aux.count();
      if (lit > 0) {
        if (size[j] - lit == 0) {
          flag = true;
          cout << "NO" << endl;
          break;
        } else if (size[i] - lit == 0 && size[j] - lit == 0) {
          flag = true;
          cout << "NO" << endl;
          break;
        }
      }
    }
    if (!flag) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
