#include<bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long k;
  cin>>n>>k;
  vector<long long>a(n+1),b(n+1);
  for(int i=1; i<=n; i++) cin>>a[i];
  for(int i=1; i<n; i++) cin>>b[i];
  vector<long long> dp(n+1,0LL);
  dp[0]=0;
  dp[1]=a[1]+k;
  vector<long long> c(n+1,0LL);
  c[0]=1;
  c[1]=1;
  for(int i=2; i<=n; i++){
    long long v=dp[i-1]+a[i]+k;
    long long x=dp[i-2]+b[i-1]+k;
    if(v<x){
      dp[i]=v;
      c[i]=c[i-1]%mod;
    }
    else if(x<v){
      dp[i]=x;
      c[i]=c[i-2]%mod;
    }
    else{
      dp[i]=v;
      c[i]=(c[i-1]+c[i-2])%mod;
    }
  }
  cout<<dp[n]<<" "<<c[n]%mod;
  return 0;
}
