#include <bits/stdc++.h>

using namespace std;
long long fac[1000005];
const int mod=1e9+7;
void precompute(){
  fac[0]=1,fac[1]=1,fac[2]=2;
  for(int i=1; i<=1000003; i++){
    fac[i]=(fac[i-1]*i)%mod;
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  long long sum=0;
  precompute();
  for(int i=1; i<=n; i++){
    sum=(sum+fac[i])%mod;
  }
  cout<<(sum%mod)<<"\n";
  return 0;
}
