#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

class UnionFindTree
{
    int n;
    vector<int> parent; // 親ノード
    vector<int> rank;   // 木の高さの上限
    vector<int> num;    // グループの要素数
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
public:
    UnionFindTree(int n0){ // コンストラクタ
        n = n0;
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = i;
        rank.assign(n, 0);
        num.assign(n, 1);
    }
    void unite(int x, int y){ // xとyのグループを併合
        if((x = find(x)) != (y = find(y))){
            if(rank[x] < rank[y]){
                parent[x] = y;
                num[y] += num[x];
            }else{
                parent[y] = x;
                if(rank[x] == rank[y])
                    ++ rank[x];
                num[x] += num[y];
            }
            -- n;
        }
    }
    bool same(int x, int y){ // xとyのグループが同じかを調べる
        return find(x) == find(y);
    }
    int getNum(){ // グループの数を返す
        return n;
    }
    int getNum(int x){ // xのグループの要素数を返す
        return num[find(x)];
    }
};

template <size_t T>
bool nextBitset(bitset<T> &bs, int digit)
{
    if(bs.none())
        return false;
    bitset<T> x, y, z;
    x = bs.to_ulong() & (~(bs.to_ulong()) + 1ULL);
    y = bs.to_ulong() + x.to_ulong() + 0ULL;
    z = bs & ~y;
    if(bs[digit-1] && bs == z)
        return false;
    bs = ((z.to_ulong() / x.to_ulong()) >> 1) + 0ULL;
    bs |= y;
    return true;
}

int n, m;
vector<string> name;
vector<bitset<30> > use;

void solve()
{
    for(int i=1; i<=min(5, n); ++i){
        bitset<30> bs((1<<i)-1);
        do{
            UnionFindTree uft(m);
            for(int j=0; j<m; ++j){
                for(int k=0; k<j; ++k){
                    if((use[j] & use[k] & bs).any())
                        uft.unite(j, k);
                }
            }

            if(uft.getNum() == 1){
                cout << i << endl;
                for(int j=0; j<n; ++j){
                    if(bs[j])
                        cout << name[j] << endl;
                }
                return;
            }
        }while(nextBitset(bs, n));
    }

    cout << "Impossible" << endl;
}

int main()
{
    bool isFirst = true;

    for(;;){
        cin >> n >> m;
        if(n == 0)
            return 0;

        name.resize(n);
        map<string, int> index;
        for(int i=0; i<n; ++i){
            cin >> name[i];
            index[name[i]] = i;
        }

        use.assign(m, 0);
        for(int i=0; i<m; ++i){
            int a;
            cin >> a;
            for(int j=0; j<a; ++j){
                string s;
                cin >> s;
                use[i][index[s]] = true;
            }
        }

        if(isFirst)
            isFirst = false;
        else
            cout << endl;

        solve();
    }
}