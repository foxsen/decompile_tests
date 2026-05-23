#include <bits/stdc++.h>

using namespace std;


class LazySegT{
private:
  int NN;
  struct Node{
	int f, g, l, r;
	int lazy;
  };
  Node segT[2*(1<<17)-1]; // =131072
public:
  LazySegT(int n){
	NN = 1;
	while(NN < n) NN <<= 1;

	for(int i=0;i<2*NN-1;++i){
	  segT[i].f = segT[i].g = segT[i].l = segT[i].r = 0;
	  segT[i].lazy = -1;
	}
  }

  void eval(int k, int l, int r){
	if(segT[k].lazy < 0) return;
	
	segT[k].f = (r-l) * segT[k].lazy;
	segT[k].g = (r-l-1) * segT[k].lazy;
	segT[k].l = segT[k].r = segT[k].lazy;

	if(k < NN-1){
	  segT[2*k+1].lazy = segT[2*k+2].lazy = segT[k].lazy;
	}
	segT[k].lazy = -1;
  }

  void update(int a, int b, int bit, int k, int l, int r){
	eval(k,l,r);
	if(r <= a || b <= l) return;

	if(a <= l && r <= b){
	  segT[k].lazy = bit;
	  eval(k,l,r);
	}
	else{
	  int m = (l+r) / 2;
	  update(a, b, bit, k*2+1, l, m);
	  update(a, b, bit, k*2+2, m, r);

	  segT[k].f = segT[k*2+1].f + segT[k*2+2].f;
	  segT[k].g = segT[k*2+1].g + segT[k*2+2].g + segT[k*2+1].r * segT[k*2+2].l;
	  segT[k].l = segT[k*2+1].l;
	  segT[k].r = segT[k*2+2].r;
	}
  }
  void update(int a, int b, int c){
	update(a, b, c, 0, 0, NN);
  }

  int query(){
	eval(0, 0, NN);
	return segT[0].f - segT[0].g;
  }
};

int main(){
  int N; cin >> N;
  string X; cin >> X;
  int Q; cin >> Q;

  LazySegT seg(N);
  for(int i=0;i<X.size();++i){
	seg.update(i, i+1, X[i]-'0');
  }

  for(int q=0;q<Q;++q){
	int l, r, b;
	cin >> l >> r >> b;
	--l;
	seg.update(l, r, b);
	cout << seg.query() << endl;
  }
  
  return 0;
}