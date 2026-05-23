#include <iostream>
using namespace std;
int main()
{
int k,n;
cin>>k;
cin>>n;
int a[300000];

int maxl=0;
for (int i=0;i<n;i++)
cin>>a[i];

for (int i=0;i<n-1;i++)
{if(maxl<a[i+1]-a[i])maxl=a[i+1]-a[i];}
if(maxl<(k-(a[n-1]-a[0])))maxl=k-(a[n-1]-a[0]);
cout<<k-maxl;
}