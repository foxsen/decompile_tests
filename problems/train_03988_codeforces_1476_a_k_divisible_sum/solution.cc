#include <bits/stdc++.h>
#define present(container, element) (container.find(element) != container.end()
#define all(c) c.begin(), c.end()
#define lli long long int
#define vi vector<int>
#define cpresent(container, element) (find(all(container),element) != container.end())
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
int main()
{
int t;

cin>>t;
while(t--)
{
    lli n, k;
    cin>>n>>k;
    lli ans=0;
    if(n%k==0)
    {
        ans=1;
    }
    else
    {
        lli r = (n/k)+1;
        r*=k;
        if(r%n==0)
        {
            ans=r/n;
        }
        else
        {
            ans=(r/n)+1;
        }

    }
    cout<<ans<<endl;

}
return 0;
}
