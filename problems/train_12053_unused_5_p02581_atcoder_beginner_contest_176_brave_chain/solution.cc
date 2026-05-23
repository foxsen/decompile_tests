#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=6005;
int n,m,add,ans,a[N],b[N],f[N][N],nxt[N],last[N];
int check(int x,int y,int z){
	return b[x]==b[y]&&b[y]==b[z];
}
void update(int x,int y,int a,int b,int c){
	f[x][a]=max(f[x][a],f[x][y]+check(y,b,c));
	f[x][b]=max(f[x][b],f[x][y]+check(y,a,c));
	f[x][c]=max(f[x][c],f[x][y]+check(y,a,b));
	f[y][a]=max(f[y][a],f[x][y]+check(x,b,c));
	f[y][b]=max(f[y][b],f[x][y]+check(x,a,c));
	f[y][c]=max(f[y][c],f[x][y]+check(x,a,b));
	f[a][b]=max(f[a][b],f[x][y]+check(x,y,c));
	f[a][c]=max(f[a][c],f[x][y]+check(x,y,b));
	f[b][c]=max(f[b][c],f[x][y]+check(x,y,a));
}
void dp(int x,int y){
	if(y+3>=n){
		return;
	}
	int sy=y/3*3;
	update(x,y,sy+3,sy+4,sy+5);
	int tx=x;
	while(tx&&tx<sy+3){
		tx=nxt[tx];
	}
	if(tx){
		int t=tx/3*3;
		update(x,y,t,t+1,t+2);
	}
	int ty=y;
	while(ty&&ty<sy+3){
		ty=nxt[ty];
	}
	if(ty){
		int t=ty/3*3;
		update(x,y,t,t+1,t+2);
	}
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++){
		scanf("%d",&a[i]);
	}
	b[++m]=a[1];
	b[++m]=a[2];
	for(int i=3;i<3*n;i+=3){
		if(a[i]==a[i+1]&&a[i+1]==a[i+2]){
			add++;
		}else{
			b[++m]=a[i];
			b[++m]=a[i+1];
			b[++m]=a[i+2];
		}
	}
	b[++m]=a[3*n];
	n=m;
	for(int i=n-1;i>=1;i--){
		nxt[i]=last[b[i]];
		last[b[i]]=i;
	}
	f[1][2]=0;
	for(int j=2;j<n;j++){
		for(int i=1;i<j;i++){
			if(f[i][j]!=-1){
				ans=max(ans,f[i][j]+check(i,j,n));
				dp(i,j);
			}
		}
	}
	printf("%d\n",add+ans);
	return 0;
}