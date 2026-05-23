#include<iostream>
using namespace std;

const int M = 1000000;
int n;
int sch[400][20];
bool dp[2][M];
int dy[] = {0,-1,0,1,0}, dx[] = {0,0,1,0,-1};
bool table[5][5];
int y,x;

int main(){
  while(cin >> n,n){
    for(int i=0;i<n;i++){
      for(int j=0;j<16;j++)cin >> sch[i][j];
    }

    for(int i=0;i<M;i++)dp[0][i] = false;
    dp[0][4] = !sch[0][5] && !sch[0][6] && !sch[0][9] && !sch[0][10];
    

    for(int i=0;i<n-1;i++){
      int now = i&1, nxt = 1-now;
      for(int j=0;j<M;j++)dp[nxt][j] = false;

      for(int j=0;j<M;j++){
	if(dp[now][j]){
	  for(int ii=0;ii<4;ii++){
	    for(int jj=0;jj<4;jj++){
	      table[ii][jj] = ((i<5)?true:false);
	    }
	  }

	  int tmp = j;
	  for(int z=0;z<6;z++){
	    int pos = tmp%10;
	    y = pos/3; x = pos%3;
	    for(int ii=0;ii<=1;ii++){
	      for(int jj=0;jj<=1;jj++){
		table[y+ii][x+jj] = true;
	      }
	    }
	    tmp/=10;
	  }

	  tmp = j%10;
	  y = tmp/3; x = tmp%3;

	  for(int ii=1;ii<=2;ii++){
	    for(int jj=0;jj<=4;jj++){
	      bool f = true;
	      int ny = y+ii*dy[jj], nx = x+ii*dx[jj];
	      if(ny<0 || nx<0 || ny>=3 || nx>=3)continue;
	      
	      bool piyo[5][5];
	      for(int iii=0;iii<4;iii++){
		for(int jjj=0;jjj<4;jjj++){
		  piyo[iii][jjj] = table[iii][jjj];
		}
	      }

	      for(int iii=0;iii<=1;iii++){
		for(int jjj=0;jjj<=1;jjj++){
		  if(sch[i+1][ (ny+iii)*4+nx+jjj ]){
		    f = false;
		    goto END;
		  }
		  piyo[ny+iii][nx+jjj] = true;
		}
	      }

	      for(int iii=0;iii<4;iii++){
		for(int jjj=0;jjj<4;jjj++){
		  if(!piyo[iii][jjj]){
		    f = false;
		    goto END;
		  }
		}
	      }
	    END:;
	      dp[nxt][(j*10+(ny*3+nx))%M] |= f;
	    }
	  }
	}
      }
    }
    bool ans = false;
    for(int i=0;i<M;i++)ans |= dp[(n-1)&1][i];
    if(ans)cout << "1\n";
    else cout << "0\n";
  }
}

          
	  