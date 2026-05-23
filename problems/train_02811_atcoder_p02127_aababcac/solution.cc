#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

bool isSubstr(string &s, string &t){
    int p = 0;
    rep(i,s.size()){
        if(s[i]==t[p]){
            p++;
        }
        if(p==t.size())break;
    }
    
    if(p==t.size())return true;
    else return false;
}

int main(){
    string s,t;
    
    cin>>s>>t;
    
//    vector<string> vs(18,"");
//    vs[1] = t;
//    int l = t.size();
//    for(int i=2;i<18;i++){
//        l = (l+1)*t.size() + l;
//        if(l>s.size())break;
//        vs[i] = t;
//        rep(j,vs[i-1].size()){
//            vs[i]+=string(1,vs[i-1][j]);
//            vs[i]+=t;
//        }
//        assert(l==vs[i].size());
//    }
//
//    for(int i=1;i<18;i++)if(vs[i]=="")vs[i] = "*";
    
    vector<string> vs(2);
    vs[1] = t;
    int ok = 0;
    for(int i=1;i<18;i++){
        
        if(isSubstr(s,vs[i%2]))ok = i;
        else break;
        int l = (vs[i%2].size()+1)*t.size() + vs[i%2].size();
        
        if(l>s.size())break;
        vs[(i+1)%2] = t;
        rep(j,vs[i%2].size()){
            vs[(i+1)%2] += string(1,vs[i%2][j]);
            vs[(i+1)%2] += t;
        }
    }
    cout<<ok<<endl;
}


