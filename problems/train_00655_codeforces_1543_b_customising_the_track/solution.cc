#include<iostream>
#include<bits/stdc++.h>
#include <cmath>

#define ll long long int
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define fi first
#define se second
#define inf INT_MAX

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()

#define sumof(v) accumulate(all(v), 0LL, plus<ll>())
#define maxof(v) max_element(all(v))
#define minof(v) min_element(all(v))


#define Vl vector<ll>
#define Vlp vector<pair<ll,ll>>
#define Vll vector<vector<ll>>
#define Vi vector<int>
#define Vip vector<pair<int,int>>
#define Vii vector<vector<int>>

#define repU(i,x,y,d) for(int i=x;i<y;i+=d)
#define repD(i,x,y,d) for(int i=x;i>=y;i-=d)

using namespace std;

int n;

int main(){
    FASTIO
    int t=1;
    cin>>t;

    while(t--){
        ll val;
        cin>>n;
        ll sm=0;
        repU(i,0,n,1){cin>>val;sm+=val;}

        if(sm%n){
            cout<<(sm%n)*(n-(sm%n))<<'\n';
        }
        else cout<<0<<'\n';

    }
    return 0;
}
