#include <cstdio>
#include <string>

using namespace std;

int main(){
    string mark = "SHCD";
    bool card[4][13] = { 0 };
    int n;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i){
        char c;
        int t;
        
        scanf(" %c %d", &c, &t);
        
        card[mark.find(c)][t - 1] = true;
    }
    
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 13; ++j){
            if(!card[i][j]){
                printf("%c %d\n", mark[i], j + 1);
            }
        }
    }
    
    return 0;
}
