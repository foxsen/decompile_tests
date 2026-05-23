#include <bits/stdc++.h>
using namespace std;

//#define DEBUG 1

#define pii pair<int,int>
#define ff first 
#define ss second
typedef long long int64; 



int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int T=0,M=0;
        vector<int> t1,t2,m;
        for(char c:s){
            if( c == 'T' )
                ++T;
            else ++M;
        }
        if( s[0] == 'M' || s[s.length()-1] == 'M') {
            cout<<"NO\n";
            continue;
        }

        if( !(T&1) && 2*M == T ){
            int cnt = 0;
            int i;
            for(i=0;i<n && cnt<M;i++)
                if( s[i] == 'T'){
                    t1.push_back(i);
                    cnt++;
                }
            cnt = 0;
            for(;i<n&&cnt<M;i++)
                if( s[i] == 'T'){
                    t2.push_back(i);
                    cnt++;
                }
            cnt = 0;
            for(i=0;i<n && cnt<M;i++){
                if( s[i] == 'M'){
                    m.push_back(i);
                    ++cnt;
                }
            }
            bool chk = 1;

            for(int i=0;i<m.size()&&chk;i++)
                if( t1[i] < m[i] && m[i] < t2[i] ){}
                else chk = 0;
            if( chk ){
                cout<<"YES\n";
            }
            else cout<<"NO\n";

        }
        else cout<<"NO\n";
    }

}
