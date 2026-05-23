#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
    int t; cin>>t;
    while(t--)
    {
        int a[4]; cin>>a[0]>>a[1]>>a[2]>>a[3];
        sort(a, (a+4)); cout<<a[0]*a[2]<<endl;
    }

    return 0;
}
