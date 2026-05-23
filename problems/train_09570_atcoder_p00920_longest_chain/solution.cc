#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
int M,N,A,B,C,a,b,mod;
typedef pair<int,int> P;
typedef pair<int,P> PP;
vector< set<P> > ss;
set<P>::iterator it;
vector<PP> vc;
int ran(){
	a=36969*(a&mod)+(a>>16);
	b=18000*(b&mod)+(b>>16);
	return (C&((a<<16)+b))%1000000;
}
int main(){
	while(true){
		cin>>M>>N>>A>>B;
		if(M+N==0) break;
		ss.clear();
		vc.clear();
		a=A,b=B,C=~(1<<31),mod=(1<<16)-1;
		rep(i,M){
			int x,y,z;
			cin>>x>>y>>z;
			vc.pb(PP(x,P(-y,-z)));
		}
		rep(i,N){
			int x=ran(),y=ran(),z=ran();
			vc.pb(PP(x,P(-y,-z)));
		}
		sort(all(vc));
		N=M+N;
		rep(i,N) vc[i].sc.fs*=-1,vc[i].sc.sc*=-1;
		set<P> be;
		be.insert(P(-2,-2));
		ss.pb(be);
		int mx=0;
		rep(i,N){
			int y=vc[i].sc.fs,z=vc[i].sc.sc;
			int ub=mx+1,lb=-1;
			while(ub-lb>1){
				int m=(ub+lb)/2;
				it=ss[m].upper_bound(P(y-1,z-1));
				if(it==ss[m].begin()){
					ub=m;
					continue;
				}
				it--;
//				printf("m=%d, koko;%d,%d\n",m,it->fs,it->sc);
				if(it->sc<z) lb=m;
				else ub=m;
			}
			if(lb==-1) continue;
			int m=lb+1;
//			printf("m=%d\n",m);
			if(m>mx){
				set<P> be;
				be.insert(P(y,z));
				ss.pb(be);
				mx++;
			}else{
				it=ss[m].lower_bound(P(y,z));
				while(it!=ss[m].end()){
					if(it->sc<z) break;
//					printf("erase=(%d,%d)\n",it->fs,it->sc);
					it=ss[m].erase(it);
				}
				bool ok=true;
				it=ss[m].upper_bound(P(y,-1919));
				if(it!=ss[m].end()&&it->fs==y&&it->sc<z) ok=false;
				if(it!=ss[m].begin()){
					it--;
					if(it->sc==z) ok=false;
				}
				if(ok) ss[m].insert(P(y,z));
			}
/*			printf("i=%d,  y,z=(%d,%d)     mx=%d\n",i,y,z,mx);
			cout<<"ss[1]";
			for(auto s:ss[1]) cout<<"("<<s.fs<<","<<s.sc<<") ";
			puts("");
			if(ss.size()>2){
				cout<<"ss[2]";
				for(auto s:ss[2]) cout<<"("<<s.fs<<","<<s.sc<<") ";
				puts("");
			}*/
		}
		cout<<mx<<endl;
	}
}