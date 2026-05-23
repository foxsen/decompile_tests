#include <bits/stdc++.h>
using namespace std;
const int ALPHA = 26;
struct trie {
  int cnt;
  bool fl;
  trie* children[ALPHA];
  trie() {
    cnt = fl = 0;
    for (int i = 0; i < ALPHA; i++) {
      children[i] = nullptr;
    }
  }
};
int solve(trie* root, string s) {
  int ans = (int)s.size();
  int fs = -1;
  trie* cur = root;
  for (int i = 0; i < (int)s.size(); i++) {
    if (cur != root && cur->cnt == 1 && fs == -1) {
      fs = i;
    }
    int let = s[i] - 'a';
    if ((cur->fl) > 0 && fs != -1) {
      ans = min(ans, (fs + 1) + ((int)s.size() - i));
    }
    if (cur->children[let] == nullptr) cur->children[let] = new trie();
    cur = cur->children[let];
  }
  if (cur->fl && fs != -1) {
    ans = min(ans, fs + 1);
  } else {
    cur->fl = true;
    cur = root;
    for (char c : s) {
      cur->cnt += 1;
      int let = c - 'a';
      cur = cur->children[let];
    }
    cur->cnt += 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<string> words;
  string line, whole_text = "";
  while (getline(cin, line)) {
    whole_text += (line + "\n");
  }
  string w = "";
  int answer = 0;
  int ID = 0;
  for (char c : whole_text) {
    if (isalpha(c))
      w += c;
    else {
      if (w != "") {
        words.push_back(w);
        w = "";
      }
      answer += 1;
    }
  }
  trie* root = new trie();
  for (string& word : words) {
    int s = solve(root, word);
    answer += s;
  }
  printf("%d\n", answer);
  return 0;
}
