#include <cstdio>
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

const double EPS=(1e-10);
typedef long long ll;
typedef pair<int,int> pii;
bool EQ(double a,double b){
  return abs((a)-(b))<EPS;
}
void fast_stream(){
	std::ios_base::sync_with_stdio(0);
}

int C,D,W,X;
int E[101][101];
int F[101][101];

int dp[31][6][51];
int calc(){
    int ret=0;
    for(int day=D;day>=0;day--){
        for(int more=0;more<=X;more++){
            for(int w=0;w<=W;w++){
                int res=0;
                if(day==D)res=0;
                else{
                    // ツ開ツ始ツ都ツ市ツ暗環置ツづーツ個按津ィ
                    for(int pos=0;pos<C;pos++){
                        if(E[pos][day]!=0){
                            // ツ債カツつゥツ右ツつゥ
                            for(int i=-1;i<=1;i++){
                                if(i==0)continue;
                                int curPos=pos;
                                int sumw=w;
                                int sumv=0;
                                while(curPos>=0&&curPos<C){
                                    sumw-=F[curPos][day];
                                    sumv+=E[curPos][day];
                                    if(E[curPos][day]==0)break;
                                    int nmore=more;
                                    if(curPos!=pos)nmore--;
                                    if(sumw>=0&&nmore>=0)res=max(res,dp[day+1][nmore][sumw]+sumv);
                                    curPos+=i;
                                }
                            }
                        }
                    }
                    // ツつオツづ按つ「
                    res=max(res,dp[day+1][more][w]);
                }
                dp[day][more][w]=res;
            }
        }
    }
    return dp[0][X][W];
}

void solve(){
    while(cin>>C>>D>>W>>X&&(C|D|W|X)){
        for(int i=0;i<C;i++)for(int j=0;j<D;j++)cin>>E[i][j];
        for(int i=0;i<C;i++)for(int j=0;j<D;j++)cin>>F[i][j];
        int res=calc();
        cout<<res<<endl;
    }
}
int main(){

    solve();

    return 0;
}