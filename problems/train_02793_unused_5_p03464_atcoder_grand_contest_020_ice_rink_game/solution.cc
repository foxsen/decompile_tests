#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int k;
    cin >>k;
    int a[k];
    for(int i=0;i<k;i++)cin>>a[i];
    int ng=1,ok=2;
    for(int i=k-1;i>=0;i--){
        ng=(1 + ng/a[i])*a[i]-1;
        ok =(1+ ok/a[i])*a[i]-1;
        if(ng>=ok)break;
    }
   if(ng<ok) cout <<ng+1<<' '<<ok;
   else cout <<-1;


    return 0;
}