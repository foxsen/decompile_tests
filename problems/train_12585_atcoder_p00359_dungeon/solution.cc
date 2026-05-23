#include<stdio.h>
int main(void)
{
	int w,h,n,x[100000],y[100000],Xmax,cnt,flg[100000],kyori,ymax,i;
	scanf("%d%d%d",&w,&h,&n);
	Xmax=0;
	for(i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(Xmax<x[i]) Xmax=x[i];
	}
	for(i=0;i<=Xmax;i++) flg[i]=-1;
	flg[0]=0;
	for(i=0;i<n;i++){
		if(flg[x[i]]<y[i]) flg[x[i]]=y[i];
	}
	//for(i=0;i<=Xmax;i++) printf("flg[%d]=%d\n",i,flg[i]);
	kyori=1000000; ymax=0;
	for(i=Xmax;i>=0;i--){
		if(flg[i]!=-1){
			if(kyori>ymax+i) kyori=ymax+i;
			if(ymax<flg[i]) ymax=flg[i];
		}
		//printf("i=%d ymax=%d\n",i,ymax);
	}
	printf("%d\n",kyori);
	return 0;
}
