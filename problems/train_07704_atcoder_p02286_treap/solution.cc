#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

using namespace std;

template <typename T> T &chmin(T &a, const T &b) {return a = min(a, b);}
template <typename T> T &chmax(T &a, const T &b) {return a = max(a, b);}

using ll = long long;
using ld = long double;

const int INF = 1e9;
const ld eps = 1e-9, pi = acos(-1.0);

struct Node{
  int k;
  int p;
  Node* lc = NULL;
  Node* rc = NULL;
  Node(int k, int p) : k(k), p(p){}
};

Node* rightRotate(Node* n){
  Node* l = n->lc;
  if(l!=NULL){
    n->lc = l->rc;
    l->rc = n;
  }
  return l;
}

Node* leftRotate(Node* n){
  Node* r = n->rc;
  if(r!=NULL){
    n->rc = r->lc;
    r->lc = n;
  }
  return r;
}

void preorder(Node* n){
  if(n==NULL) return;
  cout << " " << n->k;
  preorder(n->lc);
  preorder(n->rc);
  return;
}

void inorder(Node* n){
  if(n==NULL) return;
  inorder(n->lc);
  cout << " " << n->k;
  inorder(n->rc);
  return;
}

Node* ins(Node* n, int k, int p){
  if(n==NULL) { return new Node(k, p); }
  if(k==n->k) return n;
  if(k<n->k){
    n->lc = ins(n->lc, k, p);
    if(n->p<n->lc->p) n = rightRotate(n);
  } else {
    n->rc = ins(n->rc, k, p);
    if(n->p<n->rc->p) n = leftRotate(n);
  }
  return n;
}

bool fnd(Node* n, int k){
  if(n==NULL) return false;
  if(n->k==k) return true;
  return (n->k>k ? fnd(n->lc, k) : fnd(n->rc, k));
}

Node* del(Node* n, int k);

Node* exec_del(Node* n,int k){
  if(n->lc==NULL && n->rc==NULL) { delete n; return NULL; }
  if(n->lc==NULL) n = leftRotate(n);
  else if(n->rc==NULL) n = rightRotate(n);
  else{
    if(n->lc->p > n->rc->p) n = rightRotate(n);
    else n = leftRotate(n);
  }
  return del(n, k);
}

Node* del(Node* n, int k){
  if(n==NULL) return NULL;
  if(k<n->k) n->lc = del(n->lc, k);
  else if(k>n->k) n->rc = del(n->rc, k);
  else return exec_del(n, k);
  return n;
}

void prt(Node* n){
  inorder(n);
  cout << endl;
  preorder(n);
  cout << endl;
  return;
}

int main(){
  int n;
  cin >> n;
  char str[10];
  int k, p;
  Node* top = NULL;
  REP(i, n){
    scanf("%s", str);
    if(str[0]=='i'){
      cin >> k >> p;
      top = ins(top, k, p);
    } else if (str[0]=='f'){
      cin >> k;
      cout << (fnd(top, k) ? "yes" : "no") << endl;
    } else if (str[0]=='d'){
      cin >> k;
      top = del(top, k);
    } else {
      prt(top);
    }
  }
  return 0;
}
