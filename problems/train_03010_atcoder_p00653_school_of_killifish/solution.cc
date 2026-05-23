#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

const int inf = INT_MAX;

int data[1<<23];
int H, W;
int wid;

void init(const int f[], int h, int w)
{
  H = W = 1;
  while(H < h) H <<= 1;
  while(W < w) W <<= 1;
  wid = 2*W-1;
  fill(begin(data), end(data), inf);
  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      data[(i+H-1)*wid+(j+W-1)] = f[i*w+j];

  for(int i = 2*H-2; i > H-2; i--)
    for(int j = W-2; j >= 0; j--)
      data[i*wid+j] = min(data[i*wid+(2*j+1)], data[i*wid+(2*j+2)]);

  for(int i = H-2; i >= 0; i--)
    for(int j = 0; j < 2*W-1; j++)
      data[i*wid+j] = min(data[(2*i+1)*wid+j], data[(2*i+2)*wid+j]);
}
int query_w(int lj, int rj, int aj, int bj, int i, int k)
{
  if(rj <= aj || bj <= lj) return inf;
  if(lj <= aj && bj <= rj) return data[i*wid+k];
  return min(query_w(lj, rj, aj, (aj+bj)/2, i, 2*k+1),
	     query_w(lj, rj, (aj+bj)/2, bj, i, 2*k+2));
}
int query_h(int li, int lj, int ri, int rj, int ai, int bi, int k)
{
  if(ri <= ai || bi <= li) return inf;
  if(li <= ai && bi <= ri) return query_w(lj, rj, 0, W, k, 0);
  return min(query_h(li, lj, ri, rj, ai, (ai+bi)/2, 2*k+1),
	     query_h(li, lj, ri, rj, (ai+bi)/2, bi, 2*k+2));
}
int query(int li, int lj, int ri, int rj)
{
  return query_h(li, lj, ri, rj, 0, H, 0);
}

int r, c, q;
int grid[1000100];
int lr, lc, rr, rc;

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  while(cin >> r >> c >> q, r) {
    rep(i, r) rep(j, c) cin >> grid[i*c+j];

    init(grid, r, c);

    while(q--) {
      cin >> lr >> lc >> rr >> rc;
      cout << query(lr, lc, rr+1, rc+1) << endl;
    }
  }

  return 0;
}