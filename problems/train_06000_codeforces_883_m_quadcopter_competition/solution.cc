#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, w;
  cin >> q >> w;
  int qq, ww;
  cin >> qq >> ww;
  vector<pair<int, int>> vpp;
  vpp.push_back(make_pair(qq - 1, ww + 1));
  vpp.push_back(make_pair(qq, ww + 1));
  vpp.push_back(make_pair(qq + 1, ww + 1));
  vpp.push_back(make_pair(qq - 1, ww));
  vpp.push_back(make_pair(qq + 1, ww));
  vpp.push_back(make_pair(qq - 1, ww - 1));
  vpp.push_back(make_pair(qq, ww - 1));
  vpp.push_back(make_pair(qq + 1, ww + 1));
  vpp.push_back(make_pair(qq, ww));
  pair<int, int> target = make_pair(q, w);
  if (find(vpp.begin(), vpp.end(), target) != vpp.end()) {
    cout << vpp.size() - 1 << endl;
  } else {
    int total1, total2, total3, total4;
    (abs(q - qq) > 1) ? total1 = abs(q - qq) : total1 = 1;
    (abs(w - ww) > 1) ? total2 = abs(w - ww) : total2 = 1;
    int total = (2 + total1 + total2) * 2;
    cout << total << endl;
  }
}
