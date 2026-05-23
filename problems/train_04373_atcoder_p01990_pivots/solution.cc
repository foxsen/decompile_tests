#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int main(){
    int n,q;
    cin >> n >> q;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int pos[n+1], push_i = n, begin_i = 0;
    for(int i=0;i<n;i++) pos[a[i]] = i;

    int query;
    for(int i=0;i<q;i++){
        cin >> query;
        a[push_i] = query;
        begin_i = (pos[query]+1) % (n+1);
        swap(pos[query], push_i);
    }

    for(int i=0;i<n-1;i++){
        cout << a[(begin_i+i)%(n+1)] << " ";
    }
    cout << a[(begin_i+n-1)%(n+1)] << endl;
}
