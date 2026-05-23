#include <iostream>
#define INF (1 << 31) - 1
using namespace std;

typedef pair<int,int> P;

int n,q,cnt = 1;
P dat[300000];

void init(){
	int nn = 1;
	while(nn < n) nn *= 2;
	n = nn;
	for(int i = 0;i < n * 2 - 1;i++){
		dat[i] = P(INF,0);
	}
}

void update(int a,int b,int x,int k,int l,int r){
	if(r <= a || b <= l) return;
	if(a <= l && r <= b){
		dat[k] = P(x,cnt);
		return;
	}
	update(a,b,x,k * 2 + 1,l,(l + r) / 2);
	update(a,b,x,k * 2 + 2,(l + r) / 2,r);
}

int get(int i){
	i = i + n - 1;
	int last = dat[i].second,val = dat[i].first;
	while(i){
		i = (i - 1) / 2;
		if(last < dat[i].second){
			last = dat[i].second;
			val = dat[i].first;
		}
	}
	return val;
}

int main(){
	cin >> n >> q;
	init();
	for(int i = 0;i < q;i++){
		int v;
		cin >> v;
		if(v == 0){
			int s,t,x;
			cin >> s >> t >> x;
			update(s,t + 1,x,0,0,n);
			cnt++;
		}
		else{
			int x;
			cin >> x;
			cout << get(x) << endl;
		}
	}
	return 0;
}