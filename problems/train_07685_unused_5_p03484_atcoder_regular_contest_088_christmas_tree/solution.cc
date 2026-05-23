#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, A;
vector<int> e[N];

int g(vector<int> &v, int z){
    for(int i = -(v.size() & 1), j = int(v.size()) - 1; i < j; i++, j--){
        int t = v[j];
        if(i >= 0) t += v[i];
        if(t > z) return -1;
    }
    return 0;
}

int h(vector<int> &v, int m, int z){
    if((m >= 0 ? v[m] : 0) + 1 > z) return -1;
    vector<int> w;
    for(int i = 0; i < v.size(); i++) if(i != m) w.push_back(v[i]);
    return g(w, z);
}

int f(int x, int y, int z){
    vector<int> v;
    for(int i : e[x]){
        if(i == y) continue;
        v.push_back(f(i, x, z));
        if(v.back() < 0) return -1;
    }
    if(v.empty()) return 1;
    sort(v.begin(), v.end());
    if(!y) return g(v, z);
    int l = -(~v.size() & 1), r = v.size() - 1;
    while(l < r){
        int m = (l + r + 2) / 2 -1;
        if(h(v, m, z) >= 0) r = m;
        else l = m + 1;
    }
    if(h(v, l, z) < 0) return -1;
    return (l >= 0 ? v[l] : 0) + 1;
}

int main(){
    scanf("%d", &n);
    for(int i = 0, x, y; i < n - 1; i++){
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    A = n - 1;
    for(int i = 1; i <= n; i++) A -= int(e[i].size()) / 2;
    printf("%d ", A);
    int l = 1, r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(f(1, 0, m) >= 0) r = m;
        else l = m + 1;
    }
    printf("%d\n", l);
}