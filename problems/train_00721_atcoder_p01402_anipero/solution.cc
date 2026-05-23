#include<stdio.h>
#include<algorithm>
using namespace std;
char in[100];
int dp[110][1010];
int val[1010];
int sp[110];
int sq[110];
int np[110];
int nq[110];
int main(){
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d),a){
		for(int i=0;i<b;i++){
			scanf("%s%d%d",in,sp+i,sq+i);
		}
		for(int i=0;i<c;i++)scanf("%s%d%d",in,np+i,nq+i);
		for(int i=0;i<110;i++)for(int j=0;j<1010;j++)dp[i][j]=-99999999;
		dp[0][0]=0;
		for(int i=0;i<c;i++){
			for(int j=i;j>=0;j--){
				for(int k=a-np[i];k>=0;k--){
					dp[j+1][k+np[i]]=max(dp[j+1][k+np[i]],dp[j][k]+nq[i]);
				}
			}
		}
		for(int i=0;i<1010;i++)val[i]=-99999999;
		for(int i=d;i<=c;i++)for(int j=0;j<=a;j++)val[j]=max(val[j],dp[i][j]);
		int ret=0;
		for(int i=0;i<b;i++){
			for(int j=0;j<=a-sp[i];j++){
		//		if(sq[i]+val[j]==59)printf("%d %d\n",i,j);
				ret=max(ret,sq[i]+val[j]);
			}
			for(int j=i+1;j<b;j++){
				for(int k=0;k<=a-sp[i]-sp[j];k++){
			//		if(sq[i]+sq[j]+val[k]==59)printf("%d %d %d\n",i,j,k);
					ret=max(ret,sq[i]+sq[j]+val[k]);
				}
			}
		}
		printf("%d\n",ret);
	}
}