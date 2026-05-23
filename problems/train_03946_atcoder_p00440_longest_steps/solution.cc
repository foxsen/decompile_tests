#include<stdio.h>
int n,k;
int ar[100000];
int x;
int r,l;
int m,t;
int i,j;
int used;

int max(int a,int b){
	if(a>=b)return a;
	else return b;
}

int main(){
	while(1){
		scanf("%d %d",&n,&k);
		if(n==0&&k==0)return 0;
		used=0;
		for(i=0;i<n+1;i++)ar[i]=0;
		for(i=0;i<k;i++){
			scanf("%d",&x);
			ar[x]=1;
		}
		r=1;l=1;
		if(ar[1]==0){
			used++;
			m=0;
		}else m=1;
		while(l<n){
			if(ar[++l]==0)used++;
			if(ar[0]==1)while(used>1){if(ar[r++]==0)used--;}
			if(ar[0]==0)while(used>0){if(ar[r++]==0)used--;}
			m=max(m,l-r+1);
		}
		printf("%d\n",m);
	}
}
		