#include<bits/stdc++.h>
using namespace std;
int a[55],b[55],c[55],d[55],n,m,i,j,num,s,mins=0x7fffffff;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(i=1;i<=m;i++) scanf("%d%d",&c[i],&d[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			s=abs(a[i]-c[j])+abs(b[i]-d[j]);
			if(s<mins) mins=s,num=j;
		}
		printf("%d\n",num);
		mins=0x7fffffff;
	}
	return 0;
}