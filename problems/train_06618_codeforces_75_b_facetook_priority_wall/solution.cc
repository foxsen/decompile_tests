#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
string me;
map<string, int> M;
string word[MAXN];
struct node {
  string name;
  int v;
  node() {
    name = "";
    v = 0;
  }
} relate[MAXN];
bool operator<(const node &a, const node &b) {
  if (a.v == b.v)
    return a.name < b.name;
  else
    return a.v > b.v;
}
int cnt, n;
int get(const string &x) {
  if (M.find(x) == M.end()) {
    M[x] = ++cnt;
    relate[cnt].name = x;
  }
  return M[x];
}
char act[10000];
int main() {
  string tmp;
  cnt = 0;
  cin >> me;
  get(me);
  scanf("%d", &n);
  gets(act);
  for (int i = 0; i < n; i++) {
    gets(act);
    istringstream ss(act);
    int m = 0;
    while (ss >> tmp) {
      word[++m] = tmp;
    }
    word[m - 1] = word[m - 1].substr(0, word[m - 1].size() - 2);
    int a = get(word[1]);
    int b = get(word[m - 1]);
    int tar;
    if (a == 1 || b == 1) {
      tar = (a == 1) ? b : a;
      if (word[2] == "posted") {
        relate[tar].v += 15;
      } else if (word[2] == "commented") {
        relate[tar].v += 10;
      } else if (word[2] == "likes") {
        relate[tar].v += 5;
      }
    }
  }
  sort(relate + 2, relate + cnt + 1);
  for (int i = 2; i <= cnt; i++) cout << relate[i].name << endl;
}
