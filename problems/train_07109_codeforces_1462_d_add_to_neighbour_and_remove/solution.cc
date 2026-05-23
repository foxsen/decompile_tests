#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
//seen editorial :(
int main() {
	ll t;
	cin>>t;
    //t=1;
	while(t--)
	{
	    ll n,m,k,j,i,y,x,z,a,b,c,d,o,l,r;
	    ll count=0,ans=0,maxi=LLONG_MIN,mini=LLONG_MAX,flag=0,sum=0;
	    char ch;
	    vector<long long int> vec,vec1;
	    string str,strs;
	    map<ll,ll> mp;
	    stack <long long int> stck;
	    set<ll > se;
	    cin>>n;
	    for(i=0;i<n;i++)
        {
            cin>>m;
            vec.push_back(m);
            sum+=m;
        }
        for(int i=n;i>=1;i--)//i=n-k; where k is the min no of operations.
        {


           if(sum%i==0)
           {
              int p;
               int q=1;
               p=sum/i;
               int currsum=0;

           for(j=0;j<n;j++)
           {
               currsum+=vec[j];
               if(currsum>p)
               {q=0;break;}
               else if(currsum==p)
               {
                   currsum=0;
               }
           }
           if(q)
           {cout<<n-i<<endl;break;}


          }
	}
}
}
