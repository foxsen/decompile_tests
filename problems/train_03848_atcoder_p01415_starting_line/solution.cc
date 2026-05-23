#include<stdio.h>
#include<algorithm>
using namespace std;
int g[210];
int h[11000];
int main(){
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	for(int i=0;i<a;i++)scanf("%d",g+i);
	for(int i=0;i<a;i++)h[g[i]]=1;
	int last=0;
	double ret=0;
	int now=0;
	for(int i=1;i<=f;i++){
		if(now)ret+=1.0/e;
		else ret+=1.0/d;
		if(now&&last+c*e==i){
			now--;
			last=i;
		}
		if(h[i]){
			now++;
			if(now==1)last=i;
			if(now>b+1){
				now--;
				last=i;
			}
		}
	}
	printf("%.12f\n",ret);
}