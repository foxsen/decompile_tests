#include <cstdio>
#include <algorithm>
using namespace std;
#define x 10001
int dp[x][2],num[x];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1;i<n;i++)
    {
      scanf("%d",&num[i]);
    }
  for(int i=0;i<x;i++)
    {
      dp[i][0]=x*x;
      dp[i][1]=x*x;
    }
  dp[1][0]=0;
  for(int i=1;i<n;i++)
    {
      for(int j=1+i;j>=1;j--)
    {
      dp[j][1]=min(dp[j][1],dp[j][0]+num[i]);
      dp[j][0]=min(dp[j-1][0],dp[j-1][1]+num[i]);
    }
    }
  printf("%d\n",min(dp[n/2][0],dp[n/2][1]));
  return 0;
}