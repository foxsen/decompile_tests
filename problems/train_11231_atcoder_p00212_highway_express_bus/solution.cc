#include<iostream>
#include<algorithm>

const int MAX = (1<<30);

using namespace std;

int minnode;

int main(){
  int c, city, bus, from, to;
  while(cin >> c >> city >> bus >> from >> to && c && city && bus && from && to){

    int price[city+1][city+1];

    for(int i = 0; i < city+1; i++){
      for(int j = 0; j < city+1; j++){	
	price[i][j] = 0;	
      }
    }

    for(int i = 0; i < bus; i++){
      int start, end, pri;
      cin >> start >> end >> pri;

      price[start][end] = pri;
      price[end][start] = pri;
    }

    int node[city+1][c+1];
    int visited[city+1][c+1];

    for(int i = 0; i < city+1; i++){
      for(int j = 0; j < c+1; j++){	
	node[i][j] = MAX;
	visited[i][j] = 0;
      }
    }

    minnode = from;
    int ticket = c;
    node[from][c] = 0;
    int nownode = MAX;
    int minpos, mintic;
    
    while(1){
      for(int i = 1; i < city+1; i++){
	for(int j = 0; j < c+1; j++){
	  if(visited[i][j]) continue;
	  if(node[i][j] < nownode){
	    nownode = node[i][j];
	    minpos = i;
	    mintic = j;
	  }
	}
      }
      visited[minpos][mintic] = 1;
      if(nownode == MAX) break;
      
      nownode = MAX;
      
      for(int i = 1; i < city+1; i++){
	if(price[minpos][i]){
	  node[i][mintic] = min(node[i][mintic],node[minpos][mintic]+price[minpos][i]);
	  if(mintic){
	    node[i][mintic-1] = min(node[i][mintic-1],node[minpos][mintic] + price[minpos][i]/2);
	  }
	}
      }
    }

    for(int i = 1; i <= ticket; i++){
      if(node[to][0] > node[to][i]) node[to][0] = node[to][i];
    }
    cout << node[to][0] << endl;
  }
  return 0;
}