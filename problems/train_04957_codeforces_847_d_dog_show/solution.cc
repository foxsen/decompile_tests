#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 200;
const long long inf = 2e18, mod = 1e9 + 7;
struct node {
  int key, prior, cnt, sum;
  node* l;
  node* r;
  node(int KEY = 0, int PRIOR = 0, int CNT = 1) {
    key = KEY;
    sum = cnt = CNT;
    prior = PRIOR;
    l = r = NULL;
  }
};
typedef node* pnode;
int getSum(pnode t) { return (t ? t->sum : 0); }
inline void update(pnode& t) {
  if (t) t->sum = getSum(t->l) + getSum(t->r) + t->cnt;
}
void split(pnode t, int key, pnode& l, pnode& r) {
  if (!t)
    l = r = NULL;
  else if (key < t->key)
    split(t->l, key, l, t->l), r = t;
  else
    split(t->r, key, t->r, r), l = t;
  update(t);
}
void addVal(pnode& t, int key) {
  if (t->key == key)
    t->cnt++;
  else if (key < t->key)
    addVal(t->l, key);
  else
    addVal(t->r, key);
  update(t);
}
void insert(pnode& t, pnode it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior) {
    split(t, it->key, it->l, it->r), t = it;
  } else
    insert((it->key < t->key ? t->l : t->r), it);
  update(t);
}
void merge(pnode& t, pnode& l, pnode& r) {
  if (!l || !r)
    t = (l ? l : r);
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
  update(t);
}
void erase(pnode& t, int key) {
  if (!t) return;
  if (t->key == key)
    merge(t, t->l, t->r);
  else
    erase((key < t->key ? t->l : t->r), key);
  update(t);
}
int query(pnode t, int key) {
  if (!t) return 0;
  if (key < t->key)
    return query(t->l, key);
  else if (key == t->key)
    return getSum(t->l);
  else
    return getSum(t->l) + t->cnt + query(t->r, key);
}
void print(pnode t) {
  if (!t) return;
  cerr << "P " << t->key << ' ' << t->sum << endl;
  print(t->l);
  print(t->r);
}
node treapNodes[maxn];
pnode TREAP;
set<int> st;
int n, T, cool[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(time(NULL));
  for (int i = 0; i < maxn; i++) treapNodes[i].prior = rand() % mod;
  cin >> n >> T;
  for (int i = 0; i < n; i++) cin >> cool[i];
  for (int i = 0; i < n; i++) cool[i] = max(0, cool[i] - i - 1);
  int ind = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    treapNodes[ind].key = cool[i];
    if (st.find(cool[i]) == st.end()) {
      insert(TREAP, treapNodes + ind);
      st.insert(cool[i]);
    } else {
      addVal(TREAP, cool[i]);
    }
    ind++;
    ans = max(ans, query(TREAP, T - i - 1));
  }
  cout << ans << endl;
}
