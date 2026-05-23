#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

int main(){
  LL n;
  cin>>n;
  LL a[200010],b[200010];
  for(LL i=0;i<n;i++){
    cin>>a[i]>>b[i];
  }
  sort(a,a+n);
  sort(b,b+n);
  if(n%2!=0){
    LL m=n/2;
    cout<<b[m]-a[m]+1<<endl;
   
  }
  else{
    LL m=n/2-1;
    cout<<b[m]+b[m+1]-a[m]-a[m+1]+1<<endl;
  }
  return 0;
}
