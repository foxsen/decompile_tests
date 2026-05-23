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
#include <stack>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
double EPS=1e-10;
double EQ(double a,double b){
	return abs(a-b)<EPS;
}

const int dy[]={-1,0,0,1};
const int dx[]={0,-1,1,0};
int w,h;

vector<pii> bp[1001];
vector<int> G[1001];
int leftPoint[1001];
int rightPoint[1001];
const int INF=1000000000;
typedef pair<double,double> pdd;
typedef pair<double,int> ppd; 
bool isBalanced;
char field[101][101];
int maps[101][101];
bool used[101][101];
int blocks;

void dfs(int cy,int cx,int idx,char ch){
	used[cy][cx]=true;
	maps[cy][cx]=idx;
	for(int i=0;i<4;i++){
		int ny=cy+dy[i];
		int nx=cx+dx[i];
		if(ny>=0&&nx>=0&&ny<h&&nx<w&&!used[ny][nx]&&field[ny][nx]==ch)
			dfs(ny,nx,idx,ch);
	}
}

ppd dfs2(int now){
	int weight=0;
	double sumx=0;
	for(int i=0;i<G[now].size();i++){
		int to=G[now][i];
		ppd p=dfs2(to);
		weight+=p.second;
		sumx+=p.first*p.second;
	}
//	double basex=0;
//	int baseWeight=0;
//	for(int i=0;i<bp[now].size();i++){
//		baseWeight++;
//		basex+=bp[now][i].second+0.5;
//	}
//	double baseAvgx=basex/baseWeight;
//	sumx+=baseAvgx;
//	weight+=baseWeight;
	for(int i=0;i<bp[now].size();i++){
		weight++;
//		basex+=
		sumx+=bp[now][i].second+0.5;
	}
	double avgx=sumx/weight;
	if(!EQ(leftPoint[now],avgx)&&leftPoint[now]<avgx&&!EQ(rightPoint[now],avgx)&&avgx<rightPoint[now]){
	}
	else isBalanced=false;
	return ppd(avgx,weight);
}

void solve(){
	while(cin>>w>>h&&(w|h)){
		isBalanced=true;
		for(int i=0;i<1001;i++){
			leftPoint[i]=INF;
			rightPoint[i]=-INF;
			bp[i].clear();
			G[i].clear();
		}
		memset(used,0,sizeof(used));
		memset(maps,-1,sizeof(maps));
		blocks=0;

		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>field[i][j];
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(!used[i][j]&&field[i][j]!='.')
					dfs(i,j,blocks++,field[i][j]);
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(maps[i][j]!=-1){
					bp[maps[i][j]].push_back(pii(i,j));
					int ny=i+1;
					int nx=j;
					if(ny==h||(maps[ny][nx]!=-1&&maps[ny][nx]!=maps[i][j])){
						leftPoint[maps[i][j]]=min(leftPoint[maps[i][j]],nx);
						rightPoint[maps[i][j]]=max(rightPoint[maps[i][j]],nx);
					}
				}
			}
		}
		for(int i=0;i<blocks;i++)
			rightPoint[i]++;
		for(int i=0;i<blocks;i++){
			bool got[1001];
			memset(got,0,sizeof(got));
			for(int j=0;j<bp[i].size();j++){
				int cy=bp[i][j].first;
				int cx=bp[i][j].second;
				//for(int k=0;k<4;k++){
				{
					int k=0;
					int ny=dy[k]+cy;
					int nx=dx[k]+cx;
					if(ny>=0&&nx>=0&&ny<h&&nx<w){
						if(i==maps[ny][nx])continue;
						if(maps[ny][nx]!=-1&&!got[maps[ny][nx]]){
							got[maps[ny][nx]]=true;
							G[i].push_back(maps[ny][nx]);
						}
					}
				}
			}
		}
		int start=-1;
		for(int i=h-1;i>=0;i--){
			for(int j=0;j<w;j++){
				if(maps[i][j]!=-1){
					start=maps[i][j];
					break;
				}
			}
			if(start!=-1)break;
		}
		dfs2(start);
		if(isBalanced)
			cout<<"STABLE"<<endl;
		else cout<<"UNSTABLE"<<endl;
		//for(int i=0;i<h;i++){
		//	for(int j=0;j<w;j++){
		//		if(maps[i][j]==-1)cout<<".";
		//		else cout<<maps[i][j];
		//	}
		//	cout<<endl;
		//}
		//for(int i=0;i<blocks;i++){
		//	cout<<leftPoint[i]<<" "<<rightPoint[i]<<endl;
		//}
		//cout<<endl;
		//for(int i=0;i<blocks;i++){
		//	cout<<"from:"<<i<<endl;
		//	cout<<"to:";
		//	for(int j=0;j<G[i].size();j++){
		//		cout<<G[i][j]<<" ";
		//	}
		//	cout<<endl;
		//}
		//cout<<endl;
		//for(int i=0;i<h;i++){
		//	for(int j=0;j<w;j++){
		//		cout<<maps[i][j];
		//	}
		//	cout<<endl;
		//}
		//cout<<endl;
	}
}


int main(){
	solve();

}