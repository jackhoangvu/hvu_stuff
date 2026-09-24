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
long long solve(int a,int b,int c, int k){
  int sum=pfo(a+b+c,k);
  return sum-(pfo(b+c,k)+pfo(a+c,k)+pfo(a+b,k))+pfo(a,k)+pfo(b,k)+pfo(c,k);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a,b,c,k; cin>>a>>b>>c>>k;
  if(k<0||a<0||b<0||c<0) cout<<0<<"\n";
  else if (k<3||k>a+b+c) cout<<0<<"\n";
  else cout<<solve(a,b,c,k)<<"\n";
  return 0;
}
