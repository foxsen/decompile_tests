#include <bits/stdc++.h>
using namespace std;
int trie[100500][26] = {};
int sz = 1;
int addNode() { return sz++; }
void addWord(string s, int root = 0) {
  for (char ch : s) {
    if (trie[root][ch - 'a'] == 0) trie[root][ch - 'a'] = addNode();
    root = trie[root][ch - 'a'];
  }
}
pair<int, int> dfs(int n) {
  bool leaf = true;
  pair<int, int> p(false, false), pp;
  for (int i = 0; i < 26; i++) {
    if (trie[n][i] != 0) {
      leaf = false;
      pp = dfs(trie[n][i]);
      p.first = p.first | !pp.first;
      p.second = p.second | !pp.second;
    }
  }
  if (leaf) p.second = true;
  return p;
}
int main(void) {
  int n;
  int k;
  cin >> n >> k;
  addNode();
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    addWord(s);
  }
  auto p = dfs(0);
  int win = p.first;
  int loose = p.second;
  if (k == 1 && win)
    cout << "First" << endl;
  else if (k == 1 && !win)
    cout << "Second" << endl;
  else if (!win)
    cout << "Second" << endl;
  else if (win && loose)
    cout << "First" << endl;
  else if (k % 2 == 1)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
