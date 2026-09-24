#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<vector<int>> a(n+2,vector<int>(n+2,0));
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin>>a[i][j];
    }
  }
  int l=2*n+2;
  vector<vector<vector<long long>>> dp(l+5,vector<vector<long long>>(n+2,vector<long long>(n+2,LLONG_MIN)));
  dp[2][1][1]=a[1][1];
  for(int l=3; l<=2*n; l++){
    for(int x=1; x<=n; x++){
      int y=l-x;
      if(y<1||y>n) continue;
      for(int u=1; u<=n; u++){
        int v=l-u;
        if(v<1||v>n) continue;
        dp[l][x][u]=max({dp[l-1][x][u],dp[l-1][x][u-1],dp[l-1][x-1][u],dp[l-1][x-1][u-1]})+a[x][y]+(x!=u?a[u][v]:0);
      }
    }
  }
  cout<<dp[2*n][n][n];
  return 0;
}
