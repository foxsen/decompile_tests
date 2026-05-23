#include <bits/stdc++.h>
using namespace std;
vector<string> token(string a) {
  vector<string> w;
  a.push_back(' ');
  while (!a.empty()) {
    w.push_back(a.substr(0, a.find(" ")));
    a = a.substr(a.find(" ") + 1, a.size() - 1);
  }
  return w;
}
map<string, int> mapik;
vector<string> amapik;
int dodaj(string a) {
  if (mapik.count(a) == 0) {
    mapik[a] = mapik.size() - 1;
    amapik.push_back(a);
  }
  return mapik[a];
}
char tmp_str[1000];
string scanf_string() {
  scanf("%s", tmp_str);
  return tmp_str;
}
const int N = 1000;
int n;
int main() {
  scanf("%d", &n);
  int inches = (n + 1) / 3;
  printf("%d %d\n", inches / 12, inches % 12);
  return 0;
}
