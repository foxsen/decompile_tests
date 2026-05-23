#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a%2==1 && b%2==1){puts("Hom");return 0;}
    if(c%2==1 && b%2==1){puts("Hom");return 0;}
    if(a%2==1 && c%2==1){puts("Hom");return 0;}
    puts("Tem");return 0;
}


