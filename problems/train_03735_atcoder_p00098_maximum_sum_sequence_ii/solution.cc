#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int a[105][105];
int sum[105][105];

int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("%d",&a[j][i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)sum[j][i]=sum[j-1][i]+a[j][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)sum[i][j]+=sum[i][j-1];
	}
	int res=-114514;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=0;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					res=max(res,sum[j][l]-sum[j][k]-sum[i][l]+sum[i][k]);
				}
			}
		}
	}
	printf("%d\n",res);
}