#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

struct edge{
    int to;
    char ch;
};

vector<edge> G[2][4000];
// dp[i][j]->m[gÌm[hði,m[gÌRs[Ìm[hðjÆµ½Æ«A»±ÜÅÉ¤ÊµÄ»êé¶ÍÌ
//int dp[3600][3600];
map<int,map<int,int> > dp;
int n[2],m[2];

const int INF=-1;
const int MOD=1000000007;

int dfs(int idx1,int idx2){
    //if(dp[idx1][idx2]!=-1)
    //    return dp[idx1][idx2];
    if(!(dp.find(idx1)==dp.end()||dp[idx1].find(idx2)==dp[idx1].end()))
        return dp[idx1][idx2];
    if(idx1==0&&idx2==0)
        return 1;
    else if(idx1==0||idx2==0)
        return 0;
    // »ÝÌn_É¢½é[gð·×Ä²×ã°é
    // ßèûÌgÝí¹ðXgAbvµA·×Ä²×é
    int res=0;
    for(int i = 0; i < G[0][idx1].size(); i++){
        edge back=G[0][idx1][i];
        for(int j = 0; j < G[1][idx2].size(); j++){
            edge back2=G[1][idx2][j];
            if(back.ch==back2.ch){
                res+=dfs(back.to,back2.to);
                res%=MOD;
            }
        }
    }
    return dp[idx1][idx2]=res%MOD;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        dp.clear();
        //memset(dp,0,sizeof(dp));
        //for(int i = 0; i < 3600; i++)
        //    fill(dp[i],dp[i]+3600,INF);
        for(int j = 0; j < 2; j++)
            for(int i = 0; i < 4000; i++)
                G[j][i].clear();
        for(int j = 0; j < 2; j++){
            cin>>n[j]>>m[j];
            int idx=n[j];
            for(int i = 0; i < m[j]; i++){
                int from,to;
                string str;
                cin>>from>>to>>str;
                // ¶ñðª£µÄ»ê¼êÉidðÂ¯ÄGÉi[·é
                int prv=from;
                for(int k = 0; k < str.size(); k++){
                    edge e;
                    e.to=prv;
                    e.ch=str[k];
                    int tmp=idx;
                    if(k==str.size()-1){
                        tmp=to;
                    }
                    G[j][tmp].push_back(e);
                    prv=tmp;
                    if(k==str.size()-1)
                        break;
                    idx++;
                }
            }
        }
        // »ÄAÅ¦ã°
        int res=dfs(n[0]-1,n[1]-1);
        cout<<res%MOD<<endl;
    }

    return 0;
}