#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t=0,n,i;
    cin>>n;
    for(i=1;i*(i+1)<n;i++)
        if(n%i==0)
            t+=n/i-1;
    cout<<t;
    return 0;
}
