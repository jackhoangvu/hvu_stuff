#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n; cin>>m>>n;
  vector<vector<int>> a(m+2,vector<int>(n+2));
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++){
      cin>>a[i][j];
    }
  }
  vector<vector<int>> dp0(m+2,vector<int>(n+2)),dp1(m+2,vector<int>(n+2));
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++){
      if(a[i][j]) dp1[i][j]=min({dp1[i-1][j],dp1[i][j-1],dp1[i-1][j-1]})+1;
      else dp0[i][j]=min({dp0[i-1][j],dp0[i][j-1],dp0[i-1][j-1]})+1;
    }
  }
  int ans=-1;
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++){
      ans=max({ans,dp1[i][j],dp0[i][j]});
    }
  }
  cout<<ans;
  return 0;
}
