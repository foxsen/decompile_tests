#include "bits/stdc++.h"
using namespace std;

class Edge
{
	public:
	int from,to,cost,index;
	Edge(int f,int t,int c,int i)
	{
		from=f;
		to=t;
		cost=c;
		index=i;
	}
};

bool comp(Edge &lhs, Edge &rhs)
{
	return lhs.cost<rhs.cost;
}

class UF
{
	public:
	int s;
	vector<int> par;
	vector<int> dep;
	vector<int> size;

	UF(int n)
	{
		s=n;
		par.resize(s);
		dep.resize(s);
		size.resize(s);
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			dep[i]=0;
			size[i]=1;
		}
	}

	int find(int x)
	{
		if(par[x]==x)
			return x;
		else
			return par[x]=find(par[x]);
	}

	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y)
			return;
		if(dep[x]<dep[y])
		{
			par[x]=y;
			size[y]+=size[x];
		}else{
			par[y]=x;
			size[x]+=size[y];
			if(dep[x]==dep[y])
				dep[x]++;
		}
	}

	bool same(int x,int y)
	{
		return find(x)==find(y);
	}

	int getSize(int x)
	{
		return size[find(x)];
	}
};

vector<Edge> v;
vector<int> nouseind;
bool use[50000];
int mst(int n,int nouse)
{
	int ret=0;
	UF u=UF(n);
	for(int i=0;i<v.size();i++)
	{
		Edge e=v[i];
		if(!u.same(e.from,e.to) && i!=nouse)
		{
			u.unite(e.from,e.to);
			ret+=e.cost;
			use[i]=true;
		}
		if(u.getSize(0)>=n)
			break;
	}
	if(u.getSize(0)<n)
		return -1;
	else
		return ret;
}


int main()
{
	int n,m;
	int ans1=0;
	int ans2=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d,c;
		cin>>s>>d>>c;
		s--;d--;
		v.push_back(Edge(s,d,c,i));
	}
	fill(use,use+50000,false);
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<m;i++)
	{
		//cerr<<v[i].cost<<endl;
		v[i].index=i;
	}
	
	//start mst
	int init=mst(n,-1);
	for(int i=0;i<m;i++)
	{
		if(use[i])
			nouseind.push_back(i);
	}
	//cerr<<init<<" "<<nouseind.size()<<endl;
	for(int i=0;i<nouseind.size();i++)
	{
		if(init!=mst(n,nouseind[i]))
		{
			ans1++;
			ans2+=v[nouseind[i]].cost;
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
