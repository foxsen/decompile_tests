#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct State{
	int t, s, d;
	State(int t_, int s_, int d_){
		t = t_; s = s_; d = d_;
	}
	State(){}
};
bool operator<(const State &a, const State &b){
	return a.t < b.t;
}

int main(){
	int N, M;
	while( cin >> N >> M, N || M ){
		vector<bool> c(N, false);
		c[0] = true;
		vector<State> v;
		for(int i=0 ; i < M ; i++ ){
			int t, s, d;
			cin >> t >> s >> d;
			s--, d--;
			v.push_back(State(t, s, d));
		}
		sort(v.begin(), v.end());
		for(int i=0 ; i < v.size() ; i++ ){
			if( c[v[i].s] ) c[v[i].d] = true;
		}
		int ans = 0;
		for(int i=0 ; i < N ; i++ ){
			if( c[i] ) ans++;
		}
		cout << ans << endl;
	}
}