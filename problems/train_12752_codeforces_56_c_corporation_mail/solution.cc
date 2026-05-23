#include <bits/stdc++.h>
using namespace std;
class Tree {
 public:
  string n;
  vector<Tree> s;
  void print(int tab = 0) {
    for (int i = 0; i < tab; i++) printf(" ");
    printf("%s\n", n.c_str());
    for (int i = 0; i < (int)s.size(); i++) s[i].print(tab + 1);
  }
  int count(string name) {
    int res = n == name;
    for (int i = 0; i < (int)s.size(); i++) res += s[i].count(name);
    return res;
  }
  int solve() {
    int res = count(n) - 1;
    for (int i = 0; i < (int)s.size(); i++) res += s[i].solve();
    return res;
  }
};
Tree read() {
  Tree res;
  char left[20], ch;
  scanf("%[^:.]%c", left, &ch);
  res.n = left;
  while (ch == ':' || ch == ',') {
    res.s.push_back(read());
    scanf("%c", &ch);
  }
  return res;
}
int main() {
  Tree t = read();
  cout << t.solve() << endl;
  return 0;
}
