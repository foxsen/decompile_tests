#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
       long long int n,i,j,k,l;
       cin>>n>>k;
       if(k==1)
       {
           cout<<"1"<<endl;
           continue;
       }
       if(n&1)
       {
           if(k*2>n-2)
           {
               j=(n-2)/2+1;
               l=(k-1)/j;
               k=k+l;
           }
       }
       if(k%n==0)
       cout<<n<<endl;
       else
       cout<<(k%n)<<endl;
   }
   return 0;
}