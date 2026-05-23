#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007;
#define INF (1<<28)
#define int long long
#define double long double
#define floot10 cout<<fixed<<setprecision(10)



signed main(){
  int h,w,x,y;
  cin>>h>>w>>x>>y;
  if(h*w%2==1&&(x+y)%2==1){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
  return 0;
}


