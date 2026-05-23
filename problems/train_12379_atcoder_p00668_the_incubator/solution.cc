#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
int p[410000];
int q[410000];
int bit[410000];
int n;
int sum(int a,int b){
	if(a)return sum(0,b)-sum(0,a-1);
	int ret=0;
	for(;b>=0;b=(b&(b+1))-1)ret+=bit[b];
	return ret;
}
void add(int a,int b){
	for(;a<n;a|=a+1)bit[a]+=b;
}
int get(int a){
	int left=-1;
	int right=n+1;
	while(left+1<right){
		int M=(left+right)/2;
		if(sum(0,M)>a)right=M;
		else left=M;
	}
	return right;
}
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a+b){
		map<int,int>m;
		for(int i=0;i<a;i++)scanf("%d%d",p+i,q+i);
		int sz=0;
		for(int i=0;i<a;i++){
			if(p[i]==0){
				m[q[i]]=i;
			}
		}
		n=a+1;
		for(int i=0;i<n;i++)bit[i]=0;
		for(int i=0;i<a;i++){
			if(p[i]==0){
				add(i,1);
				if(sum(0,a)>b)add(get(0),-1);
			}
			if(p[i]==1){
				q[i]--;
				int at=get(q[i]);
				add(at,-1);
			}
			if(p[i]==2){
				q[i]--;
				int at=get(q[i]);
				printf("%d\n",q[at]);
			}
			if(p[i]==3){
				int at=m[q[i]];
				add(at,-1);
			}
		}
		printf("end\n");
	}
}