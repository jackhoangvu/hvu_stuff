#include <bits/stdc++.h>
using namespace std;
int n;long long MOD=1000000007,dp[3]={1,0,0};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  while (n--) {
    long long x;
    cin >> x;
    long long a=dp[0], b=dp[1], c=dp[2];
    if (x % 3 == 0){
      dp[0] = 2*a % MOD;
      dp[1] = 2*b % MOD;
      dp[2] = 2*c % MOD;
    }
    else if (x % 3 == 1){//0,0; 0;2; 0,+x
      dp[0] = (a+c) % MOD;
      dp[1] = (b+a) % MOD;
      dp[2] = (c+b) % MOD;
    }
    else{
      dp[0] = (a+b) % MOD;
      dp[1] = (b+c) % MOD;
      dp[2] = (c+a) % MOD;
    }
  }
  cout<<(dp[0]-1+MOD) % MOD;
  return 0;
}
