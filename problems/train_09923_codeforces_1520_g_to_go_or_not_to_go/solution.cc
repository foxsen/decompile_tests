#include      <bits/stdc++.h>
using namespace std;
#define IOS       ios_base::sync_with_stdio(false); cin.tie (nullptr)
#define PREC      cout.precision (10); cout << fixed
#ifdef CONVICTION
#include "/home/convict/Dropbox/myfiles/sport_coding/cplib/snippets/debug.h"
#else
#define debug(x...)
#endif
typedef long long Int;
typedef long double ff;
#define F first
#define S second
//Don’t practice until you get it right. Practice until you can’t get it wrong

void preproc() { }
void reset() { }
void solve()
{
   const vector <int> dx{0, 1, -1, 0};
   const vector <int> dy{1, 0, 0, -1};
   int n, m;
   Int w;
   cin >> n >> m >> w;
   vector <vector <int>> mat(n, vector <int> (m));

   for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
         cin >> mat[i][j];

   function <vector <vector<int>> (int, int)> bfs
      = [&] (int sx, int sy) {
         vector <vector<bool>> vis(n, vector <bool>(m));
         vector <vector <int>> dist(n, vector <int> (m, INT_MAX));

         dist[sx][sy] = 0;
         vis[sx][sy] = true;

         queue <pair <int, int>> q;
         q.push({sx, sy});

         while (!q.empty()) {
            auto [ux, uy] = q.front();
            int& d = dist[ux][uy];
            q.pop();
            for (int rot = 0; rot < 4; ++rot) {
               int vx = ux + dx[rot];
               int vy = uy + dy[rot];
               if (vx >= 0 and vx < n and vy >= 0 and vy < m
                     and mat[vx][vy] != -1 and vis[vx][vy] == false) {
                  vis[vx][vy] = true;
                  q.push({vx, vy});
                  dist[vx][vy] = d + 1;
               }
            }
         }
         return dist;
      };

   Int res, fs, ft;
   res = fs = ft = LLONG_MAX;
   vector <vector<int>> ds = bfs(0, 0);
   vector <vector<int>> dt = bfs(n-1, m-1);

   if (ds[n-1][m-1] != INT_MAX)
      res = min(res, w*ds[n-1][m-1]);

   for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
         if (mat[i][j] > 0) {
            if (ds[i][j] != INT_MAX)
               fs = min(fs, w*ds[i][j] + mat[i][j]);
            if (dt[i][j] != INT_MAX)
               ft = min(ft, w*dt[i][j] + mat[i][j]);
         }
   if (fs != LLONG_MAX and ft != LLONG_MAX)
      res = min(res, fs + ft);

   cout << (res == LLONG_MAX ? -1 : res) << '\n';
}

signed main()
{
   IOS; PREC;
   preproc();
   int tc = 1;
   // cin >> tc;
   for (int Tt = 1; Tt <= tc; ++Tt) {
      // debug(Tt);
      // cout << "Case #" << Tt << ": ";
      reset();
      solve();
   }
   return EXIT_SUCCESS;
}
