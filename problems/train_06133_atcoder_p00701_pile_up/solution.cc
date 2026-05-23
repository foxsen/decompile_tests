#include<cstdio>
#include<vector>
#include<algorithm>

#define	pb		push_back
#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

typedef	vector<int>	vi;
typedef	vector<vi>	vvi;

bool cmp(const vi &va,const vi &vb){ return va.size()<vb.size(); }

vvi pile;

void findPos(int id,int &p,int &h){
	rep(i,pile.size())rep(j,pile[i].size()){
		if(pile[i][j]==id){ p=i,h=j; return; }
	}
}

int main(){
	for(int m;scanf("%d",&m),m;){
		pile=vvi(m);
		rep(i,m)	pile[i].pb(i+1);

		for(int pck,put;scanf("%d%d",&pck,&put),pck||put;){
			if(pck==put)	continue;

			int pckp,pckh;	findPos(pck,pckp,pckh);
			int putp,puth;	findPos(put,putp,puth);

			if(put==0){
				if(pckh>0){
					while(1){
						int cube=pile[pckp].back();
						pile[pckp].pop_back();
						pile.pb(vi(1,cube));
						if(cube==pck)	break;
					}
				}
			}
			else{
				if(pckp!=putp || (pckp==putp && pckh<puth)){
					while(1){
						int cube=pile[pckp].back();
						pile[pckp].pop_back();
						if(cube==pck)	break;
						pile.pb(vi(1,cube));
					}
					findPos(put,putp,puth);
					pile[putp].pb(pck);
				}
			}
		}

		sort(pile.begin(),pile.end(),cmp);

		rep(i,pile.size()) if(pile[i].size()>0) printf("%d\n",pile[i].size());
		puts("end");
	}

	return 0;
}