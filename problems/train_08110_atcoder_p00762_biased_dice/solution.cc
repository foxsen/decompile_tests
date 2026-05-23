#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
 
const ll MOD=1e9+7;
const ll INF=1e18;
 
int dx[]={0, 1, 0, -1};
int dy[]={-1, 0, 1, 0};


int n,h[405][405],num[405][405];
int ss[][7] = {
	{ 0,0,0,0,0,0,0, },
	{ 0,0,3,5,2,4,0, },
	{ 0,4,0,1,6,0,3, },
	{ 0,2,6,0,0,1,5, },
	{ 0,5,1,0,0,6,2, },
	{ 0,3,0,6,1,0,4, },
	{ 0,0,4,2,5,3,0, },
};

int main(){
	while(true){
		cin >> n;
    	if(n == 0)break;
    	for(int i = 0;i < 400;i++){
      		for(int j = 0;j < 400;j++){
        		h[i][j] = 0;
        		num[i][j] = -1;
      		}
    	}
		for(int ii = 0;ii < n;ii++){
			int t,f;
			cin >> t >> f;
			int s = ss[t][f];
			int side[] = {f,s,7-f,7-s};
			int nmax = -1,rot = -1;
			int x = 200,y = 200;
			bool flag = false;
			for(int k = 0;k < 4;k++){
				if(side[k] >= 4 && side[k] > nmax && h[x][y] > h[x+dx[k]][y+dy[k]]){
					rot = k;
					nmax = side[k];
					flag = true;
				}
			}
			while(flag == true){
				flag = false;
				x = x + dx[rot]; y = y + dy[rot];
				if(rot == 0){
					int f_tmp = f;
					f = t;
					t = 7 - f_tmp;
				}else if(rot == 1){
					int s_tmp = s;
					s = t;
					t = 7 - s_tmp;
				}else if(rot == 2){
					int t_tmp = t;
					t = f;
					f = 7 - t_tmp;
				}else{
					int t_tmp = t;
					t = s;
					s = 7 - t_tmp;
				}
				nmax = -1; 
				rot = -1;
				side[0] = f; side[1] = s; side[2] = 7-f; side[3] = 7-s;
				for(int k = 0;k < 4;k++){
					if(side[k] >= 4 && side[k] > nmax && h[x][y] > h[x+dx[k]][y+dy[k]]){
						rot = k;
						nmax = side[k];
						flag = true;
					}
				}
			}
			h[x][y]++;
			num[x][y] = t;
		}
		int ans[7];
		for(int i = 1;i <= 6;i++) ans[i] = 0;
		for(int i = 0;i < 400;i++){
			for(int j = 0;j < 400;j++){
				if(num[i][j] >= 1) ans[num[i][j]]++;

			}
		}
		cout << ans[1];
		for(int i = 2;i <= 6;i++){
			cout << " " << ans[i];
		}
		cout << endl;
  	}
}
