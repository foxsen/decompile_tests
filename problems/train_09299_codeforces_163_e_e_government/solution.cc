#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000005;
struct node {
  node* fail;
  node* next[26];
  int lo, hi;
  vector<node*> link;
  node() {
    fail = NULL;
    for (int i = 0; i < 26; i++) next[i] = NULL;
  }
};
int T, n;
char text[MaxN];
node* root = new node();
queue<node*> Q;
int fenwick[10 * MaxN], gtime;
bool erased[MaxN];
node* ptr[MaxN];
void insert(char* patt, int index) {
  node* current = root;
  for (int j = 0; patt[j]; j++) {
    if (current->next[patt[j] - 'a'] == NULL)
      current->next[patt[j] - 'a'] = new node();
    current = current->next[patt[j] - 'a'];
  }
  ptr[index] = current;
}
void ahoC() {
  root->fail = root;
  for (int i = 0; i < 26; i++)
    if (root->next[i] != NULL) {
      root->next[i]->fail = root;
      Q.push(root->next[i]);
      root->link.push_back(root->next[i]);
    } else
      root->next[i] = root;
  while (!Q.empty()) {
    node* state = Q.front();
    Q.pop();
    for (int i = 0; i < 26; i++)
      if (state->next[i] != NULL) {
        node* r = state->fail;
        while (r->next[i] == NULL) r = r->fail;
        state->next[i]->fail = r->next[i];
        r->next[i]->link.push_back(state->next[i]);
        Q.push(state->next[i]);
      }
  }
}
void dfs(node* u) {
  u->lo = ++gtime;
  for (int i = u->link.size() - 1; i >= 0; i--) dfs(u->link[i]);
  u->hi = ++gtime;
}
void add(int k, int val) {
  for (int i = k; i <= gtime; i += (i & -i)) fenwick[i] += val;
}
int query(node* u) {
  int ret = 0;
  for (int i = u->lo; i > 0; i -= (i & -i)) ret = ret + fenwick[i];
  return ret;
}
void update(int index, int val) {
  if (erased[index] && val == -1) return;
  if (!erased[index] && val == +1) return;
  add(ptr[index]->lo, val);
  add(ptr[index]->hi, -val);
  erased[index] = !erased[index];
}
int main() {
  scanf("%d%d", &T, &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", text);
    insert(text, i);
  }
  ahoC();
  dfs(root);
  for (int i = 0; i < n; i++) {
    erased[i] = true;
    update(i, +1);
  }
  while (T--) {
    scanf("%s", text);
    if (text[0] == '+' || text[0] == '-') {
      int index;
      sscanf(text + 1, "%d", &index);
      update(index - 1, (text[0] == '+') ? +1 : -1);
    } else {
      long long answer = 0;
      node* current = root;
      for (int i = 1; text[i]; i++) {
        while (current->next[text[i] - 'a'] == NULL) current = current->fail;
        current = current->next[text[i] - 'a'];
        answer += query(current);
      }
      printf("%I64d\n", answer);
    }
  }
  return 0;
}
