#include <bits/stdc++.h>

using namespace std;
const long long mod=1e9+7;
const long long mxn=2e5+5;
long long fac[mxn+5],ifac[mxn+5];
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
  if(k<0||k>n||n<0) return 0;
  return fac[n]*ifac[k]%m*ifac[n-k]%m;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n,a,b; cin>>n>>a>>b;
  precompute();
  long long ans=(bp(2,n,mod)-1-C(n,a,mod)-C(n,b,mod))%mod;
  if(ans<0) ans+=mod;
  cout<<ans;
  return 0;
}
