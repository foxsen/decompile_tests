#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 120000

int n,g[2],a[N][3],b[N],c[N],bit[2][N],f[2];

int qry(int k,int x){
	int ret=0;
	for (;x;x-=x&(-x)) ret+=bit[k][x];
	return ret;
}

void add(int k,int x){
	for (;x<=n;x+=x&(-x)) ++bit[k][x];
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<3;++i)
		for (int j=1;j<=n;++j) scanf("%d",a[j]+i);
	for (int i=1;i<=n;++i){
		if (a[i][1]%3!=2){puts("No"); return 0;}
		if (a[i][0]==a[i][1]-1&&a[i][2]==a[i][1]+1){
			b[i]=a[i][2]/3; c[i]=0;
		}
		else{
			if (a[i][0]==a[i][1]+1&&a[i][2]==a[i][1]-1){
				b[i]=a[i][0]/3; c[i]=1;
			}
			else{puts("No"); return 0;}
		}
	}
	for (int i=1;i<=n;++i)
		if ((b[i]-i)%2!=0){puts("No"); return 0;}
		else{
			int x=(i-1)/2-qry(i%2,b[i]),y=(b[i]-i)/2;
			add(i%2,b[i]);
			f[i%2]^=x&1;
			g[i%2]^=c[i]^(y&1);
		}
	if (f[0]!=g[1]){puts("No"); return 0;}
	if (f[1]!=g[0]){puts("No"); return 0;}
	puts("Yes");
	
	return 0;
}
			