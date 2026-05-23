#include <cstdio>
#include <algorithm>
int main(){
	int n;
	while(scanf("%d",&n),n){
		int m=0,v[4][2] = {{0,-1},{-1,0},{1,-1},{-1,-1}},map[66049] = {0};
		for(int y=1;y<=n;y++)
			for(int x=1;x<=n;x++)scanf("%1d",map+x+257*y);

		for(int i=0;i<4;i++){
			int dp[66049] = {0};
			for(int k=1;k<=n;k++)
				for(int j=1;j<=n;j++)m = std::max(m,dp[j+257*k] = map[j+k*257]?map[j+257*k] + dp[j+v[i][0]+257*(k+v[i][1])]:0);
		}
		printf("%d\n",m);
	}
}