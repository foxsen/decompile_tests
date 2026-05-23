#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 112345;
constexpr int MAXSEQ = 2 * (MAXN - 1);
constexpr int MAXNODES = 4 * MAXSEQ;
struct Node {
  int maxc, minc, p, s, v, lazy;
  void show() {
    cerr << "{" << endl;
    cerr << "maxc"
         << " == " << (maxc) << endl;
    ;
    cerr << "minc"
         << " == " << (minc) << endl;
    ;
    cerr << "p"
         << " == " << (p) << endl;
    ;
    cerr << "s"
         << " == " << (s) << endl;
    ;
    cerr << "v"
         << " == " << (v) << endl;
    ;
    cerr << "lazy"
         << " == " << (lazy) << endl;
    ;
    cerr << "}" << endl;
  }
};
Node tree[MAXNODES];
void fix(int L, int R, int ID);
void showTree(int L, int R, int ID) {
  cerr << "[" << L << ", " << R << "] : " << ID << endl;
  tree[ID].show();
  cerr << endl;
  if (L < R) {
    int mid = (L + R) / 2;
    fix(L, R, ID);
    showTree(L, mid, 2 * ID + 1);
    showTree(mid + 1, R, 2 * ID + 2);
  }
}
Node join(const Node& L, const Node& R) {
  Node ans;
  ans.lazy = 0;
  ans.maxc = max(L.maxc, R.maxc);
  ans.minc = min(L.minc, R.minc);
  ans.p = max(L.p, R.p);
  ans.p = max(ans.p, L.maxc - 2 * R.minc);
  ans.s = max(L.s, R.s);
  ans.s = max(ans.s, R.maxc - 2 * L.minc);
  ans.v = max(L.v, R.v);
  ans.v = max(ans.v, L.maxc + R.s);
  ans.v = max(ans.v, L.p + R.maxc);
  return ans;
}
void calc(int L, int R, int ID) {
  if (L >= R) return;
  const int IDL = 2 * ID + 1, IDR = 2 * ID + 2;
  tree[ID] = join(tree[IDL], tree[IDR]);
}
void build(int L, int R, int ID) {
  if (L >= R) {
    tree[ID].p = tree[ID].s = tree[ID].v = -MAXSEQ;
    return;
  }
  int mid = (L + R) / 2;
  build(mid + 1, R, 2 * ID + 2);
  calc(L, R, ID);
}
void update(int a, int b, int x, int L, int R, int ID) {
  if (a > R or b < L) return;
  if (a <= L and b >= R) {
    tree[ID].maxc += x;
    tree[ID].minc += x;
    tree[ID].p -= x;
    tree[ID].s -= x;
    tree[ID].lazy += x;
    return;
  }
  fix(L, R, ID);
  int mid = (L + R) / 2;
  update(a, b, x, L, mid, 2 * ID + 1);
  update(a, b, x, mid + 1, R, 2 * ID + 2);
  calc(L, R, ID);
}
Node query(int a, int b, int L, int R, int ID) {
  if (a > R or b < L) {
    Node bad;
    bad.maxc = -MAXSEQ;
    bad.minc = MAXSEQ;
    bad.v = bad.p = bad.s = -MAXSEQ;
    return bad;
  }
  if (a <= L and b >= R) {
    return tree[ID];
  }
  fix(L, R, ID);
  int mid = (L + R) / 2;
  const int IDL = 2 * ID + 1, IDR = 2 * ID + 2;
  Node AL = query(a, b, L, mid, IDL);
  Node AR = query(a, b, mid + 1, R, IDR);
  return join(AL, AR);
}
void fix(int L, int R, int ID) {
  if (L >= R or not tree[ID].lazy) return;
  int mid = (L + R) / 2;
  update(L, mid, tree[ID].lazy, L, mid, 2 * ID + 1);
  update(mid + 1, R, tree[ID].lazy, mid + 1, R, 2 * ID + 2);
  tree[ID].lazy = 0;
}
int n, S;
string seq;
void add(int i) {
  if (seq[i] == '(') {
    update(i + 1, S, 1, 0, S, 0);
  } else {
    update(i + 1, S, -1, 0, S, 0);
  }
}
void remove(int i) {
  if (seq[i] == '(') {
    update(i + 1, S, -1, 0, S, 0);
  } else {
    update(i + 1, S, 1, 0, S, 0);
  }
}
int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> n >> q;
  cin >> seq;
  S = 2 * (n - 1);
  build(0, S, 0);
  for (int i = 0; i < S; i++) {
    add(i);
  }
  cout << query(0, S, 0, S, 0).v << '\n';
  for (int qi = 0; qi < q; qi++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    remove(a);
    remove(b);
    swap(seq[a], seq[b]);
    add(a);
    add(b);
    cout << query(0, S, 0, S, 0).v << '\n';
  }
}
