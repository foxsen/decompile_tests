/*
  si = ai ai+1 ... aN-1 (テ・ツ渉ウティツセツコテ」ツ?ッ10テゥツ?イテヲツ閉ーテ」ツ?ィテ」ツ?療」ツ?ヲテ」ツ?ソテ」ツつ?
  テ」ツ?ィテ」ツ?凖」ツつ凝」ツ?Ｊ < j テ」ツ?ョテ」ツ?ィテ」ツ?催」ツ??
  si - sj = ai ai+1 .. aj-2 aj-1 * 10^k

  (i)Q != 2, 5テ」ツ?ョテ」ツ?ィテ」ツ??
  10^kテ」ツ?ィQテ」ツ?ッテ、ツコツ津」ツ??」ツ?ォテァツエツ?」ツ?ェテ」ツ?ョテ」ツ?ァ,
  si - sj テ」ツ?ッQテ」ツ?ョテ・ツ?催ヲツ閉ー
  テ「ツ??ai ai+1 .. aj-2 aj-1 * 10^k テ」ツ?ッQテ」ツ?ョテ・ツ?催ヲツ閉ー
  テ「ツ??ai ai+1 .. aj-2 aj-1 テ」ツ?ッQテ」ツ?ョテ・ツ?催ヲツ閉ー
  テ」ツ?セテ」ツ?淌」ツ??
  si - sj テ」ツ?ッQテ」ツ?ョテ・ツ?催ヲツ閉ー
  テ「ツ??si - sj テ「ツ可。 0 (mod Q)
  テ「ツ??si テ「ツ可。 sj (mod Q)
  テ」ツつ暗」ツ?」テ」ツ?ヲテ」ツ??
  si テ「ツ可。 sj (mod Q)
  テ「ツ??ai ai+1 .. aj-2 aj-1 テ」ツ?ッQテ」ツ?ョテ・ツ?催ヲツ閉ー

  テ」ツ?ェテ」ツ?ョテ」ツ?ァテ」ツ?《i テ「ツ可。 sj (mod Q)テ」ツ?ィテ」ツ?ェテ」ツつ凝」ツつ暗」ツ??」ツ?ェsi,sjテ」ツつ津ヲツ閉ーテ」ツ?暗」ツつ凝」ツ??

  (ii)Q = 2 or 5テ」ツ?ョテ」ツ?ィテ」ツ??
  テ」ツ?禿」ツ?ョテ・ツ?エテ・ツ青?i)テ」ツ?ョテヲツ鳴ケテヲツウツ陛」ツ??」ツ?ィ10^kテ」ツ?ィQテ」ツ?古、ツコツ津」ツ??」ツ?ォテァツエツ?」ツ?ァテ」ツ?ッテ」ツ?ェテ」ツ??」ツ?ョテ」ツ?ァテ」ツ??」ツ?セテ」ツ?湘ヲツ閉ーテ」ツ?暗」ツつ嘉」ツつ古」ツ?ェテ」ツ??」ツ??
  テ」ツ?ェテ」ツ?ョテ」ツ?ァテ、ツクツ?」ツ?ョテ、ツスツ催」ツ?ョテヲツ閉ーテ・ツュツ療」ツつ津」ツ?ソテ」ツ?ヲテヲツ閉ーテ」ツ?暗」ツつ凝」ツ??
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long lli;

const int MAXN = 100005;

lli N, S, W, Q;
lli a[MAXN];

void generate() {
  int g = S;
  for(int i=0; i<N; i++) {
    a[i] = (g/7) % 10;
    if( g%2 == 0 ) { g = (g/2); }
    else           { g = (g/2) ^ W; }
  }
}

lli solve25() {
  lli res = 0;
  for(lli i = 0, c = 0; i < N; ++i) {
    c += (a[i] != 0);
    if(a[i]%Q == 0) {
      res += c;
    }
  }
  return res;
}

lli solve() {
  lli res = 0;
  map<lli,lli> m;
  ++m[0];
  for(lli i = N-1, s = 0, t = 1; i >= 0; --i, t = t*10%Q) {
    s = (s + t*a[i]) % Q;
    if(a[i]) res += m[s];
    ++m[s];
  }
  return res;  
}

int main() {
  while(cin >> N >> S >> W >> Q && (N|S|W|Q)) {
    generate();
    if(Q == 2 || Q == 5) {
      cout << solve25() << endl;
    } else {
      cout << solve() << endl;
    }
  }
  return 0;
}