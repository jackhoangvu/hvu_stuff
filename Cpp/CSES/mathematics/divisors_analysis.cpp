#include <bits/stdc++.h>

using namespace std;
const long long mod=1e9+7,phi=1e9+6;
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
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long pd=1,cnt=1;
  long long num=1,sum=1;
  vector<pair<long long,long long>> pt;
  for (int i=0; i<n; i++){
    long long p,k; cin>>p>>k;
    pt.push_back({p,k});
    num=num*(k+1)%mod;
    long long tt=(bp(p,k+1)-1+mod)%mod;
    tt=tt*inv(p-1)%mod;
    sum=(sum*tt)%mod;
  }
  for (int i=0; i<n; i++){
    long long p=pt[i].first;
    long long k=pt[i].second;
    long long s=(k*(k+1)/2)%phi;
    long long e=(s*cnt)%phi;
    long long old=bp(pd,k+1);
    long long ne=bp(p,e);
    pd=(old*ne)%mod;
    cnt=cnt*(k+1)%phi;
  }
  cout<<num<<" "<<sum<<" "<<pd;
  // cout<<num;
  // cout<<sum;

  return 0;
}
