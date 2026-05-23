#include <cstdio>
#include <algorithm>

using namespace std;


static int N,M;

static struct {
    int count;
    int weight;
} counts[1000];

static int max_weight=0,min_weight=100;


int main(){
    scanf("%d%d",&N,&M);

    for(int i=0;i<N;i++) scanf("%d",&counts[i].weight);

    bool all_equals;
    int weight=0;
    int i=0;
    do{
        max_weight=0;
        min_weight=100;
        all_equals=true;
        for (int j=0;j<M;j++){
            counts[i].count++;

            max_weight=max(max_weight,counts[i].weight);
            min_weight=min(min_weight,counts[i].weight);
            i=(i+1)%N;
        }

        weight+=max_weight-min_weight;

        for (int j=0;j<N-1;j++) if (counts[j].count!=counts[j+1].count) {all_equals=false; break;}
    }while(!all_equals);

    printf("%d\n",weight);

    return 0;
}
