#include<iostream>
using namespace std;
int n,nr,nra,nrb,i,a,b,Viz[20];

void solve(int n, int a, int b)
{
    if(n==1)
    {
        cout<<a<<" "<<b<<" ";
        return;
    }
    int i,fb=0,sb=0;
    for(i=0; i<nr; i++)
        if(((((1<<i)&a)!=0)^(((1<<i)&b)!=0))==1)
        {
            fb=i;
            break;
        }
    Viz[fb]=1; //daca pun un bit facut deja 1 atunci o sa-i anuleze efectul si
               //o sa am repretitii
    for(i=0; i<nr; i++)
        if(!Viz[i])
        {
            sb=i;
            break;
        }
    solve(n-1,a,a^(1<<sb));
    solve(n-1,a^(1<<sb)^(1<<fb),b);
    Viz[fb]=0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>a>>b;
    for(i=0; i<n; i++)
        if(a&(1<<i))
            nra++;
    for(i=0; i<n; i++)
        if(b&(1<<i))
            nrb++;
    if(nra%2==nrb%2) //paritatile alterneaza
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    nr=n;
    solve(n,a,b);
    cout<<"\n";
    return 0;
}
