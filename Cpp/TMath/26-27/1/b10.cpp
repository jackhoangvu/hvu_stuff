#include<bits/stdc++.h>
using namespace std;
const long long INF=1LL<<60;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long w1,w2;
  cin>>n>>w1>>w2;
  long long w[6]={0,w1,w2,1,w2,w1};
  long long dp[6]={0,-INF,-INF,-INF,-INF, -INF};
  for(int i=1; i<=n; i++){
    long long x; cin>>x;
    for(int j=5; j>=1; j--){
      if(dp[j-1]!=-INF){
        dp[j]=max(dp[j],dp[j-1]+w[j]*x);
      }
    }
  }
  cout<<dp[5];
  return 0;
}
