#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 200000;
struct node{
	int pos,flag,v;
}a[maxn*2+50];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	
	//00001234
	for(int i=0;i<=2*maxn;++i){
		a[i].v = 0;
		a[i].pos = 0;
		a[i].flag = 0;
	}
	for(int i=maxn,j=1;j<=n;++j){
		a[i+j].v = j;
		a[i+j].pos = i+j;
	}
	
	int chg,p=1;
	for(int i=0;i<m;++i,++p){
		scanf("%d",&chg);
		if(a[chg+maxn].flag==0){
			a[chg+maxn].flag=1;
			a[chg+maxn].pos = maxn - p;
			a[maxn-p].v = chg;
		}else{
			a[a[chg+maxn].pos].flag = 1;
			a[chg+maxn].pos = maxn - p;
			a[a[chg+maxn].pos].pos = maxn - p;
			a[maxn - p].v = chg;
		}
	}
	
	for(int i=0;i<=2*maxn;++i)
		if(a[i].v && (!a[i].flag))printf("%d\n",a[i].v);
	
	return 0;
}