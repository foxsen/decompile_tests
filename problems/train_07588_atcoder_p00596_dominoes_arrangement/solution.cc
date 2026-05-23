#include<stdio.h>
#include<algorithm>
using namespace std;
int UF[200];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
int deg[100];
int main(){
	int a;
	while(~scanf("%d",&a)){
		for(int i=0;i<10;i++)deg[i]=0;
		for(int i=0;i<10;i++)UF[i]=-1;
		while(a--){
			int b;scanf("%d",&b);
			UNION(b/10,b%10);
			deg[b/10]++;
			deg[b%10]++;
		}
		bool ok=true;
		int ki=0;
		for(int i=0;i<10;i++){
			if(deg[i]%2)ki++;
			for(int j=0;j<10;j++)if(deg[i]&&deg[j]&&FIND(i)!=FIND(j))ok=false;
		}
		if(ki>2)ok=false;
		if(ok)printf("Yes\n");else printf("No\n");
	}
}