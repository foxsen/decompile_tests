#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        bool f=false;
        ll temp=1;
        while(temp<=n)
        {
            if((n-temp)%b==0)
            {
                f=true;
            }
            temp*=a;
            if(a==1)
            {
                break;
            }
        }
        if(f)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}