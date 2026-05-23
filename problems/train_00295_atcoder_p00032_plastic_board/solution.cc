#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    char x;
    int r=0,m=0;
    while(cin>>a>>x>>b>>x>>c){
        if(a*a+b*b==c*c)r++;
        if(a==b)m++;
    }
    cout<<r<<endl
        <<m<<endl;
}