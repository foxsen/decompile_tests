#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main(){
    int n;
    string str = "ai1333";
    scanf("%d", &n);
    n/=100;
    for (int i = 0; i < n; i++) str+='3';
    printf("%s\n", str.c_str());
    return 0;
}

