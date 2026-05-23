//Era Name Transformation
#include<bits/stdc++.h>
using namespace std;

int main(){
  int y, m, d;
  while(cin>>y>>m>>d){
    if(y<1868 || (y==1868&&m< 9) || (y==1868&&m== 9&&d< 8)){printf("pre-meiji\n"); continue;}
    if(y<1912 || (y==1912&&m< 7) || (y==1912&&m== 7&&d<30)){printf("meiji %d %d %d\n", y-1867, m, d); continue;}
    if(y<1926 || (y==1926&&m<12) || (y==1926&&m==12&&d<25)){printf("taisho %d %d %d\n", y-1911, m, d); continue;}
    if(y<1989 || (y==1989&&m==1&&d<8)){printf("showa %d %d %d\n", y-1925, m, d); continue;}
    printf("heisei %d %d %d\n", y-1988, m, d);
  }
  return 0;
}