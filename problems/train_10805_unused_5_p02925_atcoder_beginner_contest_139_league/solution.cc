#include<bits/stdc++.h>
using namespace std;
#define MN 1005
int n,want[MN][MN],vis[MN],now[MN],ok[MN];
inline int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		now[i]=1;
		for(int j=1;j<n;++j)
		want[i][j]=read();
	}
	int CNT=0,r=0,bol=0;
	while(CNT<n){
		r++;
		bol=0;
		for(int i=1;i<=n;++i)
			if(now[i]<n){
			int j=want[i][now[i]];
			if(want[j][now[j]]==i){
				bol=1,ok[i]=ok[j]=max(ok[i],ok[j])+1,now[i]++,now[j]++;
			}
			if(now[i]==n&&!vis[i])vis[i]=1,CNT++;
			if(now[j]==n&&!vis[j])vis[j]=1,CNT++;
		}
		if(!bol&&CNT<n){puts("-1");return 0;}
	}
	for(int i=1;i<=n;++i)r=max(r,ok[i]);
	printf("%d",r);
	return 0;
}
