#include<bits/stdc++.h>
using namespace std;
int ver[400010],nxt[400010],hed[400010],tot=0,vs[200010],n,m,ans=0,tt;
void add(int x,int y){
    ver[++tot]=y,nxt[tot]=hed[x],hed[x]=tot;
}
void search(int x){
	vs[x]=1,tt++;
	for(int i=hed[x];i;i=nxt[i])
		if(!vs[ver[i]])
			search(ver[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	memset(vs,0,sizeof(vs));
	for(int i=1;i<=n;++i){
		if(!vs[i])
			tt=0,search(i);
		ans=max(ans,tt);
	}
	printf("%d\n",ans);
	return 0;
}