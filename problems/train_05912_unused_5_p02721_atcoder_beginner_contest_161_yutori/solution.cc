// E - Yutori
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,K,C; string S;
	cin>>N>>K>>C>>S;

	vector<int> R(N,-1);

	int c = 0;
	int r_pos = 0;
	for(int r=N-1; r>=0; --r){
		if(c > 0) c--;
		else{
			if(S[r] == 'o'){
				R[r_pos++] = r;
				if(r_pos > K) return 0; // 働ける日に余裕があると、その日に必ず働く必要がない
				c = C;
			}
		}
	}

	reverse(R.begin(), R.begin() + r_pos);

	c = 0;
	int l_pos = 0;
	for(int l=0; l<N; ++l){
		if(c > 0) c--;
		else{
			if(S[l] == 'o'){
				if(R[l_pos++] == l) cout<< l + 1 <<endl;
				c = C;
			}
		}
	}

}