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
  vector<vector<int>> dp(m+2,vector<int>(n+2));
  int ans=-1;
  int vi=1,vj=1;
  for(int i=1; i<m; i++){
    for(int j=1; j<n; j++){
      int cur=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
      if(cur>ans||(cur==ans&&i+j<vi+vj)){
        ans=cur;
        vi=i;
        vj=j;
      }
    }
  }
  cout<<vi<<" "<<vj;
  return 0;
}
