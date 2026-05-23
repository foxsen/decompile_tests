/*********************************************************
                Name: Snehasish Dhar,
                IIEST ,SHIBPUR
                dsnehasish74@gmail.com
**********************************************************/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define  PB           push_back
#define  UB           upper_bound
#define  LB           lower_bound
#define  BS           binary_search
#define  MP           make_pair
#define  EB           emplace_back
#define  endl         "\n"
#define  PI           3.1415926535897932384626433832795
#define  MOD          1000000007
#define  F            first
#define  S            second
#define  umap         unordered_map
#define  uset         unordered_set
#define  dec(x)       fixed<<setprecision(x)
#define  lcm(a,b)     (a*b/__gcd(a,b))
 

void solution(){

    bool ans=true;
    ll n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    vector<int>fa(26,0),fb(26,0);
    for(char it:a)fa[it-'a']++;
    for(char it:b)fb[it-'a']++;
    for(ll i=0;i<26;i++){
        if(fa[i]<fb[i]){
            ans=false;
            break;
        }
        else{
            ll diff=abs(fa[i]-fb[i]);
            if(diff%k!=0){
                ans=false;
                break;
            }
            else{
                fa[i]-=diff;
                fa[i+1]+=diff;
            }
        }
    }


    if(ans)cout<<"Yes\n";
    else cout<<"No\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solution();
    }

    return 0;
}
 
