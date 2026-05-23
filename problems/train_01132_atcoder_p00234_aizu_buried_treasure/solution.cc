#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <set>
using namespace std;

class Situation{
public:
    int oxigen;
    int money;
    int h,w;
    int miningCnt;
    int bitmask;
    set<pair<int,int> > visited;
};
int mem[11][11][1<<10][51];
int field[11][11];
const int INF=100000000;
const int dy[]={0,0,1};
const int dx[]={-1,1,0};

void solve(){
    int h,w;
    int f,m,o;
    while(cin>>w>>h&&!(w==0&&h==0)){
        queue<Situation> q;
        for(int i = 0; i < 11; i++)
            for(int j = 0; j < 11; j++)
                for(int k = 0; k < (1<<10); k++)
                    fill(mem[i][j][k],mem[i][j][k]+51,INF);
        cin>>f>>m>>o;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin>>field[i][j];
                field[i][j]=-field[i][j];
            }
        }
        for(int i = 0; i < w; i++){
            Situation s;
            s.money=0;
            s.miningCnt=1;
            s.oxigen=o;
            s.h=0;
            s.w=i;
            s.bitmask=(1<<i);
            s.visited.insert(make_pair(s.h,s.w));
            s.oxigen--;
            if(s.oxigen>=1){
                if(field[s.h][s.w]>0)
                    s.money+=field[s.h][s.w];
                else
                    s.oxigen=min(m,s.oxigen-field[s.h][s.w]);
                if(s.money<=f&&s.oxigen>=1){
                    mem[s.h][s.w][(1<<i)][s.oxigen]=s.money;
                    q.push(s);
                }
            }
        }
        int minGoalCost=INF;
        while(q.size()){
            Situation s=q.front();q.pop();
            if(s.h==h-1||s.oxigen<=1){
                if(s.h==h-1&&s.oxigen>=1)
                    minGoalCost=min(minGoalCost,s.money);
                continue;
            }
            for(int i = 0; i < 3; i++){
                int toH=s.h+dy[i];
                int toW=s.w+dx[i];
                int toCost=s.money;
                int toOx=s.oxigen-1;
                int toMining=s.miningCnt;
                if(toH>=0&&toW>=0&&toH<h&&toW<w){
                    if(s.visited.find(make_pair(toH,toW))==s.visited.end()){
                        if(field[toH][toW]>0)
                            toCost+=field[toH][toW];
                        else
                            toOx=min(m,toOx-field[toH][toW]);
                        toMining++;
                    }
                    Situation ns;
                    ns.h=toH;
                    ns.w=toW;
                    ns.money=toCost;
                    ns.visited=s.visited;
                    ns.oxigen=toOx;
                    ns.visited.insert(make_pair(toH,toW));
                    ns.miningCnt=toMining;
                    ns.bitmask=s.bitmask;
                    if(i==2)
                        ns.bitmask=(1<<ns.w);
                    else
                        ns.bitmask|=(1<<ns.w);
                    if(mem[toH][toW][ns.bitmask][toOx]>toCost&&toCost<=f&&toCost<=minGoalCost){
                        if(toH!=h-1)
                            q.push(ns);
                        else
                            minGoalCost=min(minGoalCost,ns.money);
                        mem[toH][toW][ns.bitmask][toOx]=min(mem[toH][toW][ns.bitmask][toOx],toCost);
                    }
                }
            }
        }
        if(minGoalCost==INF)
            cout<<"NA"<<endl;
        else
            cout<<minGoalCost<<endl;
    }
}

int main(){
    solve();
    return 0;
}