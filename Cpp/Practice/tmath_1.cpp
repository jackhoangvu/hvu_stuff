const long long mod=1e9+7;
const int mxn=2000005;
// precompute: fac + inv fac
long long fac[mxn],ifac[mxn];
// binpow: tính b^e mod m
long long bp(long long b,long long e,long long m=mod){
  b %= m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b % m;
    b=b*b % m;
    e>>=1;
  }
  return ans;
}
// nghịch đảo modulo: inv(b)= b^(mod-2) mod mod (lil fermat)
long long inv(long long b, long long m=mod){
  return bp(b,mod-2);
}

void precompute(){
  fac[0]=1;
  for(int i=1; i<mxn; i++){
    fac[i]=fac[i-1]*i%mod;
  }
  ifac[mxn-1]=bp(fac[mxn-1],mod-2);
  for(int i=mxn-2; i>=0; i--){
    ifac[i]=ifac[i+1]*(i+1)%mod;
  }
}
long long bp(long long b, long long e, long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%m;
    b=b*b%mod;
    e>>=1;
  }
  return ans;
}

// chỉnh hợp A(n, k)
long long A(long long n,long long k,long long m=mod){
  if (k<0||n<0||k>n) return 0;
  return fac[n]*ifac[n-k]%m;
}
//tổ hợp C(n, k)
long long C(long long n,long long k,long long m=mod){
  if(k<0||k>n||n<0) return 0;
  return fac[n]*ifac[k]%m*ifac[n-k]%m;
}

// Catalan n-th
long long ctl(long long n){
  return C(2*n,n,mod)*inv(n+1)%mod;
}
struct Matrix{ //nhân ma trận 2*2
  long long a[2][2];
};
// ôn sau
Matrix matmul(const Matrix& x,const Matrix& y){
  Matrix ans{};
  for (int i=0; i<2; i++){
    for (int j=0; j<2; j++){
      for (int k=0; k<2; k++){
        ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j]) % mod;
      }
    }
  }
  return ans;
}

Matrix matpow(Matrix b,long long e){
  Matrix ans{{{1,0},{0,1}}}; //ma trận đơn vị
  while (e>0){
    if(e&1) ans=matmul(ans,b);
    b=matmul(b,b);
    e>>=1;
  }
  return ans;
}
// ----------------------------------------------------------------------------------------------------

long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%m;
    b=b*b%m;
    e>>=1;
  }
  return ans;
}

void precompute(){
  fac[0]=1;
  for(int i=1; i<mxn; i++){
    fac[i]=fac[i-1]*i%mod;
  }
  ifac[mxn-1]=bp(fac[mxn-1],mod-2);
  for(int i=mxn-2; i>=0; i--){
    ifac[i]=ifac[i+1]*(i+1)%mod;
  }
}
long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%mod;
    b=b*b%mod;
    e>>=1;
  }
  return ans;
}
void precompute(){
  fac[0]=1;
  ifac[mxn-1]=bp(fac[mxn-1],mod-2);
  for(int i=1; i<mxn; i++){
    fac[i]=fac[i-1]*i%mod;
  }
  for(int i=mxn-2; i>=0; i--){
    ifac[i]=ifac[i+1]*(i+1)%mod;
  }
}
long long C(long long n,long long k){
  if(k<0||n<0||k>n) return 0;
  return fac[n]*ifac[n-k]%mod;
}
long long A(long long n,long long k,long long m=mod){
  if(k<0||n<0||k>n) return 0;
  return fac[n]*ifac[n-k]%m;
}
long long C(long long n,long long k,long long m=mod){
  if(k<0||n<0||k>n) return 0;
  return fac[n]*ifac[k]%m*ifac[n-k]%m;
}
long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%m;
    b=b*b%m;
    e>>=1;
  }
  return ans;
}
void precompute(){
  fac[0]=1;
  ifac[mxn-1]=bp(fac[mxn-1],mod-2);
  for(int i=1; i<mxn; i++){
    fac[i]=fac[i-1]*i%mod;
  }
  for(int i=mxn-2; i>=0; i--){
    ifac[i]=ifac[i+1]*(i+1)%mod;
  }
}
long long ctl(long long n){
  return C(2*n,n,mod)*inv(n+1)%mod;
}
long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%m;
    b=b*b%m;
    e>>=1;
  }
  return ans;
}
long long C(long long n,long long k,long long m=mod){
  if(k<0||n<0||k>n) return 0;
  return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}
long long A(long long n,long long k,long long m=mod){
  if(k<0||n<0||k>n) return 0;
  return fac[n]*ifac[n-k]%mod;
}
void precompute(){
  fac[0]=1;
  ifac[mxn-1]=bp(fac[mxn-1],mod-2);
  for(int i=1; i<mxn; i++){
    fac[i]=fac[i-1]*i%mod;
  }
  for(int i=mxn-2; i>=0; i--){
    ifac[i]=ifac[i+1]*(i+1)%mod;
  }
}
long long ctl(long long n){
  return C(2*n,n,mod)*inv(n+1)%mod;
}

struct Matrix{
  long long a[2][2];
};
Matrix matmul(const Matrix &x,const Matrix &y){
  Matrix ans{};
  for (int i=0; i<2; i++){
    for (int j=0; j<2; j++){
      for (int k=0; k<2; k++){
        ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j]) % mod;
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

long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*e%m;
    b=b*b%m;
    e>>=1;
  }
  return ans;
}

void precompute(){
  fac[0]=1;
  ifac[mxn-1]=bp(fac[mxn-1],mod-2);
  for (int i=1; i<mxn; i++){
    fac[i]=fac[i-1]*i%mod;
  }
  for(int i=mxn-2; i>=0; i--){
    ifac[i]=ifac[i+1]*(i+1)%mod;
  }
}
long long bp(long long b,long long e,long long m=mod){
  b%=m;
  long long ans=1;
  while(e>0){
    if(e&1) ans=ans*b%m;
    b=b*b%m;
    e>>=1;
  }
  return ans;
}
void precompute(){
  fac[0]=1;
  ifac[mxn-1]=bp(fac[mxn-1],mod-2);
  for(int i=1; i<mxn; i++){
    fac[i]=fac[i-1]*i%mod;
  }
  for(int i=mxn-2; i>=0; i--){
    ifac[i]=ifac[i+1]*(i+1)%mod;
  }
}
Matrix matmul(const Matrix &x, const Matrix &y){
  Matrix ans{};
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      for(int k=0; k<2; k++){
        ans.a[i][j]=(ans.a[i][j]+x.a[i][k]+y.a[k][j])%mod;
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
