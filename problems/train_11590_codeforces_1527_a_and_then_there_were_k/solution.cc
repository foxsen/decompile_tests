#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int x,p,t;
    cin >> t;
    while(t--)
    {
        cin >> x ;
        int p=1;
        while(x >= p) 
        {
            p *= 2;
        }
        p = p/2;
        cout << p - 1 << endl;
    }
    return 0;
}