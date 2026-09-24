#include <bits/stdc++.h>

using namespace std;
const int mxn=10005;
const int mod=1e9+7;
map<int,int> ca,cb;
void pt(long long x,map<int,int>& c){
  for(int i=2; i*i<=x; i++){
    while(x%i==0){c[i]++; x/=i;}
  }
  if(x>1) c[x]++;
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
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n,m; cin>>n>>m;
  for (int i=0; i<n; i++){
    long long a; cin>>a; pt(a,ca);
  }
  for (int i=0; i<m; i++){
    long long b; cin>>b; pt(b,cb);
  }
  long long ans=1;
  for(auto [b,e]:cb){
    ca[b]=max(ca[b],e);
  }
  for(auto [b,e]:ca){
    ans=(ans*bp(b,e))%mod;
  }
  cout<<ans<<"\n";
  return 0;
}
