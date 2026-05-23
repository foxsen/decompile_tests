#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

int num[2048][2048];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int m;
bool prime[1000001];
pair<int, int> pos[1002001];
pair<int, int> memo[1000001];

bool valid(int y, int x)
{
	return (0 <= y && y <= 2000 && 0 <= x && x <= 2000 && 1 <= num[y][x] && num[y][x] <= m);
}

pair<int, int> getMax(pair<int, int> pos)
{
	if (memo[num[pos.first][pos.second]].first != -1)
		return (memo[num[pos.first][pos.second]]);
	
	int y = pos.first, x = pos.second;
	pair<int, int> ret = make_pair(0, 0);
	for (int dx = -1; dx <= 1; dx++){
		if (valid(y + 1, x + dx)){
			pair<int, int> tmp = getMax(make_pair(y + 1, x + dx));
			if (ret < tmp) ret = tmp;
		}
	}
	
	if (prime[num[y][x]]){
		ret.first++;
		if (!ret.second) ret.second = num[y][x];
	}
	
	return (memo[num[pos.first][pos.second]] = ret);
}

int main()
{
	memset(num, -1, sizeof(num));
	
	int sx = 1000, sy = 1000;
	int n = 1;
	int step = 1, dir = 0;
	
	num[sy][sx] = n;
	pos[n++] = make_pair(sy, sx);
	while (n <= 1000000){
		for (int i = 0; i < step; i++){
			sy += dy[dir]; sx += dx[dir];
			num[sy][sx] = n;
			pos[n++] = make_pair(sy, sx);
		}
		dir = (dir + 1) % 4;
		for (int i = 0; i < step; i++){
			sy += dy[dir]; sx += dx[dir];
			num[sy][sx] = n;
			pos[n++] = make_pair(sy, sx);
		}
		dir = (dir + 1) % 4;
		step++;
	}
	
	for (int i = 3; i <= 1000000; i += 2) prime[i] = true;
	prime[2] = true;
	
	for (int i = 3; i * i <= 1000000; i += 2){
		if (prime[i] == true){
			for (int j = 3 * i; j <= 1000000; j += 2 * i) prime[j] = false;
		}
	}
	
	while (scanf("%d %d", &m, &n) && m){
		for (int i = 0; i <= 1000000; i++)
			memo[i].first = memo[i].second = -1;
		
		pair<int, int> ans = getMax(pos[n]);
		
		printf("%d %d\n", ans.first, ans.second);
	}
	
	return (0);
}