#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

enum EVENT{ORDER, COOKED};

class Event
{
public:
	int c,t,s,id;
	EVENT e;
	
	Event(int c, int t, int s, int id, EVENT e)
	:c(c),t(t),e(e),s(s),id(id)
	{}
	
	bool operator<(const Event& a) const
	{
		if(t!=a.t) return t>a.t;
		if(e!=a.e) return e<a.e;
		if(c==a.c) return s>a.s;
		return c>a.c;
	}
};

class Order
{
public:
	int id,pt;
	Order(int id, int pt)
	:id(id),pt(pt)
	{}
	
	bool operator<(const Order& a) const
	{
		if(pt!=a.pt) return pt>a.pt;
		return id<a.id;
	}
};

int main()
{
	bool f=true;
	int M,N;
	while(cin >> M >> N, (M||N))
	{
		if(!f) cout << endl;
		f=false;
		
		int limit[20], time[20];
		map<string, int> d;
		for(int i=0; i<M; i++)
		{
			int l,t;
			string n;
			cin >> n >> l >> t;
			d[n]=i;
			
			limit[i]=l; time[i]=t;
		}
		
		priority_queue<Event> q;
		
		int order[100],cooked[100]={0},cookid=-1,cooking=0,cooktime=-1,served[100],pretime=-1;
		for(int i=0; i<N; i++)
		{
			int t,o;
			cin >> t >> o;
			order[i]=o;
			vector<Order> seq;
			for(int j=0; j<o; j++)
			{
				string n;
				cin >> n;
				seq.push_back(Order(d[n], time[d[n]]));
			}
			sort(seq.begin(), seq.end());
			for(int j=0; j<seq.size(); j++)
			{
				q.push(Event(i,t,j,seq[j].id,ORDER));
			}
		}
		while(!q.empty())
		{
			Event e=q.top(); q.pop();
			if(e.e==ORDER)
			{
				if(cookid==e.id&&cooking<limit[e.id]&&pretime==e.t||cooking==0)
				{
					int tm=e.t+time[e.id];
					pretime=e.t;
					cooktime=tm;
					cooking++;
					cookid=e.id;
					q.push(Event(e.c, tm,e.s, e.id,COOKED));
				}
				else
				{
					q.push(Event(e.c, cooktime,e.s, e.id,e.e));
					continue;
				}
			}
			else
			{
				cooking--;
				cooked[e.c]++;
				if(cooked[e.c]==order[e.c])
					served[e.c]=e.t;
			}
		}
		
		for(int i=0; i<N; i++)
			cout << served[i] << endl;
	}
}