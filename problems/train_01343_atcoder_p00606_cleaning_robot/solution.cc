#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);

typedef vector<double> vd;
typedef vector<vd> vvd;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
char roomChar[3][3]={{'A','B','C'},{'D','E','F'},{'G','H','I'}};
char getRoomChar(int x,int y){
	return roomChar[y][x];
}
pii getRoomLoc(char c){
	REP(x,3){
		REP(y,3){
			if(roomChar[y][x]==c){
				return make_pair(x,y);
			}
		}
	}
}
int main(){
	int n;
	while(cin>>n,n){
		char s,t,b;
		cin>>s>>t>>b;
		vector<vvd> p(n+1,vvd(3,vd(3)));
		pii sl=getRoomLoc(s);
		p[0][sl.first][sl.second]=1;
		REP(i,n){
			REP(x,3){
				REP(y,3){
					REP(d,4){
						int xx=x+dx[d];
						int yy=y+dy[d];
						if(xx>=0&&yy>=0&&xx<3&&yy<3&&getRoomChar(xx,yy)!=b){
								p[i+1][xx][yy]+=p[i][x][y]/4;
						}else{
							p[i+1][x][y]+=p[i][x][y]/4;
						}
					}
				}
			}
		}
		pii tl=getRoomLoc(t);
		printf("%.10f\n",p[n][tl.first][tl.second]);
	}
}