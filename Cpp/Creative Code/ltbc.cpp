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
long long rec(long long b,long long e){
  if(e==0) return 1;
  long long m=rec(b,e/2);
  long long ans=bp(m,2);
  if(e&1) ans=ans*b%mod;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    int b,e; cin>>b>>e;
    cout<<rec(b,e)<<"\n";
  }
  return 0;
}
