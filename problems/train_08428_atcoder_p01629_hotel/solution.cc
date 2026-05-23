#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstdio>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define inf (1<<29)
#define MAX 100
using namespace std;
typedef long long ll;

/*
経路復元用
dp[day][hotel][number] := minimum
 */
int dp[MAX][MAX][MAX];
int path[MAX][MAX][MAX];
int N,D,p[MAX][MAX];

int main()
{
  scanf("%d %d",&N,&D);
  rep(i,N)
    {
      rep(j,D)scanf("%d",&p[i][j]);
      reverse(p[i],p[i]+D);
    }
  
  rep(i,D+1)rep(j,N)rep(k,55)
    {
      dp[i][j][k] = inf;
      path[i][j][k] = inf;
    }

  rep(i,N)dp[0][i][0] = 0;

  rep(day,D)
    {
      rep(hotel,N)
	{
	  rep(number,55)
	    {
	      if(dp[day][hotel][number] == inf)continue;
	      rep(next_hotel,N)
		{
		  int add = (hotel != next_hotel);
		  if(dp[day+1][next_hotel][number+add] > dp[day][hotel][number]+p[next_hotel][day])
		    {
		      dp[day+1][next_hotel][number+add] = dp[day][hotel][number]+p[next_hotel][day];
		      path[day+1][next_hotel][number+add] = hotel;
		    }
		  else if(dp[day+1][next_hotel][number+add] == dp[day][hotel][number]+p[next_hotel][day])
		    {
		      if(path[day+1][next_hotel][number+add] > hotel)path[day+1][next_hotel][number+add] = hotel;
		    }
		}
	    }
	}
    }

  int mincost,minnumber,minN;
  mincost = minnumber = minN = inf;

  rep(i,N)rep(j,55)
    {
      if(mincost >= dp[D][i][j])
	{
	  if(mincost == dp[D][i][j])
	    {
	      if(minnumber >= j)
		{
		  if(minnumber == j)
		    {
		      if(minN > i)
			minN = i;
		    }
		  else
		    {
		      minnumber = j;
		      minN = i;
		    }
		}
	    }
	  else
	    {
	      mincost = dp[D][i][j];
	      minnumber = j;
	      minN = i;
	    }
	}
    }

  cout << mincost << " " << minnumber << endl;
  vector<int> ph;
  int d,h,n;

  d = D,h = minN, n = minnumber;

  int diff = p[h][D-1];
  for(;d >= 0 && n >= 0;)
    {
      ph.push_back(h);

      int next_h = path[d][h][n];
      int next_n = n - (next_h != h);
      h = next_h;
      n = next_n;
      d--;
      diff += p[h][d-1];
      if(path[d][h][n] == inf)break;
    }
  rep(i,ph.size())
    {
      cout << ph[i]+1 << endl;
      assert(ph[i]!=inf);
    }
  return 0;
}