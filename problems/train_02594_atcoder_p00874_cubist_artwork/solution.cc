#include<bits/stdc++.h>
using namespace std;

int W, D;
int hw[21], hd[21];

int main(){
	int h;
	while(cin >> W >> D, W){
		for(int i = 0; i < 21; i++){
			hw[i] = 0;
			hd[i] = 0;
		}

		for(int i = 0; i < W; i++){
			cin >> h;
			hw[h]++;
		}

		for(int i = 0; i < D; i++){
			cin >> h;
			hd[h]++;
		}

		int ans = 0;
		for(int i = 0; i <= 20; i++){
			ans += max(hd[i], hw[i]) * i;
		}
		cout << ans << endl;
	}
}