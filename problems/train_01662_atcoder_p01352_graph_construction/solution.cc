#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 40000
#define sqrt_NUM 200

typedef pair<int,int> P;

enum Type{
	ADD,
	DELETE,
	QUERY,
};

struct Info{
	Type type;
	int from,to;
};

struct Edge{
	void set(int arg_from,int arg_to,int arg_add_time,int arg_delete_time){
		from = arg_from;
		to = arg_to;
		add_time = arg_add_time;
		delete_time = arg_delete_time;
	}
	int from,to,add_time,delete_time;
};

int V,num_query;
int edge_index;
int height[NUM],boss[NUM];
bool check[NUM];
int divide_table[2*sqrt_NUM][2*sqrt_NUM];
bool visited[2*sqrt_NUM];
Info info[NUM];
Edge edge[NUM];
vector<int> divide_G;
map<P,int> MAP;

int get_boss(int id){
	if(boss[id] == id)return id;
	else{
		return boss[id] = get_boss(boss[id]);
	}
}

int is_same_group(int x,int y){
	return get_boss(x) == get_boss(y);
}

void unite(int x,int y){
	int boss_x = get_boss(x);
	int boss_y = get_boss(y);

	if(boss_x == boss_y)return;

	if(height[x] > height[y]){

		boss[boss_y] = boss_x;

	}else if(height[x] < height[y]){

		boss[boss_x] = boss_y;

	}else{ //height[x] == height[y]

		boss[boss_y] = boss_x;
		height[x]++;
	}
}

void init(){

	for(int i = 0; i < V; i++){
		boss[i] = i;
		height[i] = 0;
	}
}

int find_loc(int node_id){

	int left = 0,right = (int)divide_G.size()-1,m = (left+right)/2;

	while(left <= right){

		if(divide_G[m] == node_id){

			return m;

		}else if(divide_G[m] > node_id){

			right = m-1;

		}else{
			left = m+1;
		}
		m = (left+right)/2;
	}
	return -1; //Error
}

void dfs(int node_id,int num){

	for(int i = 0; i < num; i++){

		if(visited[i] == false && divide_table[node_id][i] > 0){

			visited[i] = true;
			dfs(i,num);
		}
	}
}

int main(){

	scanf("%d %d",&V,&num_query);

	int command,tmp_index;
	edge_index = 0;

	for(int i = 0; i < num_query; i++){

		scanf("%d %d %d",&command,&info[i].from,&info[i].to);

		switch(command){
		case 1:

			info[i].type = ADD;
			edge[edge_index].set(info[i].from,info[i].to,i,BIG_NUM);
			MAP[P(info[i].from,info[i].to)] = edge_index;
			edge_index++;
			break;

		case 2:

			info[i].type = DELETE;
			tmp_index = MAP[P(info[i].from,info[i].to)];
			edge[tmp_index].delete_time = i;
			break;

		case 3:

			info[i].type = QUERY;
			break;
		}
	}

	int divide_size,divide_V;

	for(divide_size = 1; divide_size*divide_size < num_query; divide_size++);

	bool FLG;
	int from_index,to_index;

	for(int base_time = 0; base_time < num_query; base_time += divide_size){

		init();

		for(int i = 0; i < edge_index; i++){

			if(edge[i].add_time >= base_time)break;

			if(edge[i].add_time < base_time && edge[i].delete_time >= base_time+divide_size){
				unite(edge[i].from,edge[i].to);
			}
		}

		for(int i = 0; i < V; i++)check[i] = false;

		FLG = false;

		for(int i = base_time; i < min(base_time+divide_size,num_query); i++){

			check[get_boss(info[i].from)] = true;
			check[get_boss(info[i].to)] = true;
			if(info[i].type == QUERY){
				FLG = true;
			}
		}
		if(!FLG)continue;

		divide_G.clear();

		for(int i = 0; i < V; i++){
			if(check[i]){
				divide_G.push_back(i);
			}
		}

		divide_V = (int)divide_G.size();

		for(int i = 0; i < divide_V; i++){
			for(int k = 0; k < divide_V; k++){
				divide_table[i][k] = 0;
			}
		}

		for(int i = 0; i < edge_index; i++){

			if(edge[i].add_time >= base_time)break;

			if(edge[i].add_time < base_time && edge[i].delete_time >= base_time &&
					edge[i].delete_time < base_time+divide_size){

				from_index = find_loc(get_boss(edge[i].from));
				to_index = find_loc(get_boss(edge[i].to));

				divide_table[from_index][to_index]++;
				divide_table[to_index][from_index]++;
			}
		}

		for(int i = 0; i < divide_size && base_time+i < num_query; i++){

			from_index = find_loc(get_boss(info[base_time+i].from));
			to_index = find_loc(get_boss(info[base_time+i].to));

			switch(info[base_time+i].type){
			case ADD:

				divide_table[from_index][to_index]++;
				divide_table[to_index][from_index]++;
				break;

			case DELETE:

				divide_table[from_index][to_index]--;
				divide_table[to_index][from_index]--;
				break;

			case QUERY:

				for(int k = 0; k < divide_V; k++)visited[k] = false;
				visited[from_index] = true;
				dfs(from_index,divide_V);

				if(visited[to_index]){

					printf("YES\n");

				}else{

					printf("NO\n");
				}
				break;
			}
		}
	}

	return 0;
}

