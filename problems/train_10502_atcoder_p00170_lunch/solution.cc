#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct food{
	string n;
	int w;
	int s;
	int used;
};

int main(){
	int n;
	while(cin >> n){
		vector<food> vf;
		if(n == 0 ) break;
		for(int i = 0; i < n; i++){
			food f;
			cin >> f.n >> f.w >> f.s;
			f.used = 0;
			vf.push_back(f);
		}
		int weight = 0;
		for(int i = 0; i < n; i++) weight += vf[i].w;
		for(int i = 0; i < n; i++){
			vector<int> vi;
			for(int j = 0; j < n; j++){
				if(!vf[j].used && vf[j].s >= weight - vf[j].w){
					vi.push_back(j);
				}
			}
			int wmax = -1;
			int u;
			for(int j = 0; j < vi.size(); j++){
				if(wmax <vf[vi[j]].w){
					wmax = vf[vi[j]].w;
					u = vi[j];
				}
			}
			cout << vf[u].n << endl;
			vf[u].used = 1;
			weight -= vf[u].w;
		}
	}
	return 0;
}