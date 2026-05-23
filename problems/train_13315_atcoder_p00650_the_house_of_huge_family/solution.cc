#include <bits/stdc++.h>
using namespace std;

#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl
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

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	print_tuple<Cdr...>(os,t);
	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C,typename=decltype(begin(C()))>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;

struct UnionFind{
	vi data;
	UnionFind(int n):data(n,-1){}
	int Find(int i){
		return data[i]<0?i:(data[i]=Find(data[i]));
	}
	bool Unite(int a,int b){
		a=Find(a),b=Find(b);
		if(a==b) return false;
		if(-data[a]<-data[b]) swap(a,b);
		data[a]+=data[b];
		data[b]=a;
		return true;
	}
	int Size(int i){
		return -data[Find(i)];
	}
};

struct Edge{
	int src,dst,weight;
	Edge(){}
	Edge(int s,int d,int w):src(s),dst(d),weight(w){}
};
typedef vector<vector<Edge>> Graph;

int main()
{
	for(int n,m;cin>>n>>m && n|m;){
		vector<Edge> es;
		int neg=0;
		rep(i,m){
			int u,v,w; cin>>u>>v>>w;
			if(w<=0) neg+=w;
			else es.emplace_back(u,v,w);
		}
		m=es.size();
		
		int res=INF;
		{
			UnionFind uf(n);
			int cc=n;
			rep(i,m)
				cc-=uf.Unite(es[i].src,es[i].dst);
			if(cc>=2) res=0;
		}
		{
			rep(i,m){
				vi use(m,1); use[i]=0;
				UnionFind uf(n);
				int cc=n;
				rep(j,m) if(use[j])
					cc-=uf.Unite(es[j].src,es[j].dst);
				if(cc>=2) res=min(res,es[i].weight);
			}
		}
		{
			rep(i,m) repi(j,i+1,m){
				vi use(m,1); use[i]=use[j]=0;
				UnionFind uf(n);
				int cc=n;
				rep(k,m) if(use[k])
					cc-=uf.Unite(es[k].src,es[k].dst);
				if(cc>=2) res=min(res,es[i].weight+es[j].weight);
			}
		}
		cout<<neg+res<<endl;
	}
}