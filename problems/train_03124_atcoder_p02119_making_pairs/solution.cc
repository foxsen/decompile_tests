#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
????????????????????????????????? ??§?????§  
??????????????? ??§?????§ ???????´<_??? ?????? Welcome to My Coding Space!
???????????? ??? ?´_???`??????/??? ???i     
?????????????????????????????? ???  |???|     
????????? /?????? /??£??£??£??£/??????|  
??? ???_(__??????/???    ???/ .| .|????????????  
??? ????????????/????????????/??????u??????  
---------------------------------------------------------------------------------------------------*/




int N;
vector<int> E[5010];
int f[5010][5010];
int ma[5010];
//--------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;

    int ans = 0;
    rep(i, 1, N + 1) {
        int P; cin >> P;
        E[i].push_back(P);
        E[P].push_back(i);

        queue < tuple<int, int, vector<int>>> que;
        que.push(make_tuple( i, -1, vector<int>{i} ));
        vector<int> zouka = {i};
        while (!que.empty()) {
            int cu, pa; vector<int> v;
            tie(cu, pa, v) = que.front(); que.pop();

            if (0 < v.size() && v.size() % 2 == 0 && !ma[v.front()] && !ma[v.back()]) {
                zouka = v;
                break;
            }

            int type = 0;
            if (pa < 0) type = 1;
            else type = f[cu][pa];

            fore(to, E[cu]) if (pa != to && f[cu][to] != type) {
                v.push_back(to);
                que.push(make_tuple( to, cu, v ));
                v.pop_back();
            }
        }

        if (zouka.size() % 2 == 0 && !ma[zouka.front()] && !ma[zouka.back()]) {
            ans++;
            int n = zouka.size();
            rep(i, 0, n - 1) {
                int a = zouka[i], b = zouka[i + 1];
                //printf("%d -> ", f[a][b]);
                f[a][b] = 1 - f[a][b];
                f[b][a] = 1 - f[b][a];
            } //printf("\n");
            ma[zouka.front()] = 1;
            ma[zouka.back()] = 1;
        }

        printf("%d\n", ans);
    }
}