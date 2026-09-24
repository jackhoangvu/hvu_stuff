#include <bits/stdc++.h>

using namespace std;
long long n,k,d,p;
const int mxn=30;
int mod=1e9+7;
long long fac[mxn],ifac[mxn];
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
long long C(long long n,long long k,long long m=mod){
  if (k<0||n<0||k>n) return 0;
  return fac[n]*ifac[k]%m*ifac[n-k]%m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("CAU5.INP", "r", stdin);
  freopen("CAU5.OUT", "w", stdout);
  cin>>n>>k>>d>>p;
  mod=p;
  precompute();
  long long ans=C(n-(k-1)*(d-1),k,p);
  cout<<ans<<"\n";
  return 0;
}
