#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;






int main(){
    ll q;
    cin>>q;
    while(q--){
        ll fd=E,mx=-1,mx2=-1;
        string s,t;
        cin>>s>>t;
        if(s==t){cout<<0<<endl; continue;}
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){fd=min(fd,(ll)i);}
            if(s[i]=='1'){mx=max(mx,(ll)i);}
            if(t[i]=='1'){mx2=max(mx2,(ll)i);}
        }
        cout<<abs(fd-mx)+abs(mx2-fd)<<endl;
    }
    
    
    
    return 0;
}
