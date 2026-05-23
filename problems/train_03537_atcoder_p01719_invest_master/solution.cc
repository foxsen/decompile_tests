#include <iostream>
using namespace std;
int n,d,p[10][10],ans;

void saiki(int sum,int x,int day,int I){
  int f=1;
  for(int i=I;i<n;i++)
    if(p[day][i]/p[day-1][i]&&x/p[day-1][i]) {
      f=0;
      saiki(sum+p[day][i],x-p[day-1][i],day,i);
    }
  if(f)ans=max(ans,sum+x);
}

int main(){
  cin>>n>>d>>ans;
  for(int i=0;i<d;i++)
    for(int j=0;j<n;j++)cin>>p[i][j];

  for(int i=0;i<d-1;i++)saiki(0,ans,i+1,0);
  cout<<ans<<endl;
  return 0;
}