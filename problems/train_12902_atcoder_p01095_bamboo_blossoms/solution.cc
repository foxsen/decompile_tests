#include<cstdio>
#include<cstring>

typedef long long int lli;
char prime[8000000];

int main(void) {
    while(1) {
        lli m,n;
        scanf("%lld%lld",&m,&n);
        if(!m) break;

        memset(prime, 1, sizeof(prime));
        prime[0] = prime[1] = 0;
        lli cnt=0;
        lli i;
        for(i=m; cnt<=n; i++)
            if(prime[i]) {
                cnt++;
                for(lli j=2; i*j<8000000; j++)
                    prime[i*j] = 0;
            }
        printf("%lld\n",i-1);
    }
    return 0;
}