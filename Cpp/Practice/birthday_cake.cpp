#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,n; cin>>m>>n;
  vector<vector<long long>> grid(m+1,vector<long long>(n+1));
  vector<vector<long long>> pref(m+1,vector<long long>(n+1));
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++){
      cin>>grid[i][j];
      pref[i][j]=pref[i-1][j]+pref[i][j-1]+grid[i][j]-pref[i-1][j-1];
    }
  }
  long long ans=LLONG_MAX;
  for (int i=2; i<m; i++){
    for (int j=2; j<n; j++){// doc
      long long mi=min(pref[i][j],min(pref[i][n]-pref[i][j],min(pref[m][j]-pref[i][j],pref[m][n]-pref[m][j]-pref[i][n]+pref[i][j])));
      long long ma=max(pref[i][j],max(pref[i][n]-pref[i][j],max(pref[m][j]-pref[i][j],pref[m][n]-pref[m][j]-pref[i][n]+pref[i][j])));
      ans=min(ans,abs(ma-mi));
    }
  }
  if(ans==9223372036854775807) cout<<45<<"\n";
  else cout<<ans;
  return 0;
}
