#include<stdio.h>
#include<algorithm>
using namespace std;
int p[110];
int t[110];
int v[110];
double dp[110][110];
double prob[110][110];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++){
		scanf("%d%d%d",p+i,t+i,v+i);
		for(int j=0;j<=b;j++)for(int k=0;k<=b;k++)dp[j][k]=0;
		dp[0][0]=1;
		for(int j=0;j<b;j++){
			for(int k=0;k<=j;k++){
				dp[j+1][k+1]+=dp[j][k]*p[i]/100;
				dp[j+1][k]+=dp[j][k]*(100-p[i])/100;
			}
		}
		for(int j=0;j<=b;j++)prob[i][j]=dp[b][j];
	}
	double EPS=1e-12;
	for(int i=0;i<a;i++){
		double ret=0;
		for(int j=0;j<=b;j++){
			if(!v[i])continue;
			double time=(double)c/v[i]+j*t[i];
			double ks=prob[i][j];
			for(int k=0;k<a;k++){
				if(i==k)continue;
				double tmp=0;
				for(int l=0;l<=b;l++){
					if(v[k]&&time+EPS>(double)c/v[k]+l*t[k])continue;
					tmp+=prob[k][l];
				}
				ks*=tmp;
			}
			ret+=ks;
		}
		printf("%.12f\n",ret);
	}
}