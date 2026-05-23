#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll int N= 1000000007;
int main() {ios_base::sync_with_stdio(false);
/*int t;cin>>t;
while(t--){*/
    
 
 
 int n;cin>>n;
  ll int a[n];
  for(int i =0;i<n;i++)
  cin>>a[i];
 
  
  
  priority_queue<ll int, vector<ll int>,  
                       greater<ll int> > s;
  
 int cnt= 0 ;
  ll int sum = 0;
 for(int  i = 0;i<n;i++)
 {
     if(sum+a[i]>=0)
     {
         sum+=a[i];
         cnt++;
         if(a[i]<0)
         {
             s.push(a[i]);
         }
     }
     else
     {
         if(!s.empty())
         {  
              if(a[i]>s.top())
              {
                  
                  
                  sum = sum - s.top() + a[i];
                  s.pop();
                  if(a[i]<0)
                  s.push(a[i]);
                  
              }
              else
              continue;
         }
         else
         continue;
         
         
     }
 }
 cout<<cnt<<endl;
  
   
// }
   return 0; 
 
}