const long long mod=1e9+7;
const int mxn=2000005;

struct Matrix{
  long long a[2][2];
};
Matrix matmul(const Matrix &x, const Matrix &y){
  Matrix ans{};
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      for(int k=0; k<2; k++){
        ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
      }
    }
  }
  return ans;
}
Matrix matpow(Matrix b,long long e){
  Matrix ans{{{1,0},{0,1}}};
  while(e>0){
    if(e&1) ans=matmul(ans,b);
    b=matmul(b,b);
    e>>=1;
  }
  return ans;
}
