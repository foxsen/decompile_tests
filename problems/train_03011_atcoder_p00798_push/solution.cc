#include <cstdio>
#include <deque>
#include <set>
#include <cstring>
using namespace std;

int w, h;
char field[9][9];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int solve(){
	int cargo = -1, man = -1;
	for(int i = 1; i <= h; ++i)
	for(int j = 1; j <= w; ++j){
		if(field[i][j] == 2){
			cargo = i << 8 | j;
		}
		else if(field[i][j] == 4){
			man = i << 8 | j;
		}
	}
	
	set<int> st;
	deque<int> dq;
	dq.push_back(cargo << 16 | man);
	st.insert( dq.front() );
	dq.push_back(-1);

	int ans = 1;
	while(dq.size() > 1){
		int t = dq.front();
		dq.pop_front();
		
		if(t < 0){
			++ans;
			dq.push_back(t);
		}
		else{
			int mx = t & 255;
			int my = (t >> 8) & 255;
			int cx = (t >> 16) & 255;
			int cy = (t >> 24) & 255;

			for(int i = 0; i < 4; ++i){
				int mx2 = mx + dx[i], my2 = my + dy[i];

				if(mx2 == cx && my2 == cy){
					int cx2 = cx + dx[i], cy2 = cy + dy[i];
					if(field[cy2][cx2] == 3){
						return ans;
					}
					if(field[cy2][cx2] != 1){
						int u = cy2 << 24 | cx2 << 16 | my2 << 8 | mx2;
						if( st.insert(u).second ){
							dq.push_back(u);
						}
					}
				}
				else if(field[my2][mx2] != 1){
					int u = cy << 24 | cx << 16 | my2 << 8 | mx2;
					if( st.insert(u).second ){
						dq.push_front(u);
					}
				}
			}
		}
	}
	
	return -1;
}


int main(){
	while( scanf("%d%d", &w, &h), w != 0 ){
		memset(field, 1, sizeof(field));

		int d;

		for(int i = 1; i <= h; ++i)
		for(int j = 1; j <= w; ++j){
			scanf("%d", &d);
			field[i][j] = d;
		}
		
		printf("%d\n", solve());
	}
}