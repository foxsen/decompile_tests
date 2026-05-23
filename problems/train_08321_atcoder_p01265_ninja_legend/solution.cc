#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<b; i++)

int W,H;
char f[85][65];
int dist[16][16],gx[16],gy[16],gN;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

class Ninja
{
public:
	int x,y,c,dir,dh;
	Ninja(int x, int y, int c, int dir, int dh)
		:x(x),y(y),c(c),dir(dir),dh(dh)
	{}
	
	bool operator<(const Ninja& n) const
	{
		return c>n.c;
	}
};

class State
{
public:
	int p,n,v,c;
	State(int p, int n, int v, int c)
		:p(p),n(n),v(v),c(c)
	{}

	bool operator<(const State& s) const
	{
		if(c!=s.c) return c>s.c;
		return n>s.n;
	}
};

void calcDist(int s)
{
	int end=0;
	priority_queue<Ninja> q;
	q.push(Ninja(gx[s],gy[s],0,0,0));

	bool hs[80][60][4][3]={0};
	while(!q.empty())
	{
		Ninja n=q.top(); q.pop();
		
		if(f[n.x][n.y]=='*'||f[n.x][n.y]=='%')
		{
			REP(i,gN)
			{
				if(n.x==gx[i]&&n.y==gy[i]&&dist[s][i]==-1)
				{
					dist[s][i]=n.c;
					end++;
					break;
				}
			}
		}
		
		if(end==gN) return;
		
		if(hs[n.x][n.y][n.dir][n.dh]) continue;
		hs[n.x][n.y][n.dir][n.dh]=1;

		REP(i,4)
		{
			int tx=n.x+dx[i], ty=n.y+dy[i];
			if(f[tx][ty]=='#') continue;
				
			if(f[tx][ty]=='^')
			{
				int dh=(n.dir==i?n.dh:0), tc=n.c+1;

				tx+=dx[i]; ty+=dy[i]; tc++;
				if(f[tx][ty]!='#')
				{

					if(f[tx][ty]!='^')
					{
						if(!hs[tx][ty][i][min(dh+1,2)])
						q.push(Ninja(tx,ty,tc,i,(dh>=2?2:0)));
					}
					else
					{
						if(dh==2)
						{
							tx+=dx[i]; ty+=dy[i]; tc++;
							if(f[tx][ty]!='^'&&f[tx][ty]!='#'&&!hs[tx][ty][i][dh])
							{
								q.push(Ninja(tx,ty,tc,i,dh));
							}
						}
					}
				}
				if(n.dh==2 && i==n.dir)
				{
					int wx,wy,px,py;
					REP(k,2)
					{
						wx=n.x+dx[(i+2*k+1)%4],wy=n.y+dy[(i+2*k+1)%4];
						px=n.x; py=n.y;
						REP(j,6)
						{
							if(f[wx][wy]!='#') break;
							if(f[px][py]=='#') break;
	
							if(!hs[px][py][i][0]&&f[px][py]!='^') 
							{
								q.push(Ninja(px,py,n.c+j,i, 0));
							}
							
							px+=dx[i]; py+=dy[i];
							wx+=dx[i]; wy+=dy[i];
						}
					}
				}
			}
			else
			{
				int dh=(n.dir==i?min(n.dh+1,2):1);
				if(hs[tx][ty][i][dh]) continue;
	
				q.push(Ninja(tx,ty,n.c+1,i,dh));
			}
		}
	}
}

pair<int, int> dp[16][1<<16];

pair<int, int> comp(pair<int, int> a, pair<int, int> b)
{
	if(a.first!=b.first) 
	{
		if(a.first > b.first) return a;
		return b;
	}
	
	if(a.second < b.second) return a;
	return b;
}

pair<int, int> calcTSP()
{
	int P=gN;
	pair<int, int> ret=make_pair(0,0);
	
	for(int i=0; i<(1<<P); i++)
	for(int j=0; j<P; j++)
		dp[j][i]=make_pair(-1,0);
		
	for(int i=1; i<P; i++)
		if(dist[0][i]!=-1) dp[i][(1<<i)]=make_pair(1,dist[0][i]);
		
	for(int i=0; i<(1<<P); i++)
	{
		for(int j=0; j<P; j++)
		{
			if(dp[j][i].first==-1) continue;
			
			for(int k=0; k<P; k++)
			{
				if(j==k) continue;
				if(i&(1<<k)) continue;
				if(dist[j][k]==-1) continue;
				
				int pn=(k==0?0:1);
				
				pair<int, int> ns=make_pair(dp[j][i].first+pn, dp[j][i].second+dist[j][k]);
				dp[k][i|(1<<k)]=comp(ns, dp[k][i|(1<<k)]);
				
				if(k==0) ret=comp(ns,ret);
			}
		}
	}
	
	return ret;
}

int main()
{
	while(cin >> H >> W, (W||H))
	{
		gN=1;
		REP(i,H) REP(j,W) 
		{
			cin >> f[j][i];
			if(f[j][i]=='%') 
			{
				gx[0]=j;
				gy[0]=i;
			}
			if(f[j][i]=='*')
			{
				gx[gN]=j;
				gy[gN]=i;
				gN++;
			}
		}
		
		memset(dist,-1,sizeof(dist));

		REP(i,gN) calcDist(i);
		
		pair<int, int> ans=calcTSP();
		cout << ans.first << " " << ans.second << endl;

	}
}