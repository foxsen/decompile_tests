#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[300005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,j=1;i<=n;i=j=j+1){
		while(1){
			if(j+1>n||a[j+1]!=j+1)break;
			if(j+2>n||a[j+2]==j+2)break;
			j+=2;
		}
		for(int k=i;k<=j;++k)
			if(a[k]<i||a[k]>j)
				return puts("No"),0;
		for(int k=i,x=0,y=0;k<=j;++k){
			if(a[k]<k){
				if(a[k]<x)return puts("No"),0;
				x=a[k];
			}
			if(a[k]>k){
				if(a[k]<y)return puts("No"),0;
				y=a[k];
			}
		}
	}
	return puts("Yes"),0;
}
