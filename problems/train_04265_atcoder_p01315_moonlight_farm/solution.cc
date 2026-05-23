#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
typedef pair<int,int> P;

//-----------------------------------------------------------------------

double calc(int p,int a,int b,int c,int d,int e,int f,int s,int m){
    int profit=f*s*m-p;
    int time=a+b+c+(d+e)*m;
    return (double)profit/time;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while(cin>>n,n)
    {
        vector<pair<double,string> > vec;
        REP(i,n){
            string str;
            int p,a,b,c,d,e,f,s,m;
            cin>>str>>p>>a>>b>>c>>d>>e>>f>>s>>m;
            double x=calc(p,a,b,c,d,e,f,s,m);
            vec.push_back(make_pair(-x,str));
        }
        sort(ALL(vec));

        REP(i,n) cout<<vec[i].second<<endl;
        cout<<"#"<<endl;
    }
}
