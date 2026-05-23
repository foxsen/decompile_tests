#include<stdio.h>
int main(void)
{
	int n,j,i[1000],p[1000],q[1000],r[1000],p2,q2,r2,c,flg,x[1000],cnt;
	while(1){
		cnt=0;
		flg=0;
		scanf("%d",&n);
		if(n==0)break;
		for(j=0;j<n;j++){
			scanf("%d %d %d %d",&i[j],&p[j],&q[j],&r[j]);
		}
		scanf("%d %d %d %d",&p2,&q2,&r2,&c);
		for(j=0;j<n;j++){
			if(p[j]<=p2&&q[j]<=q2&&r[j]<=r2&&p[j]*4+q[j]*9+r[j]*4<=c){
				x[cnt]=i[j];
				cnt++;
				flg=1;
			}
		}
		if(flg==1){
			for(j=0;j<cnt;j++){
				printf("%d\n",x[j]);
			}
		}
		else{
			printf("NA\n");
		}
	}
	return 0;
}