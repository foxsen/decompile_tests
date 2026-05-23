#include <bits/stdc++.h>
using namespace std;

int W, D, N;
bool iss[55][55];
int Min[55][55], Max[55][55];

void adjust(int x, int y)
{
    for(int i = 1; i <= W; i++)
        for(int j = 1; j <= D; j++)
    {
        int dis = abs(i-x)+abs(j-y);
        Min[i][j] = max( Min[i][j], Min[x][y]-dis );
        Max[i][j] = min( Max[i][j], Max[x][y]+dis );
    }
    //cout<<x<<' '<<y<<' '<<Min[x][y]<<' '<<Max[x][y]<<' '<<Min[1][1]<<' '<<Max[1][1]<<'\n';
}

int main()
{
    cin>>W>>D>>N;
    int x, y, z;
    for(int i = 1; i <= N; i++)
    {
        cin>>x>>y>>z;
        iss[x][y] = 1;
        Min[x][y] = Max[x][y] = z;
    }
    for(int i = 1; i <= W; i++)
        for(int j = 1; j <= D; j++)
            if(!iss[i][j])Min[i][j]=-200, Max[i][j]=200;

    for(int i = 1; i <= W; i++)
        for(int j = 1; j <= D; j++)
            adjust(i,j);

    for(int i = 1; i <= W; i++)
        for(int j = 1; j <= D; j++)
            if( Min[i][j] > Max[i][j] )
    {
        //cout<<i<<' '<<j<<' '<<Min[i][j]<<' '<<Max[i][j]<<'\n';
        cout<<"No\n";
        return 0;
    }

    int ans = 0;
    for(int i = 1; i <= W; i++)for(int j = 1; j <= D; j++)ans+=Min[i][j];

    cout<<ans<<'\n';

    return 0;
}

