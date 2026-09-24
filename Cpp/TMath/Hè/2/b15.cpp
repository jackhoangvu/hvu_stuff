#include <bits/stdc++.h>

using namespace std;
const int mxn=10005;
const int mod=1e9+7;
long long ca[mxn],cb[mxn];
void pt(long long x,long long c[]){
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
  long long n,m; cin>>n;
  for (int i=0; i<n; i++){
    long long a; cin>>a; pt(a,ca);
  }
  cin>>m;
  for (int i=0; i<m; i++){
    long long b; cin>>b; pt(b,cb);
  }
  long long ans=1;
  for(int i=2; i<mxn; i++){
    long long e=min(ca[i],cb[i]);
    // cout<<e<<"  ";
    if(e>0) ans=(ans*bp(i,e))%mod;
  }
  cout<<ans<<"\n";
  return 0;
}
