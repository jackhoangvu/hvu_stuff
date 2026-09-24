#include <bits/stdc++.h>

using namespace std;
const int MOD=1e9+7;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int sum=n*(n+1)/2;
  if(sum%2==1) {cout<<"0"<<"\n"; return 0;}
  int t=sum/2;
  vector<int> dp(t+1,0);
  dp[0]=1;
  for(int i=1; i<n; i++){
    for(int j=t; j>=i; j--){
      dp[j]=(dp[j]+dp[j-i])%MOD;
    }
  }
  cout<<dp[t];
  return 0;
}
