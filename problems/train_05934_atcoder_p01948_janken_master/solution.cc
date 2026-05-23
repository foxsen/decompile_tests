#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,x;
  cin>>n>>x;
  n--;
  int a[n];
  double r[n],p[n],s[n];
  for(int i=0;i<n;i++) cin>>a[i]>>r[i]>>p[i]>>s[i];
  for(int i=0;i<n;i++){
    r[i]/=100;p[i]/=100;s[i]/=100;
  }
  double dp[1<<n];
  for(int i=0;i<(1<<n);i++)
    dp[i]=-1;
  function<double(int)> dfs=[&](int b){
    if(__builtin_popcount(b)==n) return 1.0;
    if(dp[b]>=0) return dp[b];
    vector<int> v;
    int y=-1;
    for(int i=0;i<n;i++){
      if(!((b>>i)&1)){
	v.push_back(i);
	y=max(y,a[i]);
      }
    }
   
    int m=v.size();
    double dp2[m+1][1<<3][1<<3];
    for(int i=0;i<=m;i++)
      for(int j=0;j<(1<<3);j++)
	for(int k=0;k<(1<<3);k++)
	  dp2[i][j][k]=0;
    dp2[0][0][0]=1;
    for(int i=0;i<m;i++){
      for(int j=0;j<(1<<3);j++){
	for(int k=0;k<(1<<3);k++){
	  dp2[i+1][j|1][k|((a[v[i]]>x)<<0)]+=dp2[i][j][k]*r[v[i]];
	  dp2[i+1][j|2][k|((a[v[i]]>x)<<1)]+=dp2[i][j][k]*p[v[i]];
	  dp2[i+1][j|4][k|((a[v[i]]>x)<<2)]+=dp2[i][j][k]*s[v[i]];
	}
      }
    }
    
    //cout<<m<<endl;

    double dp3[1<<3];
    for(int j=0;j<(1<<3);j++){
      dp3[j]=0;
      for(int k=0;k<(1<<3);k++)
	dp3[j]+=dp2[m][j][k];
    }
    
    /*/
      cout<<b<<":"<<endl;
      for(int j=0;j<(1<<3);j++)
      cout<<bitset<3>(j)<<":"<<dp3[j]<<endl;
    //*/
    
    //res=max(res,dp3[4]+(dp3[1]+dp3[6]));
    //res=max(res,dp3[1]+(dp3[2]+dp3[5]));
    //res=max(res,dp3[2]+(dp3[4]+dp3[3]));

    double aa=dp3[4]+dp2[m][1][0]+dp3[6]*(y<x);
    double bb=dp3[1]+dp2[m][2][0]+dp3[5]*(y<x);
    double cc=dp3[2]+dp2[m][4][0]+dp3[3]*(y<x);
    
    
    for(int i=1;i<(1<<m)-1;i++){
      int k=b;
      for(int j=0;j<m;j++)
	if((i>>j)&1) k|=1<<v[j];
      //cout<<bitset<3>(b)<<":"<<bitset<3>(i)<<endl;
      //for(int j=0;j<m;j++) cout<<v[j]<<endl;
      //cout<<b<<":"<<k<<endl;
      assert(k!=b);
      {
	double d=1.0;
	for(int j=0;j<m;j++){
	  if((i>>j)&1) d*=s[v[j]];
	  else d*=r[v[j]];
	}
	//res=max(res,d*dfs(k)+aa);
	aa+=d*dfs(k);
      }
      {
	double d=1.0;
	for(int j=0;j<m;j++){
	  if((i>>j)&1) d*=r[v[j]];
	  else d*=p[v[j]];
	}
	//res=max(res,d*dfs(k)+bb);
	bb+=d*dfs(k);
      }
      {
	double d=1.0;
	for(int j=0;j<m;j++){
	  if((i>>j)&1) d*=p[v[j]];
	  else d*=s[v[j]];
	}
	//res=max(res,d*dfs(k)+cc);
	cc+=d*dfs(k);
      }
    }
    //cout<<aa<<":"<<dp3[5]<<endl;
    //cout<<bb<<":"<<dp3[3]<<endl;
    //cout<<cc<<":"<<dp3[6]<<endl;
    
    double res=max({aa,bb,cc});
    if(y<x) res+=dp3[7];
    //cout<<b<<":"<<res<<endl;
    return dp[b]=res;
  };
  printf("%.12f\n",dfs(0));
  return 0;
}

