#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,m,k,s;
  cin>>n>>m>>k>>s;
  int a[11][11];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j];

  /*//
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cout<<a[i][j]<<" \n"[j==m-1]<<flush;
  //*/  

  auto row=[&](int i){
    int x[m+1];
    x[0]=0;
    for(int j=0;j<m;j++) x[j+1]=x[j]+a[i][j];
    int y[m+1];
    y[m]=x[m];
    for(int j=m-1;j>=0;j--)
      y[j]=max(y[j+1],x[j+1]);
    int res=0;
    for(int j=0;j<m;j++)
      res=max(res,y[j]-x[j]);

    //cout<<i<<":i"<<endl;for(int j=0;j<=m;j++) cout<<j<<":"<<x[j]<<" "<<y[j]<<":"<<a[i][j]<<endl;
    
    return res;
  };
  
  auto col=[&](int j){
    int x[n+1];
    x[0]=0;
    for(int i=0;i<n;i++) x[i+1]=x[i]+a[i][j];
    int y[n+1];
    y[n]=x[n];
    for(int i=n-1;i>=0;i--)
      y[i]=max(y[i+1],x[i+1]);
    int res=0;
    for(int i=0;i<n;i++)
      res=max(res,y[i]-x[i]);
    return res;
  };

  vector<int> vx,vy;
  for(int i=0;i<n;i++){
    //cout<<row(i)<<endl;
    if(row(i)>s) vy.push_back(i);
  }
  for(int j=0;j<m;j++){
    //cout<<col(j)<<endl;
    if(col(j)>s) vx.push_back(j);
  }
  if((int)vx.size()>k||(int)vy.size()>k){
    cout<<"No"<<endl;
    return 0;
  }

  int ans=0;
  function<void(int,int,int)> dfs=
    [&](int b,int c,int d){
    {
      int tmp=0;
      for(int i=0;i<n;i++){
	tmp|=row(i)>s;
	if(tmp) break;
      }
      for(int j=0;j<m;j++){
	tmp|=col(j)>s;
	if(tmp) break;
      }
      if(!tmp){
	ans=1;
	return;
      }
    }
    if(b==k) return;
    for(int i=c;i<(int)vy.size();i++){
      for(int j=(i==c?d+1:0);j<m;j++){
	if(a[vy[i]][j]<=0) continue;
	a[vy[i]][j]*=-1;
	dfs(b+1,i,j);
	a[vy[i]][j]*=-1;
	if(ans) return;
      }
    }
  };
  
  function<void(int,int,int)> dfs2=
    [&](int b,int c,int d){
    {
      int tmp=0;
      for(int i=0;i<n;i++){
	tmp|=row(i)>s;
	if(tmp) break;
      }
      for(int j=0;j<m;j++){
	tmp|=col(j)>s;
	if(tmp) break;
      }
      if(!tmp){
	ans=1;
	return;
      }
    }
    if(b==k) return;
    for(int j=c;j<(int)vx.size();j++){
      for(int i=(j==c?d+1:0);i<n;i++){
	if(a[i][vx[j]]<=0) continue;
	a[i][vx[j]]*=-1;
	dfs2(b+1,j,i);
	a[i][vx[j]]*=-1;
	if(ans) return;
      }
    }
  };
  dfs(0,0,0);
  dfs2(0,0,0);
  //assert(!ans);
  cout<<(ans?"Yes":"No")<<endl;
  return 0;
}

