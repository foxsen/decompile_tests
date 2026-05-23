#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef pair<P,P> Edge;
typedef long long ll;

const double PI=4*atan(1.0);
const int MAX_SIZE = 10000;

//#define RED_FILE

#ifdef RED_FILE
ifstream ifs("input.txt");
ofstream ofs("output.txt");
#define cin ifs
#define cout ofs
#endif


// àÏ
double dot(P a, P b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
// OÏ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
// _cª¼üabãÉ é©È¢©
int is_point_on_line(P a, P b, P c) {
  return EQ( cross(b-a, c-a), 0.0 );
}
// 2¼üÌ¼s»è
int is_orthogonal(P a1, P a2, P b1, P b2) {
  return EQ( dot(a1-a2, b1-b2), 0.0 );
}
// 2¼üÌ½s»è
int is_parallel(P a1, P a2, P b1, P b2) {
  return EQ( cross(a1-a2, b1-b2), 0.0 );
}
// _a,bðÊé¼üÆ_cÌÔÌ£
double distance_l_p(P a, P b, P c) {
  return abs(cross(b-a, c-a)) / abs(b-a);
}
// _a,bð[_Æ·éüªÆ_cÆÌ£
double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}
// a1,a2ð[_Æ·éüªÆb1,b2ð[_Æ·éüªÌð·»è
int is_intersected_ls(P a1, P a2, P b1, P b2) {
    // üªª½sÈêÍdÈÁÄ¢È¢±ÆÉ·é
    if(abs(cross(a2-a1,b2-b1)) < EPS){
        return 0;
    }
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}
// a1,a2ð[_Æ·éüªÆb1,b2ð[_Æ·éüªÌð_vZ
P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}
// a1,a2ðÊé¼üÆb1,b2ðÊé¼üÌð·»è
int is_intersected_l(P a1, P a2, P b1, P b2) {
  return !EQ( cross(a1-a2, b1-b2), 0.0 );
}
// a1,a2ðÊé¼üÆb1,b2ðÊé¼üÌð_vZ
P intersection_l(P a1, P a2, P b1, P b2) {
  P a = a2 - a1; P b = b2 - b1;
  return a1 + a * cross(b, b1-a1) / cross(b, a);
}
// 2xNgÔÌpx
// a©çbÖ¶üèÅ½x©(0->2*PI)
double diffAngle(P a,P b){
    double angle=atan2(cross(a,b),dot(a,b));
    if(angle<0)
        return 2*PI+angle;
    return angle;
}


int n;
int sy,sx;
int gy,gx;
const int INF=1000000000;
double d[1001][1001];
int prv[1001][1001];


int main(){

	while(cin>>n&&n!=0){
		vector<pair<int,int> > ps;
		for(int i = 0; i < 1001; i++){
			for(int j = 0; j < 1001; j++){
				if(i==j)d[i][j]=0;
				else d[i][j]=INF;
				prv[i][j]=INF;
			}
		}

		vector<Edge> es;
		cin>>sx>>sy;
		cin>>gx>>gy;
		// ¸_Ìo»ñð²¸
		map<pair<int,int>,int > m;
		for(int i = 0; i < n; i++){
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			m[make_pair(y1,x1)]++;
			m[make_pair(y2,x2)]++;
			es.push_back(make_pair(P(x1,y1),P(x2,y2)));
		}
		// roadÆsignÅª¯é
		vector<Edge> roads;
		vector<Edge> signs;

		int nodeNum=0;
		map<pair<int,int>,int> nodes;
		for(int i = 0; i < n; i++){
			P p1=es[i].first;
			P p2=es[i].second;

			//  é_ªÇÌüªÆàNXµÈ¢©Ç¤©ð`FbN
			bool p1ok=true;
			bool p2ok=true;
			for(int j = 0; j < n; j++){
				if(i==j)continue;
				if(EQ(distance_ls_p(es[j].first,es[j].second,p1),0))
					p1ok=false;
				if(EQ(distance_ls_p(es[j].first,es[j].second,p2),0))
					p2ok=false;
			}
			// sign
			if(p1ok){
				// open nodeðãëÉµÄ¨­
				swap(es[i].first,es[i].second);
				signs.push_back(es[i]);
			}
			// sign
			else if(p2ok)
				signs.push_back(es[i]);
			// road
			else{
				pair<int,int> p=make_pair((int)(p1.imag()+EPS),(int)(p1.real()+EPS));
				pair<int,int> pp=make_pair((int)(p2.imag()+EPS),(int)(p2.real()+EPS));
				// Ü¾o»µÄ¢È¢¸_
				if(nodes.find(p)==nodes.end()){
					ps.push_back(p);
					nodes[p]=nodeNum++;
				}
				if(nodes.find(pp)==nodes.end()){
					ps.push_back(pp);
					nodes[pp]=nodeNum++;
				}
				roads.push_back(es[i]);
			}
		}
		vector<Edge> roads2;
		// roadÌð·_Åroadðª·é
		for(int i = 0; i < roads.size(); i++){
			// ð_Æ[_ðÛ
			vector<pair<int,int> > tmp;
			// [_ðÛ
			tmp.push_back(make_pair((int)(roads[i].first.imag()+EPS),(int)(EPS+roads[i].first.real())));
			tmp.push_back(make_pair((int)(roads[i].second.imag()+EPS),(int)(EPS+roads[i].second.real())));
			// roadÉð··éð_ð·×ÄßÄ¨¢ÄA·×ÄÌð_ÌgÝí¹ÌÆ±ëÉ¹ðÍé
			for(int j = 0; j < roads.size(); j++){
				if(i==j)continue;
				// ð_ðtmpÉÇÁ
				if(!EQV(roads[j].first,roads[i].first)&&!EQV(roads[j].first,roads[i].second)&&EQ(distance_ls_p(roads[i].first,roads[i].second,roads[j].first),0))
					tmp.push_back(make_pair((int)(roads[j].first.imag()+EPS),(int)(roads[j].first.real()+EPS)));
				if(!EQV(roads[j].second,roads[i].first)&&!EQV(roads[j].second,roads[i].second)&&EQ(distance_ls_p(roads[i].first,roads[i].second,roads[j].second),0))
					tmp.push_back(make_pair((int)(roads[j].second.imag()+EPS),(int)(roads[j].second.real()+EPS)));
			}
			// _ð\[g
			sort(tmp.begin(),tmp.end());
			// \[gµ½ÔÉ¹ðªµÄ¢­
			pair<int,int> prv=tmp[0];
			for(int j = 1; j < tmp.size(); j++){
				roads2.push_back(make_pair(P(prv.second,prv.first),P(tmp[j].second,tmp[j].first)));
				prv=tmp[j];
			}
		}
		roads=roads2;
		// ¼ûüÉÓð£é
		for(int i = 0; i < roads2.size(); i++){
			pair<int,int> p=make_pair(roads2[i].first.imag(),roads2[i].first.real());
			pair<int,int> pp=make_pair(roads2[i].second.imag(),roads2[i].second.real());
			d[nodes[p]][nodes[pp]]=abs(roads2[i].first-roads2[i].second);
			prv[nodes[p]][nodes[pp]]=nodes[p];
			d[nodes[pp]][nodes[p]]=abs(roads2[i].first-roads2[i].second);
			prv[nodes[pp]][nodes[p]]=nodes[pp];
		}
		for(int i = 0; i < signs.size(); i++){
			for(int j = 0; j < roads.size(); j++){
				P p=signs[i].first;
				if(EQ(distance_ls_p(roads[j].first,roads[j].second,p),0)){
					P cp=p;
					P rp1=roads[j].first;
					double ag=diffAngle(rp1-cp,signs[i].second-cp);
					if(ag>=PI)
						ag=2*PI-ag;
					pair<int,int> p1=make_pair((int)(roads[j].first.imag()+EPS),(int)(roads[j].first.real()+EPS));
					pair<int,int> p2=make_pair((int)(roads[j].second.imag()+EPS),(int)(roads[j].second.real()+EPS));
					int node1=nodes[p1];
					int node2=nodes[p2];
					if(EQ(ag,PI/2)){
						d[node1][node2]=INF;
						d[node2][node1]=INF;
						prv[node1][node2]=INF;
						prv[node2][node1]=INF;
					}
					else{
						int from=node2;
						int to=node1;
						if(ag<PI/2){
							d[from][to]=INF;
							prv[from][to]=INF;
						}
						else{
							d[to][from]=INF;
							prv[to][from]=INF;
						}
					}
				}
			}
		}
		int V=nodeNum;
		// wfÅÅZ£ðvZ
	    int s=nodes[make_pair(sy,sx)];
	    int g=nodes[make_pair(gy,gx)];
	    for(int i = 0; i < V; i++){
	        for(int j = 0; j < V; j++){
	            for(int k = 0; k < V; k++){
	                if(d[j][k]>d[j][i]+d[i][k]){
	                    int cp=k;
	                    // XV
	                    while(1){
	                    	prv[j][cp]=prv[i][cp];
	                        cp=prv[i][cp];
	                        if(cp==i)break;
	                    }
	                    d[j][k]=d[j][i]+d[i][k];
	                }
	            }
	        }
	    }
	    if(EQ(d[s][g],INF)){
	    	cout<<-1<<endl;
	    	continue;
	    }
	    else{
            vector<int> v;
            int cp=g;
            while(1){
            	v.push_back(cp);
                if(cp==s)
                    break;
                cp=prv[s][cp];
            }
            for(int j = v.size()-1; j >= 0; j--)
            	cout<<ps[v[j]].second<<" "<<ps[v[j]].first<<endl;
            cout<<0<<endl;
	    }
	}

	return 0;
}