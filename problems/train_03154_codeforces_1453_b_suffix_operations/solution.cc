#include <iostream>
using namespace std;
#include<bits/stdc++.h>
typedef long long ll;
int main() {
       int t;cin>>t;
       while(t--){
           int n;cin>>n;
           int i,j,k,x;
           vector<ll>a(n+2);
           vector<ll>ans(n+2,0);
           for(i=0;i<n;i++)
           cin>>a[i];
           int pos=1;
           for(i=1;i<n;i++){
               ans[i]=abs(a[i]-a[i-1]);
           }
           ll myans=0;
           for(i=1;i<n;i++)
           myans+=ans[i];
           ll first=myans-ans[1];
           ll second,out,second2=100000000000000000;
           for(i=1;i<n;i++){
               if(i!=n-1){
                second=myans-ans[i]-ans[i+1]+abs(a[i+1]-a[i-1]);
                second2=min(second2,second);
               }
               else{
                   second=myans-ans[i];
                second2=min(second2,second);
               }
           }
            out=min(first,second2);
          cout<<out<<endl;
           
           
       }
	return 0;
}
