
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int INF=1000000;
int main() {
	int dp[101][101]={};
	for(int i=0;i<101;++i){
		for(int j=0;j<101;++j){
			dp[i][j]=INF;
		}
	}
	int n,m,a[1001],b[1001],c[1001];
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>a[i]>>b[i]>>c[i];
		dp[a[i]][b[i]]=c[i];
		dp[b[i]][a[i]]=c[i];
	}
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=1;i<n+1;++i){
			for(int j=1;j<n+1;++j){
				for(int k=1;k<n+1;++k){
					if(dp[i][j]>dp[i][k]+dp[k][j]){
						flag=true;
						dp[i][j]=dp[i][k]+dp[k][j];
					}

				}
			}
		}
	}
	int r=0;
	for(int i=0;i<m;++i){
		if(c[i]>dp[a[i]][b[i]])++r;
	}
	cout<<r<<endl;
	return 0;
}
