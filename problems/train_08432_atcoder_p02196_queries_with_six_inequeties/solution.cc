#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,"Line:",__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

void print(ll x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<endl;
	#else
	cout<<"Possible"<<endl;
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<endl;
	#else
	cout<<"Impossible"<<endl;
	#endif
	if(ex)exit(0);
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
int mask(int i){
	return (int(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static random_device rd;
    static mt19937_64 gen(rd());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

//CF Global3 H
//ARC073 F
//point update
template<class T,class F>
struct SegTree{
	vc<T> buf;
	int s;
	const F f;
	const T g;
	SegTree(F ff,T gg):f(ff),g(gg){}
	void init(const vc<T>& d){
		int n=d.size();
		s=1;
		while(s<n)s*=2;
		buf.resize(s*2,g);
		rep(i,n)
			buf[i+s]=d[i];
		gnr(i,1,s)
			u(i);
	}
	SegTree(const vc<T>& d,F ff,T gg):f(ff),g(gg){
		init(d);
	}
	void u(int i){
		buf[i]=f(buf[i*2],buf[i*2+1]);
	}
	void set(int i,T t){
		i+=s;
		buf[i]=t;
		while(i>>=1)u(i);
	}
	void upd(int i,T t){
		i+=s;
		buf[i]=f(buf[i],t);
		while(i>>=1)u(i);
	}
	T get(int b,int e,int l,int r,int i){
		if(e<=l||r<=b)return g;
		if(b<=l&&r<=e)return buf[i];
		int m=(l+r)/2;
		return f(get(b,e,l,m,i*2),get(b,e,m,r,i*2+1));
	}
	T get(int b,int e){
		return get(b,e,0,s,1);
	}
};

template<class t,class F>
struct Point1D{
	SegTree<t,F> seg;
	vi pos;
	const t g;
	Point1D(F ff,t gg):seg(ff,gg),g(gg){}
	void addp(int p){
		pos.pb(p);
	}
	void init(){
		mkuni(pos);
		seg.init(vc<t>(pos.size(),g));
	}
	int idx(int p){
		return lwb(pos,p);
	}
	//void addv(int p,t v){
	void updv(int p,t v){
		seg.upd(idx(p),v);
	}
	t get(int b,int e){
		return seg.get(idx(b),idx(e));
	}
};

template<class t,class F>
struct Point2D{
	vc<Point1D<t,F>> buf;
	vi pos,xs,ys;
	const F f;
	const t g;
	int s;
	Point2D(F ff,t gg):f(ff),g(gg){}
	void addp(int x,int y){
		xs.pb(x);
		ys.pb(y);
	}
	int idx(int p){
		return lwb(pos,p);
	}
	void init(){
		pos=xs;
		mkuni(pos);
		s=1;
		while(s<(int)pos.size())s*=2;
		//buf.resize(s*2,Point1D<t,F>(f,g));
		rep(i,s*2)buf.emplace_back(f,g);
		rep(i,xs.size()){
			int j=lwb(pos,xs[i])+s;
			while(j>=1){
				buf[j].addp(ys[i]);
				j>>=1;
			}
		}
		for(auto&b:buf)b.init();
	}
	void updv(int x,int y,t v){
		int j=idx(x)+s;
		while(j>=1){
			buf[j].updv(y,v);
			j>>=1;
		}
	}
	t get(int b,int e,int p,int q,int l,int r,int i){
		if(e<=l||r<=b)return g;
		if(b<=l&&r<=e)return buf[i].get(p,q);
		int m=(l+r)/2;
		return f(get(b,e,p,q,l,m,i*2),get(b,e,p,q,m,r,i*2+1));
	}
	//[x1,x2)*[y1,y2)
	t get(int x1,int x2,int y1,int y2){
		return get(idx(x1),idx(x2),y1,y2,0,s,1);
	}
};

struct rect{
	int a,b,c,d;
	void init(){
		cin>>a>>b>>c>>d;
	}
};

struct query{
	int y,t,i;
	bool operator<(const query&q)const{
		if(y!=q.y)return y>q.y;
		return t<q.t;
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,q;cin>>n>>q;
	
	vc<rect> x(n),y(q);
	auto imax=[&](int a,int b){
		return max(a,b);
	};
	vc<query> qs;
	Point2D<int,decltype(imax)> p2(imax,-inf);
	rep(i,n){
		x[i].init();
		p2.addp(x[i].a,x[i].c);
		qs.pb({x[i].d,1,i});
	}
	rep(i,q){
		y[i].init();
		qs.pb({y[i].d,0,i});
	}
	p2.init();
	vi ans(q);
	sort(all(qs));
	for(auto z:qs){
		int i=z.i;
		if(z.t==0){
			int mx=p2.get(y[i].a+1,y[i].b,y[i].c+1,y[i].d);
			dmp(mx);
			ans[i]=y[i].b<mx;
		}else{
			p2.updv(x[i].a,x[i].c,x[i].b);
		}
	}
	rep(i,q)
		if(ans[i])
			yes(0);
		else
			no(0);
}

