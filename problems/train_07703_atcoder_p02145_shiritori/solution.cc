#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 1000000000

struct max_flow
{
    int V;
    struct edge{int to,cap,rev;};
    using Graph=vector<vector<edge>>;
    Graph graph;
    vector<bool> visit;
public:
    max_flow(int n) //与えられた頂点は別にスタートとシンクを設定する場合
    {
        V=n;
        graph.resize(V+2,vector<edge> ());
        visit.resize(V+2,false);
    }

    void add_edge(int from,int to, int cap)
    {
        graph[from].pb((edge){to,cap,(int)graph[to].size()});
        graph[to].pb((edge){from,0,(int)graph[from].size()-1});
        return ;
    }

    int dfs(int s, int t, int f)
    {
        if (s==t) return f;
        visit[s]=true;
        for (int i=0;i<graph[s].size();i++)
        {
            edge &e=graph[s][i];
            if (!visit[e.to] && e.cap>0)
            {
                int d=dfs(e.to,t,min(f,e.cap));
                if (d>0)
                {
                    e.cap-=d;
                    graph[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }

    int run(int s,int t)
    {
        int flow=0;
        for (;;) //while文
        {
            for (int i=0;i<V+2;i++) visit[i]=false;//memsetは初期化
            int f=dfs(s,t,INF);
            if (f==0) return flow;
            else flow+=f;
        }
    }
};

int main()
{
    int N; cin >> N;
    int cnt[28][28];string input;
    for (int i=0;i<27;i++)
        for (int j=0;j<27;j++) cnt[i][j]=0;
    for (int i=0;i<N;i++)
    {
        cin >> input;
        cnt[(int)input[0]-'a'][(int)input[input.size()-1]-'a']++;
    }
    vector<char> ans;
    for (int s=0;s<26;s++)
    {
        max_flow solve(26);
        for (int i=0;i<26;i++)
        {
            if (i!=s)
            {
                for (int j=0;j<26;j++)
                {
                    if (j!=s && cnt[i][j]>0 &&i!=j) solve.add_edge(i+1,j+1,cnt[i][j]);
                }
            }
            else continue;
        }
        int sum=0;
        bool ok=false;
        if (cnt[s][s]>0) {ok=true;solve.add_edge(0,27,cnt[s][s]);}
        for (int i=0;i<26;i++)
        {
            sum+=cnt[s][i];
            if (cnt[s][i]>0 && i!=s ) solve.add_edge(0,i+1,cnt[s][i]);
            if (cnt[i][s]>0 && i!=s) {solve.add_edge(i+1,27,cnt[i][s]);ok=true;}
        }
        if (solve.run(0,27)==sum && ok)
        {
            char a='a'+s;
            ans.pb(a);
        }
    }
    for (int i=0;i<ans.size();i++) cout << ans[i] << endl;
return 0;
}
