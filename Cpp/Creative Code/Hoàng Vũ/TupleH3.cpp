#include <bits/stdc++.h>

using namespace std;
// const int mod=1e9+7;
// const int mxn=2e5+5;
// long long fac[mxn],ifac[mxn];
// long long bp(long long b,long long e,long long m=mod){
//   b%=m;
//   long long ans=1;
//   while(e>0){
//     if(e&1) ans=ans*b%m;
//     b=b*b%m;
//     e>>=1;
//   }
//   return ans;
// }
// void precompute(){
//   fac[0]=1;
//   for(int i=1; i<mxn; i++){
//     fac[i]=fac[i-1]*i%mod;
//   }
//   ifac[mxn-1]=bp(fac[mxn-1],mod-2);
//   for(int i=mxn-2; i>=0; i--){
//     ifac[i]=ifac[i+1]*(i+1)%mod;
//   }
// }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("TupleH3.Inp","r",stdin);
  freopen("TupleH3.Out","w",stdout);
  // precompute();
  int n; cin>>n;
  int e; cin>>e;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int l=0;
  long long ans=0;
  for (int r=0; r<n; r++){
    while(a[r]-a[l]>e) l++;
    long long m=r-l;
    ans+=(m*(m-1)/2);
  }
  cout<<ans;
  return 0;
}
