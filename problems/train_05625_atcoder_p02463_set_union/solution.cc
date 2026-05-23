#include<bits/stdc++.h>

#define all(x) (x).begin(),(x).end()
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> a,b,c;
    int n,m;
    int x;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.insert(x);
    }

    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        b.insert(x);
    }

    set_union(all(a),all(b),inserter(c,c.end()));

    for(int i:c)
    {
        cout<<i<<endl;
    }

    return 0;
}

