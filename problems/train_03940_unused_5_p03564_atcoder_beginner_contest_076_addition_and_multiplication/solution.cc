#include<iostream>
using namespace std;
int main()
{
    int a,b,x=1,i;
    cin>>a>>b;
    for(i = 1;i<=a;i++)
        x=min(x*2,x+b);
    cout<<x<<endl;
}
