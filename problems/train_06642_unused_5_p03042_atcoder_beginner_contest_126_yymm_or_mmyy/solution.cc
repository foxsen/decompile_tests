#include <iostream>
using namespace std;
int main() {
int s;
cin>>s;
int a,b;
b=s%100;
a=s/100;
if(a>=1&&a<=12)
{
    if(b>=1&&b<=12)
    {
        cout<<"AMBIGUOUS";

    }
    else
    {
        cout<<"MMYY";
    }
}
else
{
if(b>=1&&b<=12)
 cout<<"YYMM";
 else
 cout<<"NA";
}
}
