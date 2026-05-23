#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF 99999999
#define eps 1e-9


int main(){
    double xa1,ya1,xa2,ya2,xb1,yb1,xb2,yb2;
    while(cin>>xa1>>ya1>>xa2>>ya2>>xb1>>yb1>>xb2>>yb2){
        bool f=false;
        if(xa2<xb1)f=true;
        if(xa1>xb2)f=true;
        if(ya1>yb2)f=true;
        if(ya2<yb1)f=true;
        if(f)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}