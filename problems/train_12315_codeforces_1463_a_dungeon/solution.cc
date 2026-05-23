#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    for(int i = 0; i < t; i++){
        long long a,b,c;
        cin>>a>>b>>c;

        long long x = (a+b+c)/9;
        if((a+b+c) % 9 != 0) cout<<"NO"<<endl;
        else{
            long long y = min((min(a,b)),c);
            if(y < x) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}
