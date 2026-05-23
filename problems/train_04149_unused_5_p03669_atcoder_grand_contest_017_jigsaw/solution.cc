#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n,h;
int l[220],r[220],fa[420],siz[420],L,R;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=400;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(c==0)l[a]++,L=a;
		else r[c]--,L=c+200;
		if(d==0)r[b]++,R=b+200;
		else l[d]--,R=d;
		if(find(L)==find(R)){
			siz[find(L)]++;
			continue;
		}
		siz[find(R)]+=siz[find(L)]+1;
		siz[find(L)]=0;
		fa[find(L)]=find(R);
	}
	int ans=0,cns=0;
	for(int i=1;i<=200;i++){
		if(l[i]<0||r[i]<0){
			printf("NO\n");
			return 0;
		}
		if(l[i])ans+=siz[find(i)],siz[find(i)]=0;
		if(r[i])ans+=siz[find(i+200)],siz[find(i+200)]=0;
	}
	if(ans!=n)printf("NO\n");
	else printf("YES\n");
}