#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string mp;
int n,T;
double mem[2001][2001];
bool used[2001][2001];

double dfs(int t,int pos){
  if(t==T)return mem[t][pos]=(mp[pos]=='R');
  if(used[t][pos])return mem[t][pos];
  used[t][pos]=1;

  double res=0;
  for(int i=1;i<=6;i++)res+=dfs(t+1,(pos+i)%n);
  return mem[t][pos]=res/6;
}

int main(){
  while(1){
    cin>>n>>T;
    if(!n&&!T)break;
    cin>>mp;

    memset(used,0,sizeof(used));  
    for(int i=0;i<2001;i++)
      for(int j=0;j<2001;j++) mem[i][j]=0;
    
    
    double ans=0;  
    for(int i=0;i<n;i++) ans=max(ans,dfs(0,i));
    printf("%.10f\n",ans);
  }
  return 0;
}