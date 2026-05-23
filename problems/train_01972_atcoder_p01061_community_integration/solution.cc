#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef ll int__;
#define rep(i,j) for(int__ i=0;i<(int__)(j);i++)
#define repeat(i,j,k) for(int__ i=(j);i<(int__)(k);i++)
#define all(v) v.begin(),v.end()

struct UnionFind{
    int n;
    vector<int> p;
    UnionFind(int nn) : n(nn+1){
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x){
        if(p[x] == x) return x;
        else return p[x] = root(p[x]);
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x != y) p[y] = x;
    }
    bool query(int x, int y){
        return root(x) == root(y);
    }
};


int main(){
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    UnionFind ut(N);
    set<int> c;
    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        if(a != b){
            c.insert(a);
            c.insert(b);
        }
        ut.unite(a, b);
    }
    set<int> s;
    rep(i, N){
        int r = ut.root(i);
        if(r != i) s.insert(ut.root(i));
    }
    int city = s.size();
    int vil = N - c.size();
    cout << abs(vil - city) << endl;

    return 0;
}