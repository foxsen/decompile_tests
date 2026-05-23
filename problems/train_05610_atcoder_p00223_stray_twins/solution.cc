//Shuncha's code???

#include "bits/stdc++.h"
 
typedef struct {
    int ax, ay, bx, by, cnt;
} TWIN_t;
 
TWIN_t queue[300000];
int head, tail;
 
void enq(TWIN_t t)
{
    queue[(tail++) % 300000] = t;
}
 
void deq(TWIN_t *t)
{
    *t = queue[(head++) % 300000];
}
 
int main(void)
{
    TWIN_t first, temp;
    int x, y, i, j, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, flag;
    char map[51][51];
    static char v[51][51][51][51];
     
    while (1){
        scanf("%d %d", &x, &y);
         
        if (x + y == 0)
            break;
         
        scanf("%d %d", &first.ax, &first.ay);
        scanf("%d %d", &first.bx, &first.by);
         
        first.ax -= 1;
        first.ay -= 1;
        first.bx -= 1;
        first.by -= 1;
         
        for (i = 0; i < y; i++){

            for (j = 0; j < x; j++)
                scanf("%d", &map[i][j]);
        }

        first.cnt = temp.cnt = 0;
        head = tail = 0;
        memset(v, 0, sizeof(v));
        v[first.ay][first.ax][first.by][first.bx] = 1;
        enq(first);
		flag = 0;

        while (head != tail){
            deq(&temp);
             
            if (temp.cnt >= 100)
                break;
             
            if (temp.ax == temp.bx && temp.ay == temp.by){
                printf("%d\n", temp.cnt);
                flag = 1;
                break;
            }
             
            for (i = 0; i < 4; i++){
                first = temp;

                if (0 <= first.ax + dx[i] && first.ax + dx[i] < x && 0 <= first.ay + dy[i] && first.ay + dy[i] < y && map[first.ay + dy[i]][first.ax + dx[i]] == 0){
                    first.ax += dx[i];
                    first.ay += dy[i];
                }

                if (0 <= first.bx - dx[i] && first.bx - dx[i] < x && 0 <= first.by - dy[i] && first.by - dy[i] < y && map[first.by - dy[i]][first.bx - dx[i]] == 0){
                    first.bx -= dx[i];
                    first.by -= dy[i];
                }

                first.cnt++;

                if (!v[first.ay][first.ax][first.by][first.bx]){
                    v[first.ay][first.ax][first.by][first.bx] = 1;
                    enq(first);
                }
            }
        }
        if (!flag)
            printf("NA\n");
    }
     
    return 0;
}