#include<bits/stdc++.h>
using namespace std;
int main()
{
string x; 
cin>>x;
int a=x.size(),ans=0;
  for(int i=0;i<a;i++)
  {
    if(x[i]=='0')
	  ans++;
  }
cout<<a-(max(a-ans,ans)-min(a-ans,ans))<<endl;
return 0;
}