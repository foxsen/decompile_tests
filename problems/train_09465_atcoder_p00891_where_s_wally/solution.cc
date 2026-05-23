#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cstring>
#include <queue>
#include <map>
#include <list>
#include <cmath>
#include <iomanip>
#define INF 0x3f3f3f3f
#define EPS 10e-5

typedef long long ll;
typedef unsigned long long ull;
const int dx[]={-1,0,0,1,0},dy[]={0,1,-1,0,0};
using namespace std;
int w,h,p;
const ull B = 1000007,B2 = 239973;
ull ba[1005],ba2[1005],vhash[6006];
char vc[256];
char mat[6006][6006];
char model[2][606][606];
char tmp[1005];
set<ull> cts;
void rotate(char in[606][606],char out[606][606]){
    for(int i=0;i<p;++i){
        for(int j=0;j<p;++j){
            out[j][p-1-i] = in[i][j];
        }
    }

}

void vmirrorOver(char in[606][606],char out[606][606]){
    for(int i=0;i<p;++i){
        for(int j=0;j<p;++j){
            out[i][p-1-j] = in[i][j];
        }
    }
}

void hmirrorOver(char in[606][606],char out[606][606]){
    for(int i=0;i<p;++i){
        for(int j=0;j<p;++j){
            out[p-1-i][j] = in[i][j];
        }
    }
}

ull hashit(char in[606][606]){
    ull res = 0;
    for(int i=0;i<p;++i){
        ull nres = 0;
        for(int j=0;j<p;++j){
            nres *= B;
            nres += in[i][j];
        }
        res*=B2;res+=nres;
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<26;++i)
        vc[i+'A'] = i;
    for(int i=0;i<26;++i)
        vc[i+'a'] = i+26;
    for(int i=0;i<10;++i)
        vc[i+'0'] = i+52;
    vc['+'] = 62;
    vc['/'] = 63;

    ba[0] = ba2[0] = 1;
    for(int i=1;i<=1003;++i){
        ba[i] = ba[i-1]*B;
        ba2[i] = ba2[i-1]*B2;
    }

    while(true){
        scanf("%d%d%d",&w,&h,&p);
        if(w==0&&h==0&&p==0) break;
        cts.clear();
        memset(vhash,0,sizeof(vhash));
        memset(model,0,sizeof(model));
        memset(mat,0,sizeof(mat));
        for(int i=0;i<h;++i){
            scanf("%s",tmp);
            int e = ceil(w/6.0);
            for(int j=0;j<e;++j){
                tmp[j] = vc[tmp[j]];
                for(int k=5;k>=0;--k){
                    mat[i][j*6+k] = tmp[j]&1;
                    tmp[j]>>=1;
                }
            }
        }

        for(int i=0;i<p;++i){
            scanf("%s",tmp);
            int e = ceil(p/6.0);
            for(int j=0;j<e;++j){
                //cout << tmp[j] << endl;
                tmp[j] = vc[tmp[j]];
                //cout << (int)tmp[j] << endl;
                for(int k=5;k>=0;--k){
                    model[0][i][j*6+k] = tmp[j]&1;
                    tmp[j]>>=1;
                }
            }
        }

        for(int i=0;i<4;++i){
            vmirrorOver(model[i%2],model[(i+1)%2]);
            cts.insert(hashit(model[(i+1)%2]));
            hmirrorOver(model[i%2],model[(i+1)%2]);
            cts.insert(hashit(model[(i+1)%2]));
            cts.insert(hashit(model[i%2]));
            rotate(model[i%2],model[(i+1)%2]);
        }



        for(int i=0;i<h;++i){
            ull& res = vhash[i];
            for(int j=0;j<p;++j){
                res*=B;res+=mat[i][j];
            }
        }

        int ans = 0;
        for(int i=p-1;i<w;++i){
            ull res = 0;
            for(int j=0;j<p;++j){
                res*=B2;
                res+=vhash[j];
            }

            if(cts.count(res)) ++ans;
            for(int j=p;j<h;++j){
                res-=vhash[j-p]*ba2[p-1];
                res *=B2;
                res += vhash[j];
                if(cts.count(res)) ++ans;
            }
            for(int j=0;j<h;++j){
                vhash[j] -= mat[j][i+1-p]*ba[p-1];
                vhash[j] *= B;
                vhash[j] += mat[j][i+1];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

