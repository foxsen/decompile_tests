#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int min=101;

    int ans=0;
    for(int i=0;i<n;i++){
        int x;  cin>>x;
        ans+=x;
        if(min>x && x%2!=0)min=x;
    }

    if(ans%2!=0)ans-=min;

    cout<<ans/2<<endl;

    return 0;
}

