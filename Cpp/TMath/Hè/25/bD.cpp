#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
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
  return bp(b,mod-2);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,n; cin>>a>>n;
  if(a==1){cout<<n+1<<"\n"; return 0;}
  if(n==1){cout<<1+a<<"\n"; return 0;}
  //3^0+3^1...3^n
  //3^(n+1)-1
  //
  long long ans=bp(a,n+1,mod);
  cout<<(ans-1)*inv(a-1,mod)%mod;
  return 0;
}
