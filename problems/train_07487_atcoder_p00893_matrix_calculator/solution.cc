#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef VVI matrix;

ostream& operator << (ostream &os,const matrix &mat) {
  rep(i,(int)mat.size()) {
    rep(j,(int)mat[i].size()) {
      if( j ) os << " ";
      os << mat[i][j];
    } if( i+1 != (int)mat.size() ) os << endl;
  }
  return os;
}



const int MOD = 32768;

matrix identity(int n) {
  matrix A(n,vector<int>(n,0));
  for(int i=0;i<n;i++) A[i][i] = 1;
  return A;
}

matrix multi(const matrix& A,const matrix& B){
  if( (int)A.size() == 1 && (int)A[0].size() == 1 ) {
    matrix C(B.size(),VI(B[0].size()));
    int coef = A[0][0];
    rep(i,(int)B.size()) {
      rep(j,(int)B[0].size()) {
        C[i][j] = B[i][j] * coef;
        C[i][j] %= MOD;
      }
    }
    return C;
  }
  if( (int)B.size() == 1 && (int)B[0].size() == 1 ) {
    matrix C(A.size(),VI(A[0].size()));
    int coef = B[0][0];
    rep(i,(int)A.size()) {
      rep(j,(int)A[0].size()) {
        C[i][j] = A[i][j] * coef;
        C[i][j] %= MOD;
      }
    }
    return C;
  }
  matrix C(A.size(),vector<int>(B[0].size()));
  for(int i=0;i<C.size();++i)
    for(int j=0;j<C[i].size();++j)
      for(int k=0;k<A[i].size();++k) {
        C[i][j] += ( A[i][k] * B[k][j] );
        while( C[i][j] < 0 ) C[i][j] += MOD;
        C[i][j] %= MOD;
      }
  return C;
}

matrix add(const matrix& A,const matrix& B){
  assert( A.size() == B.size() );
  matrix C(A.size(),vector<int>(A[0].size(),0));
  rep(i,(int)A.size()) {
    assert( A[i].size() == B[i].size() );
    rep(j,(int)A[0].size()) {
      C[i][j] = ( A[i][j] + B[i][j] ) % MOD;
      while( C[i][j] < 0 ) C[i][j] += MOD;
      C[i][j] %= MOD;
    }
  }
  return C;
}

matrix sub(const matrix& A,const matrix& B){
  assert( A.size() == B.size() );
  matrix C(A.size(),vector<int>(A[0].size(),0));
  rep(i,(int)A.size()) {
    assert( A[i].size() == B[i].size() );
    rep(j,(int)A[0].size()) {
      C[i][j] = ( A[i][j] - B[i][j] ) % MOD;
      while( C[i][j] < 0 ) C[i][j] += MOD;
      C[i][j] %= MOD;
    }
  }
  return C;
}

matrix neg(const matrix& A) {
  matrix B(A.size(),vector<int>(A[0].size(),0));
  rep(i,(int)A.size()) {
    rep(j,(int)A[i].size()) {
      B[i][j] = -A[i][j];
      while( B[i][j] < 0 ) B[i][j] += MOD;
      B[i][j] %= MOD;
    }
  }
  return B;
}

matrix transpose(const matrix& A) {
  matrix B(A[0].size(),vector<int>(A.size(),0));
  rep(i,(int)A[0].size()) {
    rep(j,(int)A.size()) {
      B[i][j] = A[j][i];
    }
  }
  return B;
}

matrix factor();
matrix term();
matrix expr();
matrix transposed_primary(matrix);
matrix indexed_primary(matrix);
matrix indexed_primary_and_transposed_primary(matrix);

map<char,matrix> buffer;

string context;
int ptr;

matrix row() {
  matrix p = expr();
  while( ptr < (int)context.size() && context[ptr] == ' ' ) {
    ++ptr;
    matrix q = expr();
    assert( p.size() == q.size() );
    rep(i,(int)p.size()) {
      rep(j,(int)q[i].size()) {
        p[i].push_back(q[i][j]);
      }
    }
  }
  return p;
}

matrix row_seq() {
  matrix p = row();
  while( ptr < (int)context.size() && context[ptr] == ';' ) {
    ++ptr;
    matrix q = row();
    rep(i,(int)q.size()) p.push_back(q[i]);
  }
  return p;
}

matrix c_matrix() {
  assert( context[ptr] == '[' );
  ++ptr;
  matrix p = row_seq();
  assert( context[ptr] == ']' );
  ++ptr;
  return p;
}

bool next_is_indexed_primary() {
  assert( ptr < (int)context.size() && context[ptr] == '(' );
  int i=ptr+1,cnt = 1;
  for(;i<(int)context.size();++i){
    if( context[i] == '(' ) ++cnt;
    else if( context[i] == ')' ) --cnt;
    if( cnt == 0 ) {
      ++i;
      break;
    }
  }
  if( context[i] != '(' ) return false;
  ++i,cnt = 1;
  for(;i<(int)context.size();++i) {
    if( context[i] == '(' ) ++cnt;
    else if( context[i] == ')' ) --cnt;
    if( cnt == 0 ) break;
    if( cnt == 1 && context[i] == ',' ) return true;
  }
  return false;
}

bool next_is_indexed_primary2() {
  int i=ptr+1,cnt = 1;
  while( i < (int)context.size() && context[i] != '(' ) ++i;
  if( i >= (int)context.size() ) return false;
  assert( context[i] == '(' );
  ++i,cnt = 1;
  for(;i<(int)context.size();++i) {
    if( context[i] == '(' ) ++cnt;
    else if( context[i] == ')' ) --cnt;
    if( cnt == 0 ) break;
    if( cnt == 1 && context[i] == ',' ) return true;
  }
  return false;
}

bool is_indexed_primary() {
  assert( ptr < (int)context.size() && context[ptr] == '(' );
  int i=ptr+1,cnt = 1;
  for(;i<(int)context.size();++i) {
    if( context[i] == '(' ) ++cnt;
    else if( context[i] == ')' ) --cnt;
    if( cnt == 0 ) break;
    if( cnt == 1 && context[i] == ',' ) return true;
  }
  return false;
}

matrix primary() {
  if( context[ptr] == '(' && !next_is_indexed_primary() ) {
    ++ptr;
    matrix p = expr();
    assert( ptr < (int)context.size() );
    assert( context[ptr] == ')' );
    ++ptr;
    return indexed_primary_and_transposed_primary(p);
  } else if( context[ptr] == '(' ) {
    ++ptr;
    matrix p = expr();
    assert( context[ptr] == ')' );
    ++ptr;
    return indexed_primary_and_transposed_primary(indexed_primary(p));
  }

  if( context[ptr] == '[' ) {
    return indexed_primary_and_transposed_primary(c_matrix());
  }
  if( 'A' <= context[ptr] && context[ptr] <= 'Z' ) {
    char var = context[ptr++];
    assert( buffer.count(var) );
    return indexed_primary_and_transposed_primary(buffer[var]);
  }
  if( '0' <= context[ptr] && context[ptr] <= '9' ) {
    int v = 0;
    while( ptr < (int)context.size() && '0' <= context[ptr] && context[ptr] <= '9' ) {
      v *= 10;
      v += ( context[ptr++] - '0' );
    }
    return indexed_primary_and_transposed_primary(matrix(1,vector<int>(1,v)));
  }
  assert(false);
}

matrix indexed_primary_and_transposed_primary(matrix p) {
  while( ptr < (int)context.size() && ( context[ptr] == '\'' || ( context[ptr] == '(' && is_indexed_primary() ) ) ) {
    char opr = context[ptr];
    if( opr == '\'' ) {
      p = transposed_primary(p);
    } else {
      p = indexed_primary(p);
    }
  }
  return p;
}

matrix indexed_primary(matrix p) {
  if( ptr < (int)context.size() && context[ptr] == '(' ) {
    if( is_indexed_primary() ) {
      ++ptr;
      matrix k = expr();
      assert( ptr < (int)context.size() && context[ptr] == ',' );
      ++ptr;
      matrix l = expr();
      assert( ptr < (int)context.size() && context[ptr] == ')' );
      ++ptr;
      assert( (int)k.size() == 1 );
      assert( (int)l.size() == 1 );
      matrix np = matrix((int)k[0].size(),VI((int)l[0].size()));
      rep(i,(int)k[0].size()) {
        int y = k[0][i]-1;
        rep(j,(int)l[0].size()) {
          int x = l[0][j]-1;
          np[i][j] = p[y][x];
        }
      }
      p = np;
    }
  }
  return p;
}

matrix transposed_primary(matrix p) {
  if( ptr < (int)context.size() && context[ptr] == '\'' ) {
    int cnt = 0;
    while( ptr < (int)context.size() && context[ptr] == '\'' ) {
      ++ptr, ++cnt;
    }
    if( cnt & 1 ) {
      p = transpose(p);
    }
  }
  return p;
}

matrix factor() {
  assert( ptr < (int)context.size() );
  if( context[ptr] == '-' ) {
    int cnt = 0;
    while( context[ptr] == '-' ) {
      ++cnt, ++ptr;
    }
    matrix p = factor();
    if( cnt & 1 ) {
      p = neg(p);
    }
    return p;
  }
  return primary();
}

matrix term() {
  matrix p = factor();
  while( ptr < (int)context.size() && context[ptr] == '*' ) {
    ++ptr;
    matrix q = factor();
    p = multi(p,q);
  }
  return p;
}

matrix expr(){
  matrix p = term();
  while( ptr < (int)context.size() && ( context[ptr] == '+' || context[ptr] == '-' ) ) {
    char opr = context[ptr++];
    matrix q = term();
    if( opr == '+' ) {
      p = add(p,q);
    } else if( opr == '-' ) {
      p = sub(p,q);
    }
  }
  return p;
}

void assignment() {
  assert( 0 <= ptr && ptr < (int)context.size() );
  char var = context[ptr++];
  assert( 0 <= ptr && ptr < (int)context.size() );
  assert( context[ptr] == '=' );
  ++ptr;
  matrix mat = expr();
  assert( 0 <= ptr && ptr < (int)context.size() );
  assert( context[ptr] == '.' );
  ++ptr;
  buffer[var] = mat;
  cout << mat << endl;
}


void exec() {
  ptr = 0;
  assignment();
}

int main() {
  int n;
  while( cin >> n, n ) {
    cin.ignore();
    buffer.clear();
    rep(_,n) {
      getline(cin,context);
      exec();
    }
    puts("-----");
  }
  return 0;
}