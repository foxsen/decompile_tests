#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
 int u[100],d[100],dp[101][101],i,j,k,n;
 cin >> n;
 for (i=0;i<100;i++) for (j=0;j<100;j++) dp[i][j]=999999999;
 for (i=0;i<n;i++) { cin >> u[i] >> d[i]; dp[0][i]=0;} 
 for (i=1;i<n;i++)
	 for (j=0;j<n-i;j++)
		 for (k=0;k<i;k++) dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k-1][j+k+1]+u[j]*d[j+k]*u[j+k+1]*d[j+i]) ; 
 cout << dp[n-1][0] << endl;
 return 0;
 }