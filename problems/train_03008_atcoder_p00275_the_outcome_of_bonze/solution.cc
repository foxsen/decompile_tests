#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int N;
    char S[101];
    while(scanf("%d",&N),N) {
        scanf("%s",S);
        int H[10]={0},F=0,T=0;
        for(int i=0;i<100;i++) {
            if(S[i]=='S') {
                F+=H[T]+1;
                H[T]=0;
            }else if(S[i]=='M') {
                H[T]++;
            }else {
                H[T]+=F+1;
                F=0;
            }
            if(T==N-1) T=0; else T++;
        }
        sort(H,H+N);
        for(int i=0;i<N;i++) {
            printf("%d ",H[i]);
        }
        printf("%d\n",F);
    }
}