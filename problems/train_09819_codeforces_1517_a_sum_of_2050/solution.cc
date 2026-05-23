#include <iostream>

using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
    {
    long long n;
    cin>>n;
    if(n%2050!=0) cout<<-1;
    else {int k=0;n=n/205;while(n!=0){int a;a=n%10;k+=a;n=n/10;} cout<<k;}
    cout<<endl;
    }
}
