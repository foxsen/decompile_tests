#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Button {
  int sx, sy, ex, ey;
  string to;
  bool isHit(int x, int y) {
    return ( sx <= x && x <= ex &&
	     sy <= y && y <= ey );
  }
};

struct Page {
  vector<Button> buttons;
  string click(int x, int y) {
    for(int i = 0; i < buttons.size(); ++i) {
      if(buttons[i].isHit(x,y)) return buttons[i].to;
    }
    return "";
  }
};

int W, H;
map<string, Page> Pages;
vector<string> Buff;
int pi, br;

int main() {
  int n, m;
  string np;
  while(cin >> n && n) {
    Pages.clear();
    np = "";
    cin >> W >> H;
    while(n--) {
      Page p;
      string name;
      int b;
      cin >> name >> b;
      if(np == "") np = name;
      while(b--) {
	Button bn;
	cin >> bn.sx >> bn.sy >> bn.ex >> bn.ey >> bn.to;
	p.buttons.push_back(bn);
      }
      Pages[name] = p;
    }
    cin >> m;
    Buff.resize(m*2);
    Buff[0] = np;
    pi = 0;
    br = 1;
    while(m--) {
      string op;
      cin >> op;
      if(op == "click") {
	int x, y;
	cin >> x >> y;
	string to = Pages[Buff[pi]].click(x,y);
	if(to != "" && Pages.count(to)) {
	  ++pi;
	  Buff[pi] = to;
	  br = pi+1;
	}
      } else if(op == "back") {
	if(pi != 0) {
	  --pi;
	}
      } else if(op == "forward") {
	if(pi+1 != br) {
	  ++pi;
	}
      } else if(op == "show") {
	cout << Buff[pi] << endl;
      }
    }
  }
  return 0;
}