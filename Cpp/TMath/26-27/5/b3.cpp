#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<vector<int>> a(n+2,vector<int>(n+2));
  // cin>>a[0][0]
  // cin>>a[1][0]>>a[1][1]
  // cin>>a[2][0]>>a[2][1]>>a[2][2]
  // cin>>a[3][0]>>a[3][1]>>a[3][2]>>a[3][3]
  for (int i=1; i<=n; i++){
    int j=1;
    for (;j<=i; j++){
      cin>>a[i][j];
    }
  }
  // for (int i=1; i<=n; i++){
  //   for (int j=1; j<=i+1; j++){
  //     cout<<a[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  vector<vector<int>> dp(n+2,vector<int>(n+2));
  for (int i=1; i<=n; i++){
    for (int j=1; j<=i; j++){
      dp[i][j]=max({dp[i-1][j-1],dp[i-1][j]})+a[i][j];
    }
  }
  // long long ans=-1;
  cout<<*max_element(dp[n].begin()+1,dp[n].end());
  return 0;
}
