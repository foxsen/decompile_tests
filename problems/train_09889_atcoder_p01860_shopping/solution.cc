#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 999999999999

struct Info{
	ll need_time,loc;
};

struct Data{
	Data(){
		time = 0;
		loc = 0;
		need_time = 0;
	}

	Data(ll arg_time,ll arg_loc,ll arg_need_time){
		time = arg_time;
		loc = arg_loc;
		need_time = arg_need_time;
	}
	bool operator<(const struct Data &arg) const{
		if(time != arg.time){
			return time > arg.time;
		}else{
			return loc > arg.loc;
		}
	}
	ll time,loc,need_time;
};

map<ll,ll> MAP;


ll num_regi,M,K,D,S,N = 1;
ll table[500000];
vector<int> arrive[10001];
Info info[100000];

void init(ll first_N){
	while(N < first_N)N *= 2;
}

void update(ll loc,ll value){
	loc += N-1;

	table[loc] = value;

	if(N == 1)return;

	ll parent = (loc-1)/2;

	while(true){
		table[parent] = min(table[2*parent+1],table[2*parent+2]);

		if(parent == 0)break;
		else{
			parent = (parent-1)/2;
		}
	}
}



ll query(ll search_left,ll search_right,ll node_id,ll node_left,ll node_right){

	if(search_right < node_left || search_left > node_right)return NUM;

	if(search_left <= node_left && search_right >= node_right){
		return table[node_id];
	}

	ll left_min = query(search_left,search_right,2*node_id+1,node_left,(node_left+node_right)/2);
	ll right_min = query(search_left,search_right,2*node_id+2,(node_left+node_right)/2+1,node_right);

	return min(left_min,right_min);
}



int main(){


	scanf("%lld %lld %lld %lld %lld",&num_regi,&M,&K,&D,&S);

	int arrive_time;
	ll regi_index = 0;

	for(int i = 0; i < M; i++){
		scanf("%d",&arrive_time);
		arrive[arrive_time].push_back(i);
		scanf("%lld %lld",&info[i].need_time,&info[i].loc);

		auto at = MAP.find(info[i].loc);
		if(at != MAP.end()){
			info[i].loc = MAP[info[i].loc];
			continue;
		}

		MAP[info[i].loc] = regi_index;
		info[i].loc = regi_index;
		regi_index++;
	}

	if(num_regi > regi_index){
		printf("%lld\n",K*D);
		return 0;
	}

	init(regi_index);

	for(int i = 0; i <= 2*N-2; i++){
		table[i] = NUM;
	}

	for(int i = 0; i < regi_index; i++){
		update(i,0);
	}

	priority_queue<Data> Q;

	ll limit;
	if(S+D <= 10000){
		limit = S+D;
	}else{
		limit = 10000;
	}

	for(ll i = 0; i <= limit; i++){
		for(int k = 0; k < arrive[i].size(); k++){
			Q.push(Data(i,info[arrive[i][k]].loc,info[arrive[i][k]].need_time));
		}
	}

	Q.push(Data(S+D,BIG_NUM,0));
	int count = 0;
	ll tmp,ans;
	Data current;
	ll now_time = 0;

	while(count < K){

		current = Q.top();
		Q.pop();
		now_time = current.time;

		if(current.loc == BIG_NUM){

			count++;
			tmp = query(0,N-1,0,0,N-1);

			if(count == K){
				ans = max(tmp,now_time);
				break;
			}

			if(now_time+1 <= 10000){

				if(max(tmp,now_time)+D <= 10000){
					limit = max(tmp,now_time)+D;
				}else{
					limit = 10000;
				}

				for(int i = now_time+1; i <= limit;i++){
					for(int k = 0; k < arrive[i].size(); k++){
						Q.push(Data(i,info[arrive[i][k]].loc,info[arrive[i][k]].need_time));
					}
				}
			}
			Q.push(Data(max(tmp,now_time)+D,BIG_NUM,0));

		}else{

			tmp = query(current.loc,current.loc,0,0,N-1);

			if(tmp <= current.time){
				update(current.loc,now_time+current.need_time);
			}else{
				update(current.loc,tmp+current.need_time);
			}
		}
	}

	printf("%lld\n",ans-S);

	return 0;
}

