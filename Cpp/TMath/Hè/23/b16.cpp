#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
long long pfo(int n,int k){
  if(k<0||k>n){ return 0;}
  if(k==0||k==n) return 1;
  if(k>n/2){k=n-k;}
  long long ans=1;
  for (int i=1; i<=k; i++){
    ans=(ans*(n-i+1)/i)%mod;
  }
  return ans;
}
long long solve(int n,int k,int m){
  int nmi=k*m;
  if (n<nmi) return 0;
  int np=n-nmi;
  return pfo(np+k-1,k-1);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    int n,k; cin>>n>>k;
    cout<<solve(n,k,1)<<"\n";
  }
  return 0;
}
