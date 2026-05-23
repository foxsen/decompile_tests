#include<iostream>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int i,ans=0;
    for(i=0;i<a.size();i++)
     ans+=(a[i]!=b[i]);
    cout<<ans;
}
