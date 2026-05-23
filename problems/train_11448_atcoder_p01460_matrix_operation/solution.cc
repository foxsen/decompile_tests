#include <bits/stdc++.h>
using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

const int INF=1e9;
const int MOD=1e9+7;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}
template<typename T>
ostream& operator<<(ostream& os,const deque<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

struct Indices{
	vl data;
	bool reversed;
	Indices(int n):data(n),reversed(false){
		iota(all(data),0);
	}
	ll& operator[](int i){
		return reversed?data[data.size()-1-i]:data[i];
	}
};

struct Matrix{
	const int n,A,B,C,D,E,F,G;
	int dir; // 反時計回りに回した回数 mod 4
	Indices fr,fc;
	map<tuple<int,int>,int> val;
	Matrix(int n,int A,int B,int C,int D,int E,int F,int G)
		:n(n),A(A),B(B),C(C),D(D),E(E),F(F),G(G),dir(0),fr(n),fc(n){
	}
	void Set(int i,int j,int x){ // WR
		if(dir==0) tie(i,j)=mt(fr[i],fc[j]);
		if(dir==1) tie(i,j)=mt(fr[j],fc[n-1-i]);
		if(dir==2) tie(i,j)=mt(fr[n-1-i],fc[n-1-j]);
		if(dir==3) tie(i,j)=mt(fr[n-1-j],fc[i]);
		val[mt(i,j)]=x;
	}
	void SwapRow(int i1,int i2){ // SR
		if(dir==0) swap(fr[i1],fr[i2]);
		if(dir==1) swap(fc[n-1-i1],fc[n-1-i2]);
		if(dir==2) swap(fr[n-1-i1],fr[n-1-i2]);
		if(dir==3) swap(fc[i1],fc[i2]);
	}
	void SwapColumn(int j1,int j2){ // SC
		if(dir==0) swap(fc[j1],fc[j2]);
		if(dir==1) swap(fr[j1],fr[j2]);
		if(dir==2) swap(fc[n-1-j1],fc[n-1-j2]);
		if(dir==3) swap(fr[n-1-j1],fr[n-1-j2]);
	}
	void RotateLeft(){ // RL
		dir=(dir+1)%4;
	}
	void RotateRight(){ // RR
		dir=(dir+3)%4;
	}
	void ReverseRow(){ // RH
		if(dir==0 || dir==2) fr.reversed^=1;
		if(dir==1 || dir==3) fc.reversed^=1;
	}
	void ReverseColumn(){ // RV
		if(dir==0 || dir==2) fc.reversed^=1;;
		if(dir==1 || dir==3) fr.reversed^=1;;
	}
	int Get(int i,int j){
		if(dir==0) tie(i,j)=mt(fr[i],fc[j]);
		if(dir==1) tie(i,j)=mt(fr[j],fc[n-1-i]);
		if(dir==2) tie(i,j)=mt(fr[n-1-i],fc[n-1-j]);
		if(dir==3) tie(i,j)=mt(fr[n-1-j],fc[i]);
		if(val.count(mt(i,j)))
			return val[mt(i,j)];
		else
			return (ll(i+1)*A+ll(j+1)*B)%C;
	};
	int Hash(){
		int h=314159265;
		repi(i,D-1,E) repi(j,F-1,G){
			//dump(vi({fr[i],fc[j],Get(i,j)}));
			h=(31ll*h+Get(i,j))%MOD;
		}
		return h;
	}
	void Print(){
		rep(i,n){
			rep(j,n) cout<<Get(i,j)<<' ';
			cout<<endl;
		}
	}
};

int main()
{
	for(int n,q;cin>>n>>q && n|q;){
		int A,B,C,D,E,F,G; cin>>A>>B>>C>>D>>E>>F>>G;
		Matrix mat(n,A,B,C,D,E,F,G);
		rep(_,q){
			string op; cin>>op;
			if(op=="WR"){
				int r,c,v; cin>>r>>c>>v; r--,c--;
				mat.Set(r,c,v);
			}
			if(op=="CP"){
				int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2; r1--,c1--,r2--,c2--;
				mat.Set(r2,c2,mat.Get(r1,c1));
			}
			if(op=="SR"){
				int r1,r2; cin>>r1>>r2; r1--,r2--;
				mat.SwapRow(r1,r2);
			}
			if(op=="SC"){
				int c1,c2; cin>>c1>>c2; c1--,c2--;
				mat.SwapColumn(c1,c2);
			}
			if(op=="RL") mat.RotateLeft();
			if(op=="RR") mat.RotateRight();
			if(op=="RH") mat.ReverseRow();
			if(op=="RV") mat.ReverseColumn();
		}
		cout<<mat.Hash()<<endl;
	}
}