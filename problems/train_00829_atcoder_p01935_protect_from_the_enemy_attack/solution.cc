#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 5000


//辺を表す構造体(行先、容量、逆辺のインデックス)
struct Edge{
	Edge(int arg_to,int arg_capacity,int arg_rev_index){
		to = arg_to;
		capacity = arg_capacity;
		rev_index = arg_rev_index;
	}
	int to,capacity,rev_index;
};

int V,E;

vector<Edge> G[NUM]; //グラフの隣接リスト表現
vector<int> CAP1[NUM]; //容量1のエッジのインデックス
int dist[NUM]; //sourceからの距離
int cheked_index[NUM]; //どこまで調べ終わったか
bool can_visit[NUM]; //そのノードに行けるかどうか

//fromからtoへ向かう容量capacityの辺をグラフに追加する
void add_edge(int from,int to,int capacity){
	G[from].push_back(Edge(to,capacity,G[to].size()));
	G[to].push_back(Edge(from,capacity,G[from].size()-1));

	if(capacity == 1){ //容量1のエッジのインデックスを記録
		CAP1[from].push_back(G[from].size()-1);
		CAP1[to].push_back(G[to].size()-1);
	}
}

//sourceからの最短距離をBFSで計算する
void bfs(int source){
	for(int i = 0; i < V; i++)dist[i] = -1;
	queue<int> Q;
	dist[source] = 0;
	Q.push(source);

	while(!Q.empty()){
		int node_id = Q.front();
		Q.pop();
		for(int i = 0; i < G[node_id].size(); i++){
			Edge &e = G[node_id][i];
			if(e.capacity > 0 && dist[e.to] < 0){ //辺の容量が正で、かつエッジの行先に未訪問の場合
				dist[e.to] = dist[node_id]+1;
				Q.push(e.to);
			}
		}
	}
}

//増加パスをDFSで探す
int dfs(int node_id,int sink,int flow){
	if(node_id == sink)return flow; //終点についたらflowをreturn

	for(int &i = cheked_index[node_id]; i < G[node_id].size(); i++){ //node_idから出ているエッジを調査
		Edge &e = G[node_id][i];
		if(e.capacity > 0 && dist[node_id] < dist[e.to]){ //流せる余裕があり、かつsourceからの距離が増加する方法である場合
			int tmp_flow = dfs(e.to,sink,min(flow,e.capacity)); //流せるだけ流す
			if(tmp_flow > 0){ //流せた場合
				e.capacity -= tmp_flow; //流した分、エッジの容量を削減する
				G[e.to][e.rev_index].capacity += tmp_flow; //逆辺の容量を、流した分だけ増加させる
				return tmp_flow;
			}
		}
	}
	return 0;
}

void recursive(int node_id){
	can_visit[node_id] = true;
	for(int i = 0; i < G[node_id].size(); i++){
		if(can_visit[G[node_id][i].to] == false && G[node_id][i].capacity > 0){
			recursive(G[node_id][i].to);
		}
	}
}


//sourceからsinkへの最大流を求める
int max_flow(int source,int sink){ //source:始点 sink:終点
	int flow = 0,add;
	while(true){ //増加パスが存在する限り、流量を追加し続ける
		bfs(source);
		if(dist[sink] < 0)break; //sourceからsinkへと辿り着く残余グラフがない、つまり増加パスが無くなった場合、break
		for(int i = 0; i < V; i++)cheked_index[i] = 0;
		while((add = dfs(source,sink,BIG_NUM)) > 0){ //増加パスが見つかる間、加算
			flow += add;
		}
	}
	return flow;
}

int main(){

	scanf("%d %d",&V,&E);

	int from,to,capacity;

	for(int loop = 0; loop < E; loop++){
		scanf("%d %d %d",&from,&to,&capacity);
		add_edge(from,to,capacity);
	}

	int source = 0,sink = V-1;

	int flow = max_flow(source,sink);

	if(flow >= 10002){
		printf("-1\n");
		return 0;
	}

	int index;

	for(int i = 0; i < V; i++){
		for(int k = 0; k < CAP1[i].size(); k++){
			index = CAP1[i][k];
			if(G[i][index].capacity == 0){
				for(int a = 0; a < V; a++)can_visit[a] = false;
				//残余グラフ上で、iからG[i][index].toへの迂回路がないか調べる
				recursive(i);
				if(can_visit[G[i][index].to] == false){ //迂回路なし
					flow--;
					printf("%d\n",flow);
					return 0;
				}

			}
		}
	}

	if(flow > 10000){
		printf("-1\n");
	}else{
		printf("%d\n",flow);
	}

	return 0;
}

