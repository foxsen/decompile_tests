#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,m;
pair<int,int> crna[200010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	int r,c;
	while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
            cin>>r>>c, crna[i]=make_pair(c,r);
        if(m%2==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sort(crna,crna+m);
        bool ok=true;
        for(int i=0;i<m && ok;i++)
        {
            if(i%2==1)
            {
                if(i+1<m && crna[i+1].first==crna[i].first)
                    ok=false;
                int d=crna[i].first-crna[i-1].first+crna[i].second-crna[i-1].second+2;
                if(d%2==0)
                    ok=false;
            }

        }
        if(ok)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }

	return 0;
}
