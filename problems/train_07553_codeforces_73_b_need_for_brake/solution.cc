#include <bits/stdc++.h>
using namespace std;
struct man {
  string name;
  int score;
  man() {}
  man(string nname, int nscore) : name(nname), score(nscore) {}
  bool operator<(const man &m) const {
    if (score != m.score) return score > m.score;
    return name < m.name;
  }
  bool operator>(const man &m) const {
    if (score != m.score) return score < m.score;
    return name > m.name;
  }
  man operator+(const int x) const { return man(name, score + x); }
};
namespace std {
istream &operator>>(istream &in, man &m) { return in >> m.name >> m.score; }
}  // namespace std
int n, m, win[110000];
man data[110000];
string name;
int findName(string name) {
  for (int i = 0; i < n; i++)
    if (data[i].name == name) return i;
  return -1;
}
int findMax() {
  sort(data, data + n), sort(win, win + n);
  int id = findName(name), given = 0;
  data[id] = data[id] + win[n - 1];
  for (int i = 0; i < n && given < n - 1; i++) {
    if (i == id) continue;
    if (data[i] + win[given] > data[id]) given++;
  }
  data[id] = data[id] + (-win[n - 1]);
  return n - given;
}
int findMin() {
  sort(data, data + n, greater<man>()), sort(win, win + n, greater<int>());
  int id = findName(name), given = 0;
  data[id] = data[id] + win[n - 1];
  for (int i = 0; i < n && given < n - 1; i++) {
    if (i == id) continue;
    if (data[i] + win[given] < data[id]) given++;
  }
  data[id] = data[id] + (-win[n - 1]);
  return given + 1;
}
int main() {
  cin >> n, fill(win, win + n, 0);
  for (int i = 0; i < n; i++) cin >> data[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> win[i];
  cin >> name;
  cout << findMax() << " " << findMin();
  return 0;
}
