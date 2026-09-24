#include<bits/stdc++.h>
using namespace std;
const long long INF=1LL<<60;
const int mod=1e9+7;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  long long w[5]={0,a,b,c,d};
  long long dp[5]={0,INF,INF,INF,INF};
  long long ans[5]={1,0,0,0,0};
  for(int i=1; i<=n; i++){
    long long x; cin>>x;
    for(int j=4; j>=1; j--){
      if(dp[j-1]!=INF){
        long long val=dp[j-1]+w[j]*x;
        if(val<dp[j]){
          dp[j]=val;
          ans[j]=ans[j-1];
        }
        else if(val==dp[j]){
          ans[j]=(ans[j]+ans[j-1])%mod;
        }
      }
    }
  }
  cout<<dp[4]<<" "<<ans[4];
  return 0;
}
