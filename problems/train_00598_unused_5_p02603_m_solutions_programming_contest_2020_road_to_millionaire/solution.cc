// D - Road to Millionaire
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin>>N;
	int64_t yen = 1000;
	int now; cin>>now;
	for(int i=0; i<N-1; ++i){
		int nxt; cin>>nxt;
		yen += max(0L, yen/now * (nxt - now));
		now = nxt;
	}
	cout<< yen <<endl;
}
