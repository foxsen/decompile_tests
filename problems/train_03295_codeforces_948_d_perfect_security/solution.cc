#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
  int cnt;
  TrieNode *arr[2];
};
TrieNode *newNode() {
  TrieNode *temp = new TrieNode;
  temp->cnt = 0;
  temp->arr[0] = temp->arr[1] = NULL;
  return temp;
}
void insert(TrieNode *root, int pre_xor) {
  TrieNode *temp = root;
  for (int i = 32 - 1; i >= 0; i--) {
    bool val = pre_xor & (1 << i);
    if (temp->arr[val] == NULL) {
      temp->arr[val] = newNode();
    }
    temp = temp->arr[val];
    temp->cnt += 1;
  }
}
int query(TrieNode *root, int pre_xor) {
  TrieNode *temp = root;
  int ans = 0;
  for (int i = 32 - 1; i >= 0; i--) {
    bool val = pre_xor & (1 << i);
    if ((temp->arr[val] != NULL) && (temp->arr[val]->cnt) > 0) {
      temp = temp->arr[val];
      ans += val * (1 << i);
    } else if ((temp->arr[1 - val]) != NULL && (temp->arr[1 - val]->cnt) > 0) {
      temp = temp->arr[1 - val];
      ans += (1 - val) * (1 << i);
    }
    temp->cnt -= 1;
  }
  return pre_xor ^ ans;
}
int main() {
  int n;
  cin >> n;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    a.push_back(u);
  }
  TrieNode *root = newNode();
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    insert(root, v);
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int u = a[i];
    ans.push_back(query(root, u));
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
