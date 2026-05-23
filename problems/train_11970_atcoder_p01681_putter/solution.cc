#include <bits/stdc++.h>
using namespace std;

typedef complex<double> P;
typedef pair<P,P> L;

const double EPS = 1e-8;
const double EPS6 = 1e-6;

bool equal(double a, double b){
  return fabs(a-b) < EPS;
}

double dot(P a, P b){ return real(conj(a)*b); }

P rotate(P p, double rad){
  double x = real(p) * cos(rad) - imag(p) * sin(rad);
  double y = real(p) * sin(rad) + imag(p) * cos(rad);
  return P(x,y);
}

P proj(P p, L l){
    return l.first + dot(p - l.first, l.second - l.first) / norm(l.second - l.first) * (l.second - l.first);
}

P reflect(P p, L l){
  return p + (proj(p,l) - p) * 2.0;
}

int n;
vector<P> in_v;

void rotate_convex(vector<P> &v, double rad){
  for(int i=0;i<n;i++){
    v[i] = rotate(v[i], rad);
    if(equal(real(v[i]), 0.0)) v[i] = P(0, imag(v[i]));
    if(equal(imag(v[i]), 0.0)) v[i] = P(real(v[i]), 0);
  }
}

void reflect_convex(vector<P> &v, L l){
  for(int i=0;i<n;i++){
    v[i] = reflect(v[i], l);
    if(equal(real(v[i]), 0.0)) v[i] = P(0, imag(v[i]));
    if(equal(imag(v[i]), 0.0)) v[i] = P(real(v[i]), 0);
  }
}

pair<double, double> calc_next(vector<P> &v, int pos){
  L l = L(v[pos], v[(pos+1)%n]);
  P p = (l.second - l.first) / abs(l.second - l.first) * EPS6; // ?????????1e-6???????????????
  double ar_be = max(arg(l.first+p), arg(l.second-p));
  double ar_en = min(arg(l.first+p), arg(l.second-p));

  //printf("ar_max = %.5f, ar_min = %.5f\n", ar_max*180.0/M_PI, ar_min*180.0/M_PI);

  // [-PI ~ PI] -> [0 ~ 2PI]
  if(equal(ar_be, 0.0)) ar_be = 0;
  else if(ar_be <= -EPS) ar_be += 2.0 * M_PI;
  if(equal(ar_en, 0.0)) ar_en = 0;
  else if(ar_en <= -EPS) ar_en += 2.0 * M_PI;

  if(ar_en < ar_be) swap(ar_be, ar_en);

  // 180?????\????????¨ar_be??¨ar_en??????????????£?????????
  if(ar_en - ar_be >= M_PI) {
    swap(ar_be, ar_en);
    if(ar_be >= M_PI) ar_be = 0; // ar_be <= 0 ([-PI ~ PI]?????´???)
  }

  return make_pair(ar_be, ar_en);
}

int dfs(int cnt, double begin, double end, vector<P> v, set<int> &visited){
  int res = 0;
  pair<double, double> next;
  double n_be, n_en;
  vector<P> n_v;

  if(cnt == n) {
    return 1;
  }

  for(int i=0;i<n;i++){
    if(visited.count(i)) continue;
    n_v = v;
    reflect_convex(n_v, L(v[i], v[(i+1)%n])); 
    next = calc_next(n_v, i);
    n_be = max(begin, next.first);
    n_en = min(end, next.second);
    if(n_be > n_en - EPS) {
      continue;
    }
    visited.insert(i);
    res += dfs(cnt+1, n_be, n_en, n_v, visited);
    visited.erase(i);
  }

  return res;
}

int solve(){
  int res = 0;  

  for(int i=0;i<n;i++){
    set<int> st;
    vector<P> v = in_v;
    st.insert(i);
    rotate_convex(v, -arg(v[i]));
    reflect_convex(v, L(v[i], v[(i+1)%n]));
    res += dfs(1, arg(v[i]), arg(v[(i+1)%n]), v, st);
  }

  return res;
}

int main(){
  double sx, sy, x, y;
  while(cin >> n && n){
    in_v.clear();
    cin >> sx >> sy;
    for(int i=0;i<n;i++){
      cin >> x >> y;
      in_v.push_back(P(x-sx, y-sy));
    }
    cout << solve() << endl;
  }
}