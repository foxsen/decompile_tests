#include <bits/stdc++.h>
using namespace std;
struct Treap {
  int key, p, lz;
  Treap *l, *r;
  Treap() {}
  Treap(int key) {
    this->key = key, this->p = rand();
    l = r = NULL;
    lz = 0;
  }
  void unlz() {
    key += lz;
    if (l) l->lz += lz;
    if (r) r->lz += lz;
    lz = 0;
  }
  int size() {
    int sz = 1;
    if (l) sz += l->size();
    if (r) sz += r->size();
    return sz;
  }
  int getmin() {
    unlz();
    int res = key;
    if (l) res = l->getmin();
    return res;
  }
} * Root;
typedef Treap *tr;
void split(tr root, int k, tr &L, tr &R) {
  if (!root) {
    L = R = NULL;
    return;
  }
  root->unlz();
  if (k >= root->key)
    split(root->r, k, root->r, R), L = root;
  else
    split(root->l, k, L, root->l), R = root;
}
tr merge(tr A, tr B) {
  if (A) A->unlz();
  if (B) B->unlz();
  if (!A || !B) return (A ? A : B);
  if (A->p > B->p) {
    A->r = merge(A->r, B);
    return A;
  } else {
    B->l = merge(A, B->l);
    return B;
  }
}
void insert(tr &root, tr item) {
  if (!root) {
    root = item;
    return;
  }
  root->unlz();
  if (item->p > root->p)
    split(root, item->key, item->l, item->r), root = item;
  else
    insert(item->key < root->key ? root->l : root->r, item);
}
void erase(tr &root, int k) {
  if (!root) return;
  root->unlz();
  if (root->key == k) {
    tr newr = merge(root->l, root->r);
    delete root;
    root = newr;
  } else if (k < root->key)
    erase(root->l, k);
  else
    erase(root->r, k);
}
void update(int l, int r) {
  tr L, mid, R, aux;
  split(Root, l - 1, L, aux);
  split(aux, r - 1, mid, R);
  if (R) erase(R, R->getmin());
  if (mid) mid->lz++;
  Root = merge(L, merge(mid, R));
  insert(Root, new Treap(l));
}
int N;
int main() {
  srand(time(0));
  insert(Root, new Treap(0));
  cin >> N;
  while (N--) {
    int l, r;
    cin >> l >> r;
    update(l, r);
  }
  cout << Root->size() - 1 << "\n";
  return 0;
}
