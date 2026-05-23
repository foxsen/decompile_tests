#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

typedef bitset<12> B;
int m[51][51], dp[1 << 12][50][50][4];
int H, W, K;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};


int filter(int v, int x)
{
  return (v << x) ? -1 : 1; 
}

int dfs(int bit, int x, int y, int k)
{
  if(dp[bit][x][y][k] != 0)
    return dp[bit][x][y][k];
  int cnt = max(0, m[y][x]);
  int res = -100000000;
  if(x == W - 1 && y == H - 1)
    res = 0;
  B bb(bit);
  int xx = x, yy = y;
  for(int j = 0; j < 6; j++)
  {
    int d = (int)bitset<2>((bb >> (j * 2)).to_ulong()).to_ulong();
    xx -= dx[d]; yy -= dy[d];
    if(xx == x && yy == y)
      cnt = 0;
  }
  for(int i = 0; i < 4; i++)
  {
    int tx = x + dx[i], ty = y + dy[i];
    if(!(tx >= 0 && tx < W && ty >= 0 && ty < H))
      continue;
    if(m[ty][tx] == -1)
      continue;
    int dk = (dx[i] < 0 || dy[i] < 0) ? 1 : 0;
    if(k + dk > K)
      continue;

    B nb((bb << 2).to_ulong());
    nb |= bitset<12>(i);
    res = max(res, dfs(int(nb.to_ulong()), tx, ty, k + dk) + cnt);
  }
  return dp[bit][x][y][k] = res;
}

int main()
{
  cin >> H >> W >> K;
  for(int y = 0; y < H; y++)
  {
    for(int x = 0; x < W; x++)
    {
      char a;
      cin >> a;
      switch(a)
      {
        case '.':
          m[y][x] = 0;
          break;
        case '#':
          m[y][x] = -1;
          break;
        default:
          m[y][x] = a - '0';
          break;
      }
    }
  }
  cout << dfs(0, 0, 0, 0) << endl;
}