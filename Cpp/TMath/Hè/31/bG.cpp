#include <bits/stdc++.h>

using namespace std;

long long mod;
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
long long inv(long long b, long long m=mod){
  return bp(b,m-2,m);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,n; cin>>a>>n>>mod;
  // 3^0 3^1.. 3^n
  long long ans;
  if(a%mod==1){
    ans=(n+1)%mod;
  }
  else{
    ans=bp(a,n+1,mod)-1;
    ans%=mod;
    ans=ans*inv(a-1,mod)%mod;
  }
  cout<<ans;
}
