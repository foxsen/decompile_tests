#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef pair<int,int>P;
typedef long long ll;

struct UnionFind{
	vector<int>par;
	vector<int>sz;
	UnionFind(int n){
		par=sz=vector<int>(n);
		rep(i,n)par[i]=i,sz[i]=1;
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return;
		par[y]=x;
		sz[x]+=sz[y];
	}
	int size(int x){
		x=find(x);
		return sz[x];
	}
};

P a[200000],b[200000];

int main(){
	int n;cin>>n;
	rep(i,n)scanf("%d",&a[i].first),a[i].second=i;
	rep(i,n)scanf("%d",&b[i].first),b[i].second=i;
	sort(a,a+n);
	sort(b,b+n);
	UnionFind uf(n);
	rep(i,n){
		if(a[i].first>b[i].first){
			puts("No");return 0;
		}
		uf.unite(a[i].second,b[i].second);
	}
	if(uf.size(0)!=n){puts("Yes");return 0;}
	rep(i,n-1){
		if(a[i+1].first<=b[i].first){
			puts("Yes");return 0;
		}
	}
	puts("No");
}