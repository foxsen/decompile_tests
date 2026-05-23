#include<cstdio>
using namespace std;
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31},b,c;
int main(){
	scanf("%d%d",&b,&c);
    puts(a[b]==a[c]?"Yes":"No");
}