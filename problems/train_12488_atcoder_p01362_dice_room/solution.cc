#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

// ツサツイツコツδ債づ個姪環づ個遷ツ暗堋表ツ．ツ姪環氾板債づ債，ツ湘」ツ，ツ債カツ，ツ青ウツ姪環，ツ可コツ，ツ右ツ，ツ背ツ姪環づ個渉．
char dice[6][4] = {
	{5,2,1,4}, {1,1,3,0}, {0,3,2,2},
	{2,5,4,1}, {4,4,0,3}, {3,0,5,5}
};

int main(){
	int step[6][6];
	memset(step, -1, sizeof(step));
	queue< pair<pair<int, int>, int> > qu;
	qu.push(make_pair(make_pair(0, 2), 0));
	qu.push(make_pair(make_pair(0, 5), 0));
	while(!qu.empty()){
		pair< pair<int,int>, int > p = qu.front(); qu.pop();
		int a = p.first.first, b = p.first.second, c = p.second;
		if(step[a][b] != -1) continue;
		step[a][b] = c;
		for(int i=0;i<4;i++)
			qu.push(make_pair(make_pair(dice[a][i], dice[b][i]), c+1));
	}
	string str[6][3];
	int conv[6] = {2, 4, 5, 1, 0, 3};
	int mask[3][3] = {
		{ 9, 1, 3},
		{ 8, 0, 2},
		{12, 4, 6}
	};
	int front[3] = {0, 1, 4};
	int back[3]  = {2, 3, 5};
	int up[3][4] = {
		{5, 1, 4, 3},
		{5, 2, 4, 0},
		{2, 1, 0, 3}
	};
	while(cin >> str[0][0]){
		if(str[0][0] == "#") break;
		cin >> str[0][1] >> str[0][2];
		for(int i=1;i<6;i++)
			for(int j=0;j<3;j++) cin >> str[i][i==5 ? 2-j : j];
		for(int i=0;i<2;i++)
			for(int j=0;j<3;j++) reverse(str[i][j].begin(), str[i][j].end());
		int ans = 1000000000;
		for(int i=0;i<3;i++){
			int mf = 0, mb = 0;
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++){
					if(str[front[i]][j][k] == '*') mf |= mask[j][k];
					if(str[back[i]][j][k]  == '*') mb |= mask[j][k];
				}
			int m = (mf&mb);
			for(int j=0;j<4;j++)
				if(m&(1<<j)){
					ans = min(ans, step[conv[up[i][j]]][conv[front[i]]]);
					ans = min(ans, step[conv[up[i][j]]][conv[back[i]]]);
				}
		}
		cout << ans << endl;
	}
}