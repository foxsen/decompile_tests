#include <bits/stdc++.h>
using namespace std;
int n,s,ans;
int main(){
cin>>n>>s;
for(int k=0;k<n;k++){
   int a;
   cin>>a;
   if(a>=s)
        ans++;
}
cout<<ans;
return 0;
}

