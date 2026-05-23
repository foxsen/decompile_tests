#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <queue>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;
 
int n,m,r;
const int INF=1e7;
int d[2][200][200];
int dp[1001][200];
 
int main(){
 
 
	while(scanf("%d %d",&n,&m),n){
		
	   for(int i=0;i<n;i++){
		  for(int j=0;j<n;j++) d[0][i][j]=d[1][i][j]=INF;
		  d[0][i][i]=d[1][i][i]=0;
	   }
		
	   for(int i=0;i<m;i++){
		  int x,y,t;
		  char c;
		  scanf("%d %d %d %c",&x,&y,&t,&c);
		  x--; y--;
		  
		  d[c=='L'][x][y]=min(d[c=='L'][x][y],t);
		  d[c=='L'][y][x]=min(d[c=='L'][y][x],t);
	   }
		
	   for(int k=0;k<n;k++){
		  for(int i=0;i<n;i++){
			 for(int j=0;j<n;j++){
				d[0][i][j]=min(d[0][i][j],d[0][i][k]+d[0][k][j]);
				d[1][i][j]=min(d[1][i][j],d[1][i][k]+d[1][k][j]);
			 }
		  }
	   }
	   
	   int now,z;
	   scanf("%d",&r);
	   scanf("%d",&now); now--;

	   fill(&dp[0][0],&dp[1001][0],INF);
	   dp[0][now]=0;
		
	   for(int i=0;i<r-1;i++){
		   scanf("%d",&z); z--;
		   
		   for(int j=0;j<n;j++){
			   dp[i+1][j]=min(dp[i+1][j],dp[i][j]+d[1][now][z]);
			   for(int k=0;k<n;k++){
				   // 
				   dp[i+1][k]=min(dp[i+1][k],dp[i][j]+d[1][now][j]+d[0][j][k]+d[1][k][z]);
			   }
			   
			   
		   }
		   now=z;
	   }


/*
	   //int res=INF;
	   for(int i=1;i<r;i++){
		  for(int j=0;j<n;j++){
							
			 for(int k=0;k<n;k++){
				dp[i][k]=min(dp[i][k],dp[i-1][j]+d[1][z[i-1]][j]+d[0][j][k]+d[1][k][z[i]]);
				//if(i==r-1 && res>dp[i][k]) res=dp[i][k];
			 }
			 dp[i][j]=min(dp[i][j],dp[i-1][j]+d[1][z[i-1]][z[i]]);
			 //if(i==r-1 && res>dp[i][j]) res=dp[i][j];
		  }
	   }
*/
	   printf("%d\n",*min_element(dp[r-1],dp[r]));
		
	}
}