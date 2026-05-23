#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 1000005
typedef pair<int,int> P;

struct Info{
	Info(int arg_x,int arg_y,int arg_z){
		x = arg_x;
		y = arg_y;
		z = arg_z;
	}
	int x,y,z;
};

int N;
int boss[NUM],height[NUM];
int diff_x[3] = {-1,0,1},diff_y[3] = {-1,0,1},diff_z[3] = {-1,0,1};
int X,Y,Z;
int num_DEL,num_REMAIN;
vector<Info> info,DEL_GROUP[NUM];
vector<P> info_DELETE[NUM],info_REMAIN[NUM];
map<P,int> DELETE[NUM],REMAIN[NUM];


bool rangeCheck(int x,int y, int z){

	return x >= 0 && x <= X-1 && y >= 0 && y <= Y-1 && z >= 0 && z <= Z-1;
}

int get_boss(int id){
	if(boss[id] == id)return id;
	else{
		return boss[id] = get_boss(boss[id]);
	}
}

int is_same(int x,int y){
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

void init(int num){

	for(int i = 0; i < num; i++){
		boss[i] = i;
		height[i] = 0;
	}
}

bool is_DELETE(int x,int y,int z){

	auto at = DELETE[x].find(make_pair(y,z));

	if(at != DELETE[x].end()){

		return true;
	}else{

		return false;
	}
}

int main(){

	scanf("%d %d %d %d",&X,&Z,&Y,&num_DEL);

	int index_DELETE = 0;

	for(int i = 0; i < num_DEL; i++){

		int x,z,y;

		scanf("%d %d %d",&x,&z,&y);

		DELETE[x][P(y,z)] = index_DELETE++;
		info_DELETE[x].push_back(P(y,z));
		info.push_back(Info(x,y,z));
	}

	init(index_DELETE);

	//削除するキューブを連結させる
	for(int i = 0; i < index_DELETE; i++){

		Info tmp_info = info[i];

		for(int a = 0; a < 3; a++){
			for(int b = 0; b < 3; b++){
				for(int c = 0; c < 3; c++){

					if(diff_x[a] == 0 && diff_y[b] == 0 && diff_z[c] == 0)continue;

					int adj_x = tmp_info.x+diff_x[a];
					int adj_y = tmp_info.y+diff_y[b];
					int adj_z = tmp_info.z+diff_z[c];

					if(rangeCheck(adj_x,adj_y,adj_z) == true && is_DELETE(adj_x,adj_y,adj_z) == true){

						int from = i;
						int to = DELETE[adj_x][P(adj_y,adj_z)];

						unite(from,to);
					}

				}
			}
		}
	}

	for(int i = 0; i < index_DELETE; i++){

		DEL_GROUP[get_boss(i)].push_back(Info(info[i]));
	}


	int ans = 1;

	//点連結させた、取り除くキューブ集団ごとに処理する
	for(int i = 0; i < index_DELETE; i++){

		if(DEL_GROUP[i].size() == 0)continue;

		int index_REMAIN = 0;
		int min_x = BIG_NUM,max_x = -BIG_NUM;

		for(int k = 0; k < DEL_GROUP[i].size(); k++){

			min_x = min(min_x,DEL_GROUP[i][k].x);
			max_x = max(max_x,DEL_GROUP[i][k].x);
		}

		min_x = max(0,min_x-2);
		max_x = min(X-1,max_x+2);

		for(int k = min_x; k <= max_x; k++){
			REMAIN[k].clear();
			info_REMAIN[k].clear();
		}

		int L = BIG_NUM,R = -BIG_NUM;

		for(int k = 0; k < DEL_GROUP[i].size(); k++){

			Info tmp_info = DEL_GROUP[i][k];

			for(int a = 0; a < 3; a++){
				for(int b = 0; b < 3; b++){
					for(int c = 0; c < 3; c++){

						if(diff_x[a] == 0 && diff_y[b] == 0 && diff_z[c] == 0)continue;

						int adj_x = tmp_info.x+diff_x[a];
						int adj_y = tmp_info.y+diff_y[b];
						int adj_z = tmp_info.z+diff_z[c];

						if(rangeCheck(adj_x,adj_y,adj_z) == false|| is_DELETE(adj_x,adj_y,adj_z) == true){

							continue;
						}
						auto at = REMAIN[adj_x].find(P(adj_y,adj_z));
						if(at != REMAIN[adj_x].end())continue;

						L = min(L,adj_x);
						R = max(R,adj_x);
						REMAIN[adj_x][P(adj_y,adj_z)] = index_REMAIN++;
						info_REMAIN[adj_x].push_back(P(adj_y,adj_z));
					}
				}
			}
		}

		if(index_REMAIN == 0)continue;

		init(index_REMAIN);

		//REMAINを面連結させる
		for(int x = L; x <= R;x++){

			if(info_REMAIN[x].size() == 0)continue;

			for(int loop = 0; loop < info_REMAIN[x].size(); loop++){

				P tmp = info_REMAIN[x][loop];

				for(int a = 0; a < 3; a++){
					for(int b = 0; b < 3; b++){
						for(int c = 0; c < 3; c++){

							int count_zero = 0;
							if(diff_x[a] == 0)count_zero++;
							if(diff_y[b] == 0)count_zero++;
							if(diff_z[c] == 0)count_zero++;

							if(count_zero != 2)continue;


							int adj_x = x+diff_x[a];
							int adj_y = tmp.first+diff_y[b];
							int adj_z = tmp.second+diff_z[c];

							if(rangeCheck(adj_x,adj_y,adj_z) == true){

								auto at = REMAIN[adj_x].find(P(adj_y,adj_z));
								if(at == REMAIN[adj_x].end())continue;

								int from = REMAIN[x][tmp];
								int to = REMAIN[adj_x][P(adj_y,adj_z)];

								unite(from,to);
							}
						}
					}
				}
			}
		}

		int num_group = 0;

		for(int k = 0; k < index_REMAIN; k++){

			if(k == get_boss(k)){

				num_group++;
			}
		}

		ans += num_group-1;
	}

	printf("%d\n",ans);

	return 0;
}

