#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int M,N,K,D;
int cal[6];

#define HE (M)
#define CH (M+1)
#define pb push_back
#define INF (1<<24)

class Edge
{
public:
	int u,v,c;
	Edge(int u, int v, int c)
	:u(u),v(v),c(c)
	{}
};



int toNum(string s)
{
	if(s[0]=='H') return HE;
	else if(s[0]=='D') return CH;
	else
	{
		string d=s;
		s.assign(s.begin()+1, s.end());
		istringstream ss(s);
		int t;
		ss >> t;
		if(d[0]=='C') return t-1;
	
		return t+M+1;
	}
}

int main()
{
	while(cin >> M >> N >> K >> D, (M||N||K||D))
	{
		vector<Edge> eg;
		
		for(int i=0; i<M; i++)
			cin >> cal[i];
			
		for(int i=0; i<D; i++)
		{
			string a,b;
			int s,d,c;
			cin >> a >> b >> c;
			s=toNum(a); d=toNum(b);
			
			eg.pb(Edge(s,d,c*K));
			eg.pb(Edge(d,s,c*K));
		}
		
		int dist[300][(1<<6)];
		for(int i=0; i<(1<<M); i++)
		for(int j=0; j<M+N+2; j++)
			dist[j][i]=INF;
			
		dist[HE][0]=0;
		
		while(1)
		{
			bool update=false;
			for(int i=0; i<eg.size(); i++)
			for(int j=0; j<(1<<M); j++)
			{
				Edge e=eg[i];
				if(dist[e.u][j]==INF) continue;
				if(e.v<M)
				{
					if(j&(1<<e.v)) continue;
					
					if(dist[e.u][j]+e.c-cal[e.v] < dist[e.v][j|(1<<e.v)])
					{
						update=true;
						dist[e.v][j|(1<<e.v)]=dist[e.u][j]+e.c-cal[e.v];
					}
				}
				else
				{
					if(dist[e.u][j]+e.c < dist[e.v][j])
					{
						update=true;
						dist[e.v][j]=dist[e.u][j]+e.c;
					}
				}
			}
			
			if(!update) break;
		}
		
		int ans=INF;
		for(int i=0; i<(1<<M); i++)
			ans=min(ans, dist[CH][i]);
			
		cout << ans << endl;
	}
}