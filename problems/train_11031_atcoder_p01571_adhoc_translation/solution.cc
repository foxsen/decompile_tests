#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define MAX 405
#define NUM 1005

typedef pair<int,int> P; //firstは最短距離、secondは頂点の番号


//辺を表す構造体{行先、容量、コスト、逆辺のインデックス}
struct Edge{
	Edge(int arg_to,int arg_capacity,int arg_cost,int arg_rev_index){
		to = arg_to;
		capacity = arg_capacity;
		cost = arg_cost;
		rev_index = arg_rev_index;
	}

	int to,capacity,cost,rev_index;
};

int V; //頂点数
vector<Edge> G[NUM]; //グラフの隣接リスト表現
int h[NUM]; //ポテンシャル
int dist[NUM]; //最短距離
int pre_node[NUM],pre_edge[NUM]; //直前の頂点と辺
int count_table[MAX];
int index_TEXT[MAX],index_word[MAX];
char line[1005],TEXT[MAX][21],words[MAX][21];
int dp[25][25];


//fromからtoへ向かう容量capacity,コストcostの辺をグラフに追加する
void add_edge(int from,int to,int capacity,int cost){
	G[from].push_back(Edge(to,capacity,cost,G[to].size()));
	G[to].push_back(Edge(from,0,-cost,G[from].size()-1));
}

//sourceからsinkへの、流量flowの最小費用流を求める
//流せない場合は-1を返す
int min_cost_flow(int source,int sink,int flow){
	int ret = 0;
	for(int i = 0; i < V; i++)h[i] = 0; //ポテンシャルを0にする
	while(flow > 0){
		//ダイクストラ法を用いてhを更新する
		priority_queue<P,vector<P>,greater<P>> Q;
		for(int i = 0; i < V; i++)dist[i] = BIG_NUM;
		dist[source] = 0;
		Q.push(P(0,source));

		while(!Q.empty()){
			P p = Q.top();
			Q.pop();
			int node_id = p.second;
			if(dist[node_id] < p.first)continue; //最短でなければSKIP
			for(int i = 0; i < G[node_id].size(); i++){
				Edge &e = G[node_id][i];
				if(e.capacity > 0 && dist[e.to] > dist[node_id]+e.cost+h[node_id]-h[e.to]){
					dist[e.to] = dist[node_id]+e.cost+h[node_id]-h[e.to];
					pre_node[e.to] = node_id;
					pre_edge[e.to] = i;
					Q.push(P(dist[e.to],e.to));
				}
			}
		}

		if(dist[sink] == BIG_NUM){
			//これ以上流せない
			return -1;
		}

		for(int node_id = 0; node_id < V; node_id++)h[node_id] += dist[node_id];

		//source-sink間最短路に沿って目いっぱい流す
		int tmp_flow = flow;
		for(int node_id = sink; node_id != source; node_id = pre_node[node_id]){
			tmp_flow = min(tmp_flow,G[pre_node[node_id]][pre_edge[node_id]].capacity);
		}
		flow -= tmp_flow;
		ret += tmp_flow*h[sink];
		for(int node_id = sink; node_id != source; node_id = pre_node[node_id]){
			Edge &e = G[pre_node[node_id]][pre_edge[node_id]];
			e.capacity -= tmp_flow;
			G[node_id][e.rev_index].capacity += tmp_flow;
		}
	}
	return ret;
}

int calc_dist(int text_index,int word_index){

	char A[21],B[21];
	int len_A,len_B;

	for(int k = 0; TEXT[text_index][k] != '\0'; k++){

		A[k] = TEXT[text_index][k];
		A[k+1] = '\0';
	}
	for(int k = 0; words[word_index][k] != '\0'; k++){

		B[k] = words[word_index][k];
		B[k+1] = '\0';
	}

	for(len_A = 0; A[len_A] != '\0'; len_A++);
	for(len_B = 0; B[len_B] != '\0'; len_B++);

	for(int row = 0; row <= len_A; row++){
		for(int col = 0; col <= len_B; col++){

			dp[row][col] = 0;
		}
	}

	for(int col = 0; col <= len_B; col++){
		dp[0][col] = col;
	}

	for(int row = 1; row <= len_A; row++){
		dp[row][0] = row;
	}

	int cost;

	for(int row = 1; row <= len_A; row++){
		for(int col = 1; col <= len_B; col++){
			if(B[col-1] == A[row-1]){
				cost = 0;
			}else{
				cost = 1;
			}
			dp[row][col] = min(dp[row-1][col-1]+cost,min(dp[row-1][col]+1,dp[row][col-1]+1));
		}
	}

	return dp[len_A][len_B];
}

bool strCmp(char* base, char* comp){
	int length1,length2;
	for(length1=0;base[length1] != '\0';length1++);
	for(length2=0;comp[length2] != '\0';length2++);
	if(length1 != length2)return false;

	for(int i=0;base[i] != '\0'; i++){
		if(base[i] != comp[i])return false;
	}
	return true;
}

void strcpy(char* to,char* str){
	for(int i=0;str[i] != '\0';i++){
		to[i] = str[i];
		to[i+1] = '\0';
	}
}

int main(){

	int N,M;
	scanf("%d %d",&N,&M);

	int num_text = 0;
	char work[21];

	for(int i = 0; i < MAX; i++){

		count_table[i] = 0; //テキストの出現回数
	}

	int source = 0,sink = 1,index = 2;

	getchar();

	for(int loop = 0; loop < N; loop++){

		fgets(line,2000,stdin);

		for(int i = 0; line[i] != '\0' && line[i] != '\n'; ){

			int k = 0;
			while(line[i+k] != '\0' && line[i+k] != '\n' && line[i+k] != ' '){

				work[k] = line[i+k];
				work[k+1] = '\0';
				k++;
			}

			bool FLG = false;
			for(int k = 0; k < num_text; k++){
				if(strCmp(work,TEXT[k])){

					count_table[k]++;
					FLG = true;
					break;
				}
			}
			if(!FLG){ //初登場

				strcpy(TEXT[num_text],work);
				count_table[num_text] = 1;
				index_TEXT[num_text] = index++;

				add_edge(source,index_TEXT[num_text],1,0);
				num_text++;
			}
			while(line[i+k] == ' ')k++;
			if(line[i+k] == '\0' || line[i+k] == '\n')break;

			i += k;
		}
	}

	for(int i = 0; i < M; i++){

		scanf("%s",words[i]);
		index_word[i] = index++;
		add_edge(index_word[i],sink,1,0);
	}

	for(int from = 0; from < num_text; from++){

		for(int to = 0; to < M; to++){
			int tmp_dist = calc_dist(from,to);
			add_edge(index_TEXT[from],index_word[to],1,count_table[from]*tmp_dist);
		}
	}

	V = index;

	printf("%d\n", min_cost_flow(source,sink,num_text));

	return 0;
}

