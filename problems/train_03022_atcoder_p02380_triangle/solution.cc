#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int a,b,c;
    double cr,S,L,H;
    cin >> a >> b >> c;
    cr=(acos(-1.0)*c)/180.0;
    S=0.5*a*b*sin(cr);
    L=a+b+sqrt(a*a+b*b-2*a*b*cos(cr));
    H=b*sin(cr);
    
    printf("%lf\n%lf\n%lf\n",S,L,H);
    
    return 0;
}
