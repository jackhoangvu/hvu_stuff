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
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long q; cin>>q;
  while(q--){
    int n,k; cin>>n>>k;
    cout<<pfo(n,k)<<"\n";
  }
  return 0;
}
