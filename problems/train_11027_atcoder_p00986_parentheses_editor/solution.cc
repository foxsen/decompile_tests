#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 2000005
const int mod=1e6+3;
int main(){
    int cnt=0;
    LL ans=0;
    vector<pii> v;
    vector<char> vv;
    vector<pii> remove;
    v.pb(mp(0,0));
    cnt=1;
    char c[200005];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='('){
            vv.pb('(');
            v.pb(mp(v.back().x+1,0));
        }
        else if(c[i]==')'){
            vv.pb(')');
            if(v.back().x==0){
                v.pb(mp(0,0));
            }
            else{
                remove.pb(v.back());
                v.pop_back();
                
                v.back().y++;
                ans+=v.back().y;
            }
        }
        else{
            if(vv.back()=='('){
                vv.pop_back();
                v.pop_back();
            }
            else{
                vv.pop_back();
                if(v.back()==mp(0,0)){
                    v.pop_back();
                }
                else{
                    ans-=v.back().y;
                    v.back().y--;
                    v.pb(remove.back());
                    remove.pop_back();
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
